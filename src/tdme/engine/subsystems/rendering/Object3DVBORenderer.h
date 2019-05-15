#pragma once

#if defined(_WIN32) && defined(_MSC_VER)
	#include <windows.h>
#endif

#include <string>
#include <unordered_map>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/model/fwd-tdme.h>
#include <tdme/engine/model/Color4.h>
#include <tdme/engine/subsystems/renderer/fwd-tdme.h>
#include <tdme/engine/subsystems/rendering/fwd-tdme.h>
#include <tdme/engine/subsystems/rendering/Object3DGroup.h>
#include <tdme/math/fwd-tdme.h>
#include <tdme/math/Matrix4x4Negative.h>
#include <tdme/os/threading/Condition.h>
#include <tdme/os/threading/Mutex.h>
#include <tdme/os/threading/Thread.h>
#include <tdme/utils/fwd-tdme.h>
#include <tdme/utils/ByteBuffer.h>
#include <tdme/utils/Console.h>
#include <tdme/utils/Pool.h>

using std::unordered_map;
using std::string;
using std::to_string;
using std::vector;

using tdme::engine::Engine;
using tdme::engine::model::Color4;
using tdme::engine::model::Material;
using tdme::engine::subsystems::rendering::BatchVBORendererPoints;
using tdme::engine::subsystems::rendering::BatchVBORendererTriangles;
using tdme::engine::subsystems::rendering::Object3DGroup;
using tdme::engine::subsystems::rendering::TransparentRenderFacesPool;
using tdme::engine::subsystems::rendering::TransparentRenderPointsPool;
using tdme::engine::subsystems::renderer::Renderer;
using tdme::math::Matrix4x4;
using tdme::math::Matrix4x4Negative;
using tdme::math::Vector3;
using tdme::os::threading::Condition;
using tdme::os::threading::Mutex;
using tdme::os::threading::Thread;
using tdme::utils::ByteBuffer;
using tdme::utils::Console;
using tdme::utils::Pool;

/** 
 * Rendering class
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::engine::subsystems::rendering::Object3DVBORenderer final {
	friend class Object3DGroupVBORenderer;
	friend class TransparentRenderFacesGroup;

private:
	static constexpr int32_t BATCHVBORENDERER_MAX { 256 };
	static constexpr int32_t INSTANCEDRENDERING_OBJECTS_MAX { 16384 };

	struct InstancedRenderFunctionStruct {
		string shader;
		uint32_t renderTypes;
		Camera* camera;
		Matrix4x4 cameraMatrix;
		int object3DGroupIdx;
		int faceEntityIdx;
		int faces;
		int faceIdx;
		bool isTextureCoordinatesAvailable;
		Material* material;
	};

	class RenderThread: public Thread {
	private:
		Object3DVBORenderer* object3DVBORenderer;
		int idx;
		Mutex* m;
		Condition* c;
		void* context;
		InstancedRenderFunctionStruct p;
		volatile unsigned int* finishedCount;
		vector<Object3D*> objectsNotRendered;
	public:
		RenderThread(Object3DVBORenderer* object3DVBORenderer, int idx, Mutex* m, Condition* c, void* context, volatile unsigned int* finishedCount): Thread("object3dvborenderer-renderthread"), object3DVBORenderer(object3DVBORenderer), idx(idx), m(m), c(c), context(context), finishedCount(finishedCount) {
			Console::println("RenderThread::" + string(__FUNCTION__) + "()[" + to_string(idx) + "]");
		}
		inline vector<Object3D*>& getObjectsNotRendered() {
			return objectsNotRendered;
		}
		inline void setParameters(InstancedRenderFunctionStruct& p) {
			this->p = p;
		}
		virtual void run() {
			Console::println("RenderThread::" + string(__FUNCTION__) + "()[" + to_string(idx) + "]: INIT");
			while (isStopRequested() == false) {
				m->lock();
				c->wait(*m);
				m->unlock();
				if (isStopRequested() == true) break;
				objectsNotRendered.clear();
				object3DVBORenderer->instancedRenderFunction(idx, context, p, objectsNotRendered);
				#if defined(_WIN32) && defined(_MSC_VER)
					InterlockedIncrement(finishedCount);
				#else
					__sync_add_and_fetch(finishedCount, 1);
				#endif
			}
			Console::println("RenderThread::" + string(__FUNCTION__) + "()[" + to_string(idx) + "]: DONE");
		}
	};

	Engine* engine {  };
	Renderer* renderer {  };
	vector<int32_t>* vboInstancedRenderingIds {  };
	vector<BatchVBORendererTriangles*> trianglesBatchVBORenderers {  };
	unordered_map<string, vector<Object3D*>> visibleObjectsByModels {  };
	vector<TransparentRenderFace*> groupTransparentRenderFaces {  };
	Object3DVBORenderer_TransparentRenderFacesGroupPool* transparentRenderFacesGroupPool {  };
	TransparentRenderFacesPool* transparentRenderFacesPool {  };
	unordered_map<string, TransparentRenderFacesGroup*> transparentRenderFacesGroups {  };
	TransparentRenderPointsPool* pseTransparentRenderPointsPool {  };
	BatchVBORendererPoints* psePointBatchVBORenderer {  };
	Matrix4x4Negative matrix4x4Negative {  };
	vector<Object3D*> objectsToRender;
	vector<Object3D*> objectsNotRendered;
	int threadCount;
	vector<ByteBuffer*> bbEffectColorMuls;
	vector<ByteBuffer*> bbEffectColorAdds;
	vector<ByteBuffer*> bbMvMatrices;
	vector<RenderThread*> threads;
	volatile unsigned int threadsFinishedCount;
	Condition condition;
	Mutex mutex;

	/** 
	 * Renders transparent faces
	 * TODO:	guess this should be optimized regarding GL commands
	 * skinned mesh is not supported when using GPU
	 * @param transparentRenderFaces transparent render faces
	 */
	void prepareTransparentFaces(const vector<TransparentRenderFace*>& transparentRenderFaces);

	/** 
	 * Render transparent faces groups
	 * @param context context
	 */
	void renderTransparentFacesGroups(void* context);

	/** 
	 * Release transparent faces groups
	 */
	void releaseTransparentFacesGroups();

	/** 
	 * Renders multiple objects of same type(with same model)
	 * @param objects objects of same type/ with same models
	 * @param collectTransparentFaces collect render faces
	 * @param renderTypes render types
	 */
	void renderObjectsOfSameType(const vector<Object3D*>& objects, bool collectTransparentFaces, int32_t renderTypes);

	/** 
	 * Renders multiple objects of same type(with same model) not using instancing
	 * @param objects objects of same type/ with same models
	 * @param collectTransparentFaces collect render faces
	 * @param renderTypes render types
	 */
	void renderObjectsOfSameTypeNonInstanced(const vector<Object3D*>& objects, bool collectTransparentFaces, int32_t renderTypes);

	/**
	 * Render thread function
	 * @param threadIdx thread idx
	 * @param context context
	 * @param parameters parameters
	 */
	void instancedRenderFunction(int threadIdx, void* context, InstancedRenderFunctionStruct& parameters, vector<Object3D*>& objectsNotRendered);

	/**
	 * Renders multiple objects of same type(with same model) using instancing
	 * @param objects objects of same type/ with same models
	 * @param collectTransparentFaces collect render faces
	 * @param renderTypes render types
	 */
	void renderObjectsOfSameTypeInstanced(const vector<Object3D*>& objects, bool collectTransparentFaces, int32_t renderTypes);

	/**
	 * Checks if a material could change when having multiple objects but same model
	 * @param object3DGroup object 3d group
	 * @param facesEntityIdx faces entity idx
	 * @param renderTypes render types
	 */
	inline bool checkMaterialChangable(Object3DGroup* object3DGroup, int32_t facesEntityIdx, int32_t renderTypes) {
		return object3DGroup->dynamicDiffuseTextureIdsByEntities[facesEntityIdx] != Object3DGroup::TEXTUREID_NONE;
	}

	/**
	 * Set ups a material for rendering
	 * @param context context
	 * @param object3DGroup object 3d group
	 * @param facesEntityIdx faces entity idx
	 * @param renderTypes render types
	 * @param updateOnly update only, means material has been set up already, only do changes
	 * @param materialKey material key
	 * @param currentMaterialKey current material key or empty
	 */
	void setupMaterial(void* context, Object3DGroup* object3DGroup, int32_t facesEntityIdx, int32_t renderTypes, bool updateOnly, string& materialKey, const string& currentMaterialKey = string());

	/** 
	 * Clear material for rendering
	 * @param context context
	 */
	void clearMaterial(void* context);

