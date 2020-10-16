#pragma once

#include <string>

#include <tdme/tdme.h>
#include <tdme/gui/events/GUIInputEventHandler.h>
#include <tdme/audio/fwd-tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/math/fwd-tdme.h>
#include <tdme/math/Vector3.h>
#include <tdme/tools/shared/controller/fwd-tdme.h>
#include <tdme/tools/shared/model/fwd-tdme.h>
#include <tdme/tools/shared/views/View.h>
#include <tdme/tools/shared/views/PlayableSoundView.h>
#include <tdme/tools/shared/views/CameraRotationInputHandlerEventHandler.h>

using std::string;

using tdme::audio::Audio;
using tdme::engine::Engine;
using tdme::gui::events::GUIInputEventHandler;
using tdme::math::Vector3;
using tdme::tools::shared::controller::ModelEditorScreenController;
using tdme::tools::shared::model::LevelEditorEntity;
using tdme::tools::shared::views::CameraRotationInputHandler;
using tdme::tools::shared::views::CameraRotationInputHandlerEventHandler;
using tdme::tools::shared::views::EntityPhysicsView;
using tdme::tools::shared::views::EntityDisplayView;
using tdme::tools::shared::views::EntitySoundsView;
using tdme::tools::shared::views::PlayableSoundView;
using tdme::tools::shared::views::PopUps;
using tdme::tools::shared::views::View;

/**
 * TDME model editor view
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::tools::shared::views::SharedModelEditorView
	: public View
	, public PlayableSoundView
	, public GUIInputEventHandler
	, protected CameraRotationInputHandlerEventHandler
{
protected:
	Engine* engine { nullptr };
	Audio* audio { nullptr };

private:
	PopUps* popUps { nullptr };
	ModelEditorScreenController* modelEditorScreenController { nullptr };
	EntityDisplayView* entityDisplayView { nullptr };
	EntityPhysicsView* entityPhysicsView { nullptr };
	EntitySoundsView* entitySoundsView { nullptr };
	LevelEditorEntity* entity { nullptr };
	bool loadModelRequested;
	bool initModelRequested;
	bool initModelRequestedReset;
	string modelFile;
	int lodLevel;
	CameraRotationInputHandler* cameraRotationInputHandler { nullptr };
	int64_t audioStarted;
	int64_t audioOffset;
	Vector3 objectScale;

	/**
	 * Init model
	 */
	void initModel();

	/**
	 * Load settings
	 */
	void loadSettings();

	/**
	 * Store settings
	 */
	void storeSettings();

	/**
	 * Load a model
	 */
	void loadModel();

	/**
	 * Load model
	 * @param name name
	 * @param description description
	 * @param pathName path name
	 * @param fileName file name
	 * @param pivot pivot
	 * @return level editor entity
	 * @throws tdme::utilities::Exception
	 */
	virtual LevelEditorEntity* loadModel(const string& name, const string& description, const string& pathName, const string& fileName, const Vector3& pivot);

	/**
	 * On rotation event to be overloaded
	 */
	void onRotation() override;

	/**
	 * On scale event to be overloaded
	 */
	void onScale() override;

public:
	/**
	 * Public constructor
	 * @param popUps pop ups
	 */
	SharedModelEditorView(PopUps* popUps);

	/**
	 * Destructor
	 */
	~SharedModelEditorView();

	/**
	 * @return pop up views
	 */
	PopUps* getPopUpsViews();

	/**
	 * @return entity
	 */
	LevelEditorEntity* getEntity();

	/**
	 * Set entity
	 */
	void setEntity(LevelEditorEntity* entity);

	/**
	 * Reset entity
	 */
	void resetEntity();

	/**
	 * Reimport entity
	 */
	void reimportEntity();

	/**
	 * @return current model file name
	 */
	const string& getFileName();

	/**
	 * @return LOD level
	 */
	int getLodLevel() const;

	/**
	 * Set lod level to display
	 * @param lodLevel lod level
	 */
	void setLodLevel(int lodLevel);

	/**
	 * Issue file loading
	 * @param pathName path name
	 * @param fileName file name
	 */
	void loadFile(const string& pathName, const string& fileName);

	/**
	 * Issue reimport model file
	 * @param pathName path name
	 * @param fileName file name
	 */
	void reimportModel(const string& pathName, const string& fileName);

	/**
	 * Triggers saving a map
	 * @param pathName path name
	 * @param fileName file name
	 */
	void saveFile(const string& pathName, const string& fileName);

	/**
	 * Issue file reloading
	 */
	void reloadFile();

	/**
	 * Apply pivot
	 * @param x x
	 * @param y y
	 * @param z z
	 */
	void pivotApply(float x, float y, float z);

	/**
	 * Compute normals
	 */
	void computeNormals();

	/**
	 * Optimize model
	 */
	void optimizeModel();

	// overridden methods
	void handleInputEvents() override;

	/**
	 * Renders the scene
	 */
	void display() override;

	/**
	 * Init GUI elements
	 */
	void updateGUIElements();

	// overridden methods
	void initialize() override;
	void activate() override;
	void deactivate() override;
	void dispose() override;
	void playSound(const string& soundId) override;

	/**
	 * On init additional screens
	 */
	virtual void onInitAdditionalScreens();

	/**
	 * On load model
	 * @param oldEntity old entity
	 * @param entity entity
	 */
	virtual void onLoadModel(LevelEditorEntity* oldEntity, LevelEditorEntity* entity);

	/**
	 * On set entity data hook
	 */
	virtual void onSetEntityData();

	/**
	 * Play animation
	 */
	void playAnimation(const string& animationId);

	/**
	 * Update rendering options
	 */
	void updateRendering();

};
