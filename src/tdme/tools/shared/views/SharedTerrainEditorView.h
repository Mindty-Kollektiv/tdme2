#pragma once

#include <map>

#include <tdme/tdme.h>
#include <tdme/engine/fwd-tdme.h>
#include <tdme/engine/model/fwd-tdme.h>
#include <tdme/engine/primitives/BoundingBox.h>
#include <tdme/engine/prototype/fwd-tdme.h>
#include <tdme/gui/events/GUIInputEventHandler.h>
#include <tdme/math/Vector3.h>
#include <tdme/tools/shared/controller/fwd-tdme.h>
#include <tdme/tools/shared/views/fwd-tdme.h>
#include <tdme/tools/shared/views/View.h>

using std::map;

using tdme::engine::model::Model;
using tdme::engine::primitives::BoundingBox;
using tdme::engine::prototype::Prototype;
using tdme::engine::Engine;
using tdme::gui::events::GUIInputEventHandler;
using tdme::math::Vector3;
using tdme::tools::shared::controller::TerrainEditorScreenController;
using tdme::tools::shared::views::CameraInputHandler;
using tdme::tools::shared::views::PopUps;
using tdme::tools::shared::views::View;

/**
 * Shared terrain editor View
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::tools::shared::views::SharedTerrainEditorView
	: public View
	, public GUIInputEventHandler
{
protected:
	Engine* engine { nullptr };

private:
	PopUps* popUps { nullptr };
	TerrainEditorScreenController* terrainEditorScreenController { nullptr };
	Prototype* prototype { nullptr };
	bool initModelRequested { false };
	bool initCameraRequested { true };
	CameraInputHandler* cameraInputHandler { nullptr };
	bool brushingEnabled { false };
	Vector3 brushCenterPosition;

	float skyDomeTranslation { 0.0f };

	Prototype* skySpherePrototype { nullptr };
	Prototype* skyDomePrototype { nullptr };
	Prototype* skyPanoramaPrototype { nullptr };
	Prototype* spherePrototype { nullptr };

	BoundingBox terrainBoundingBox;
	vector<Model*> terrainModels;

	struct Water {
		Vector3 waterReflectionEnvironmentMappingPosition;
		vector<Model*> waterModels;
	};
	map<int, Water> waters;

	/**
	 * Init entity
	 */
	void initModel();

	/**
	 * Init sky
	 */
	void initSky();

	/**
	 * Update sky
	 */
	void updateSky();

public:
	/**
	 * Public constructor
	 * @param popUps pop ups view
	 */
	SharedTerrainEditorView(PopUps* popUps);

	/**
	 * Destructor
	 */
	~SharedTerrainEditorView();

	/**
	 * @return pop up views
	 */
	PopUps* getPopUpsViews();

	/**
	 * @return prototype
	 */
	Prototype* getPrototype();

	/**
	 * Set prototype
	 * @param prototype prototype
	 */
	void setPrototype(Prototype* entity);

	/**
	 * Set terrain models
	 * @param terrainBoundingBox terrain bounding box
	 * @param terrainModels terrain models
	 */
	void setTerrain(BoundingBox& terrainBoundingBox, vector<Model*> terrainModels);

	/**
	 * Unset all water
	 */
	void unsetWater();

	/**
	 * Remove water
	 * @param waterIdx water index
	 */
	void removeWater(int waterIdx);

	/**
	 * Add water
	 * @param waterIdx water index
	 * @param waterModels water models
	 * @param waterReflectionEnvironmentMappingPosition water reflection environment mapping position
	 */
	void addWater(int waterIdx, vector<Model*> waterModels, const Vector3& waterReflectionEnvironmentMappingPosition);

	/**
	 * Init GUI elements
	 */
	void updateGUIElements();

	// overridden methods
	void handleInputEvents() override;
	void display() override;
	void initialize() override;
	void activate() override;
	void deactivate() override;
	void dispose() override;

	/**
	 * On set prototype data hook
	 */
	virtual void onSetPrototypeData();

	/**
	 * On init additional screens
	 */
	virtual void onInitAdditionalScreens();

	/**
	 * Load file
	 * @param pathName path name
	 * @param fileName file name
	 */
	void loadFile(const string& pathName, const string& fileName);

	/**
	 * Save file
	 * @param pathName path name
	 * @param fileName file name
	 */
	void saveFile(const string& pathName, const string& fileName);

};