public:
	static constexpr int32_t RENDERTYPE_NORMALS { 1 };
	static constexpr int32_t RENDERTYPE_TEXTUREARRAYS { 2 };
	static constexpr int32_t RENDERTYPE_TEXTUREARRAYS_DIFFUSEMASKEDTRANSPARENCY { 4 };
	static constexpr int32_t RENDERTYPE_EFFECTCOLORS { 8 };
	static constexpr int32_t RENDERTYPE_MATERIALS { 16 };
	static constexpr int32_t RENDERTYPE_MATERIALS_DIFFUSEMASKEDTRANSPARENCY { 32 };
	static constexpr int32_t RENDERTYPE_TEXTURES { 64 };
	static constexpr int32_t RENDERTYPE_TEXTURES_DIFFUSEMASKEDTRANSPARENCY { 128 };
	static constexpr int32_t RENDERTYPE_LIGHTS { 256 };
	static constexpr int32_t RENDERTYPE_SHADOWMAPPING { 512 };
	static constexpr int32_t RENDERTYPE_ALL { 1023 };

	/**
	 * Init
	 */
	void initialize();

	/**
	 * Dispose
	 */
	void dispose();

	/**
	 * @return batch vbo renderer for triangles
	 */
	BatchVBORendererTriangles* acquireTrianglesBatchVBORenderer();

	/**
	 * Resets the object 3d vbo renderer
	 */
	void reset();

	/**
	 * Renders all given objects
	 * @param objects objects
	 * @param renderTransparentFaces render transparent faces
	 * @param renderTypes render types
	 */
	void render(const vector<Object3D*>& objects, bool renderTransparentFaces, int32_t renderTypes);

	/** 
	 * Render batch VBO renderer points entities
	 * @param visiblePses points batch VBO renderer points
	 */
	void render(const vector<PointsParticleSystem*>& visiblePses);

	/**
	 * Public constructor
	 * @param engine engine
	 * @param renderer renderer
	 */
	Object3DVBORenderer(Engine* engine, Renderer* renderer);

	/**
	 * Destructor
	 */
	~Object3DVBORenderer();
};
