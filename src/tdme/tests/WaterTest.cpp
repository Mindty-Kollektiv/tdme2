#include <tdme/tests/WaterTest.h>

#include <string>

#include <tdme/application/Application.h>
#include <tdme/engine/Camera.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/Light.h>
#include <tdme/engine/Object3D.h>
#include <tdme/engine/fileio/models/ModelReader.h>
#include <tdme/engine/model/Material.h>
#include <tdme/engine/model/Model.h>
#include <tdme/engine/model/SpecularMaterialProperties.h>
#include <tdme/math/Vector3.h>
#include <tdme/math/Vector4.h>
#include <tdme/math/Quaternion.h>
#include <tdme/tools/leveleditor/logic/Level.h>
#include <tdme/tools/shared/files/LevelFileImport.h>
#include <tdme/tools/shared/files/ModelMetaDataFileImport.h>
#include <tdme/tools/shared/model/LevelEditorEntity.h>
#include <tdme/tools/shared/model/LevelEditorLevel.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/ModelTools.h>
#include <tdme/utilities/ObjectDeleter.h>
#include <tdme/utilities/Time.h>

using std::string;
using std::to_string;

using tdme::tests::WaterTest;

using tdme::utilities::Time;

using tdme::engine::Camera;
using tdme::engine::Engine;
using tdme::engine::Light;
using tdme::engine::Object3D;
using tdme::engine::fileio::models::ModelReader;
using tdme::engine::model::Material;
using tdme::engine::model::Model;
using tdme::engine::model::SpecularMaterialProperties;
using tdme::math::Vector3;
using tdme::math::Vector4;
using tdme::math::Quaternion;
using tdme::tools::leveleditor::logic::Level;
using tdme::tools::shared::files::LevelFileImport;
using tdme::tools::shared::files::ModelMetaDataFileImport;
using tdme::tools::shared::model::LevelEditorEntity;
using tdme::tools::shared::model::LevelEditorLevel;
using tdme::utilities::Console;
using tdme::utilities::ModelTools;
using tdme::utilities::ObjectDeleter;
using tdme::utilities::Time;

WaterTest::WaterTest()
{
	engine = Engine::getInstance();
}


void WaterTest::main(int argc, char** argv)
{
	auto waterTest = new WaterTest();
	waterTest->run(argc, argv, "WaterTest", waterTest);
}

void WaterTest::display()
{
	// animate sky dome
	{
		auto skyDome = static_cast<Object3D*>(engine->getEntity("sky_dome"));
		skyDome->setTextureMatrix((Matrix2D3x3()).identity().translate(Vector2(0.0f, skyDomeTranslation * 0.01f)));

		auto skyPanorama = engine->getEntity("sky_panorama");
		skyPanorama->setRotationAngle(0, skyDomeTranslation * 1.0f * 0.1f);
		skyPanorama->update();

		skyDomeTranslation+= 1.0f / 60.0;
	}

	if (keyLeft == true) rotationY-= 5.0f;
	if (keyRight == true) rotationY+= 5.0f;

	Quaternion rotationYQuaternion;
	rotationYQuaternion.rotate(Vector3(0.0f, 1.0f, 0.0f), rotationY);
	auto cam = engine->getCamera();
	cam->setLookFrom(Vector3(0.0f, 30.0f, 0.0f) + (rotationYQuaternion * Vector3(0.0f, 0.0f, -50.0f)));
	cam->setUpVector(cam->computeUpVector(cam->getLookFrom(), cam->getLookAt()));

	//
	auto start = Time::getCurrentMillis();
	engine->display();
	auto end = Time::getCurrentMillis();
	auto rendererStatistics = engine->getRendererStatistics();
	Console::println(
		string("WaterTest::display::") + to_string(end - start) + "ms; " +
		"clear calls: " + to_string(rendererStatistics.clearCalls) + ", " +
		"render calls: " + to_string(rendererStatistics.renderCalls) + ", " +
		"compute calls: " + to_string(rendererStatistics.computeCalls) + ", " +
		"tris: " + to_string(rendererStatistics.triangles) + ", " +
		"points: " + to_string(rendererStatistics.points) + ", " +
		"line points: " + to_string(rendererStatistics.linePoints) + ", " +
		"buffer up: " + to_string(rendererStatistics.bufferUploads) + ", " +
		"texture up: " + to_string(rendererStatistics.textureUploads) + ", " +
		"render passes: " + to_string(rendererStatistics.renderPasses) + ", " +
		"draw cmds: " + to_string(rendererStatistics.drawCommands) + ", " +
		"submits: " + to_string(rendererStatistics.submits)
	);
}

void WaterTest::dispose()
{
	engine->dispose();
}

void WaterTest::initialize()
{
	engine->initialize();

	LevelFileImport::doImport("resources/tests/levels/water", "Level_WaterShader3.tl", &level);
	Level::setLight(engine, &level);
	Level::addLevel(engine, &level, false, false, false);

	// load sky
	skySphereEntity = ModelMetaDataFileImport::doImport("resources/tests/levels/water", "Mesh_Environment_Sky_Sphere.fbx.tmm");
	skyDomeEntity = ModelMetaDataFileImport::doImport("resources/tests/levels/water", "Mesh_Environment_Sky_Dome.fbx.tmm");
	skyPanoramaEntity = ModelMetaDataFileImport::doImport("resources/tests/levels/water", "Mesh_Environment_Sky_Panorama.fbx.tmm");
	sphereEntity = ModelMetaDataFileImport::doImport("resources/tests/levels/water", "CM_Sphere.tmm");

	// add sky
	{
		// sky sphere
		auto skySphere = new Object3D("sky_sphere", skySphereEntity->getModel());
		skySphere->setShader("sky");
		skySphere->setFrustumCulling(false);
		skySphere->setTranslation(Vector3(0.0f, 0.0f, 0.0f));
		skySphere->setScale(Vector3(300.0f/200.0f, 300.0f/200.0f, 300.0f/200.0f));
		skySphere->update();
		skySphere->setContributesShadows(false);
		skySphere->setReceivesShadows(false);
		skySphere->setExcludeEffectPass(Engine::EFFECTPASS_LIGHTSCATTERING);
		engine->addEntity(skySphere);

		// sky dome
		auto skyDome = new Object3D("sky_dome", skyDomeEntity->getModel());
		skyDome->setShader("sky");
		skyDome->setFrustumCulling(false);
		skyDome->setTranslation(Vector3(0.0f, 0.0f, 0.0f));
		skyDome->setScale(Vector3(295.0f/190.0f, 295.0f/190.0f, 295.0f/190.0f));
		skyDome->getModel()->getMaterials().begin()->second->getSpecularMaterialProperties()->setDiffuseTextureMaskedTransparency(true);
		skyDome->update();
		skyDome->setContributesShadows(false);
		skyDome->setReceivesShadows(false);
		skyDome->setEffectColorMul(Color4(1.0f, 1.0f, 1.0f, 0.7f));
		skyDome->setExcludeEffectPass(Engine::EFFECTPASS_LIGHTSCATTERING);
		engine->addEntity(skyDome);

		// sky panorama
		auto skyPanorama = new Object3D("sky_panorama", skyPanoramaEntity->getModel());
		skyPanorama->setShader("sky");
		skyPanorama->setFrustumCulling(false);
		skyPanorama->setTranslation(Vector3(0.0f, 0.0f, 0.0f));
		skyPanorama->setScale(Vector3(280.0f/190.0f, 280.0f/180.0f, 280.0f/180.0f));
		skyPanorama->addRotation(Vector3(0.0f, 1.0f, 0.0f), 0.0f);
		skyPanorama->update();
		skyPanorama->setContributesShadows(false);
		skyPanorama->setReceivesShadows(false);
		skyPanorama->setExcludeEffectPass(Engine::EFFECTPASS_LIGHTSCATTERING);
		engine->addEntity(skyPanorama);
	}

	/*
	{
		// sphere
		auto sphere = new Object3D("sphere", sphereEntity->getModel());
		sphere->setShader("water");
		sphere->setScale(Vector3(5.0f, 5.0f, 5.0f));
		sphere->setTranslation(Vector3(0.0f, 10.0f, 0.0f));
		sphere->update();
		engine->addEntity(sphere);
	}
	*/

	//
	engine->getEntity("water")->setScale(Vector3(400.0f, 1.0f, 400.0f));
	engine->getEntity("water")->setTranslation(engine->getEntity("water")->getTranslation() + Vector3(0.0f, 2.0f, 0.0f));
	engine->getEntity("water")->update();

	Quaternion rotationYQuaternion;
	rotationYQuaternion.rotate(Vector3(0.0f, 1.0f, 0.0f), rotationY);

	auto cam = engine->getCamera();
	cam->setZNear(0.1f);
	cam->setZFar(150.0f);
	cam->setLookFrom(Vector3(0.0f, 30.0f, 50.0f));
	cam->setLookAt(Vector3(0.0f, 0.0f, 0.0f));
	cam->setUpVector(cam->computeUpVector(cam->getLookFrom(), cam->getLookAt()));
	auto light0 = engine->getLightAt(0);
	light0->setAmbient(Color4(0.75f, 0.75f, 0.75f, 1.0f));
	light0->setDiffuse(Color4(0.40f, 0.40f, 0.40f, 1.0f));
	light0->setSpecular(Color4(1.0f, 1.0f, 1.0f, 1.0f));
	light0->setPosition(Vector4(0.0f, 20000.0f, 0.0f, 1.0f));
	light0->setSpotDirection(Vector3(0.0f, 0.0f, 0.0f).sub(Vector3(light0->getPosition().getX(), light0->getPosition().getY(), light0->getPosition().getZ())));
	light0->setConstantAttenuation(0.5f);
	light0->setLinearAttenuation(0.0f);
	light0->setQuadraticAttenuation(0.0f);
	light0->setSpotExponent(0.0f);
	light0->setSpotCutOff(180.0f);
	light0->setEnabled(true);
}

void WaterTest::reshape(int32_t width, int32_t height)
{
	engine->reshape(width, height);
}

void WaterTest::onChar(unsigned int key, int x, int y) {
}

void WaterTest::onKeyDown (unsigned char key, int x, int y) {
}

void WaterTest::onKeyUp(unsigned char key, int x, int y) {
}

void WaterTest::onSpecialKeyDown (int key, int x, int y) {
	if (key == KEYBOARD_KEYCODE_LEFT) keyLeft = true;
	if (key == KEYBOARD_KEYCODE_RIGHT) keyRight = true;
}

void WaterTest::onSpecialKeyUp(int key, int x, int y) {
	if (key == KEYBOARD_KEYCODE_LEFT) keyLeft = false;
	if (key == KEYBOARD_KEYCODE_RIGHT) keyRight = false;
}

void WaterTest::onMouseDragged(int x, int y) {
}

void WaterTest::onMouseMoved(int x, int y) {
}

void WaterTest::onMouseButton(int button, int state, int x, int y) {
}

void WaterTest::onMouseWheel(int button, int direction, int x, int y) {
}
