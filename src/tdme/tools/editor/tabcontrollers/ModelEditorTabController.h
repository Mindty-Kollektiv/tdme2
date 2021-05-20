#pragma once

#include <array>
#include <map>
#include <string>
#include <vector>

#include <tdme/tdme.h>
#include <tdme/engine/model/fwd-tdme.h>
#include <tdme/engine/prototype/fwd-tdme.h>
#include <tdme/engine/ShaderParameter.h>
#include <tdme/gui/events/fwd-tdme.h>
#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/events/GUIChangeListener.h>
#include <tdme/gui/nodes/fwd-tdme.h>
#include <tdme/math/fwd-tdme.h>
#include <tdme/tools/editor/misc/FileDialogPath.h>
#include <tdme/tools/editor/tabcontrollers/subcontrollers/fwd-tdme.h>
#include <tdme/tools/editor/tabcontrollers/TabController.h>
#include <tdme/tools/editor/tabviews/fwd-tdme.h>
#include <tdme/utilities/fwd-tdme.h>

using std::array;
using std::map;
using std::string;
using std::vector;

using tdme::engine::model::Material;
using tdme::engine::model::Node;
using tdme::engine::prototype::Prototype;
using tdme::engine::prototype::PrototypeLODLevel;
using tdme::engine::ShaderParameter;
using tdme::gui::events::GUIActionListener;
using tdme::gui::events::GUIActionListenerType;
using tdme::gui::events::GUIChangeListener;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUIParentNode;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::nodes::GUITextNode;
using tdme::math::Vector3;
using tdme::tools::editor::misc::FileDialogPath;
using tdme::tools::editor::tabcontrollers::subcontrollers::PrototypeBaseSubController;
using tdme::tools::editor::tabcontrollers::subcontrollers::PrototypeDisplaySubController;
using tdme::tools::editor::tabcontrollers::subcontrollers::PrototypePhysicsSubController;
using tdme::tools::editor::tabcontrollers::subcontrollers::PrototypeSoundsSubController;
using tdme::tools::editor::tabcontrollers::TabController;
using tdme::tools::editor::tabviews::ModelEditorTabView;
using tdme::utilities::MutableString;

/**
 * Model editor screen controller
 * @author Andreas Drewke
 * @version $Id$
 */
class tdme::tools::editor::tabcontrollers::ModelEditorTabController final
	: public TabController
{

private:
	PrototypeBaseSubController* prototypeBaseSubController { nullptr };
	PrototypeDisplaySubController* prototypeDisplaySubController { nullptr };
	PrototypePhysicsSubController* prototypePhysicsSubController { nullptr };
	PrototypeSoundsSubController* prototypeSoundsSubController { nullptr };
	ModelEditorTabView* view { nullptr };
	GUIScreenNode* screenNode { nullptr };

	FileDialogPath modelPath;
	FileDialogPath audioPath;

	array<string, 5> applyAnimationNodes = {
		"animation_startframe",
		"animation_endframe",
		"animation_speed",
		"animation_loop",
		"animation_overlaybone"
	};

	array<string, 3> applySpecularMaterialNodes = {
		"specularmaterial_shininess",
		"specularmaterial_reflection",
		"specularmaterial_maskedtransparency"
	};

	array<string, 5> applyPBRMaterialNodes = {
		"pbrmaterial_metallic_factor",
		"pbrmaterial_roughness_factor",
		"pbrmaterial_normal_scale",
		"pbrmaterial_exposure",
		"pbrmaterial_maskedtransparency"
	};

	array<string, 4> applyAnimationPreviewNodes = {
		"animationpreview_base",
		"animationpreview_overlay1",
		"animationpreview_overlay2",
		"animationpreview_overlay3"
	};

	/**
	 * @return prototype lod level or nullptr
	 */
	PrototypeLODLevel* getLODLevel(int level);

	/**
	 * @return current selected material
	 */
	Material* getSelectedMaterial();

	/**
	 * Create outliner model nodes xml
	 */
	void createOutlinerModelNodesXML(const map<string, Node*>& subNodes, string& xml);

public:
	/**
	 * Public constructor
	 * @param view view
	 */
	ModelEditorTabController(ModelEditorTabView* view);

	/**
	 * Destructor
	 */
	virtual ~ModelEditorTabController();

	/**
	 * Get view
	 */
	ModelEditorTabView* getView();

	/**
	 * @return prototype display sub screen controller
	 */
	PrototypeDisplaySubController* getPrototypeDisplaySubController();

	/**
	 * @return prototype bounding volume sub screen controller
	 */
	PrototypePhysicsSubController* getPrototypePhysicsSubController();

	/**
	 * @return prototype sounds sub screen controller
	 */
	PrototypeSoundsSubController* getPrototypeSoundsSubController();

	// overridden method
	GUIScreenNode* getScreenNode() override;

	/**
	 * @return model path
	 */
	FileDialogPath* getModelPath();

	/**
	 * @return audio path
	 */
	FileDialogPath* getAudioPath();

	// overridden methods
	void initialize(GUIScreenNode* screenNode) override;
	void dispose() override;

	/**
	 * Set outliner content
	 */
	void setOutlinerContent();

	/**
	 * Set outliner add drop down content
	 */
	void setOutlinerAddDropDownContent();

	/**
	 * Set details content
	 */
	void setDetailsContent();

	/**
	 * Set lod level
	 * @param level lod level
	 */
	void setLODLevel(int level);

	/**
	 * @return current material
	 */
	Material* getCurrentMaterial();

	/**
	 * Set up model statistics
	 * @param statsOpaqueFaces stats opaque faces
	 * @param statsTransparentFaces stats transparent faces
	 * @param statsMaterialCount stats material count
	 */
	void setStatistics(int statsOpaqueFaces, int statsTransparentFaces, int statsMaterialCount);

	/**
	 * Unset statistics
	 */
	void unsetStatistics();

	/**
	 * On model load
	 */
	void onModelLoad();

	/**
	 * On model save
	 */
	void onModelSave();

	/**
	 * On model reload
	 */
	void onModelReload();

	/**
	 * On model reload
	 */
	void onModelReimport();

	/**
	 * On tools compute normals
	 */
	void onToolsComputeNormal();

	/**
	 * On tools optimize model
	 */
	void onToolsOptimizeModel();

	/**
	 * Save file
	 * @param pathName path name
	 * @param fileName file name
	 */
	void saveFile(const string& pathName, const string& fileName);

	/**
	 * Load file
	 * @param pathName path name
	 * @param fileName file name
	 */
	void loadFile(const string& pathName, const string& fileName);

	/**
	 * Set material details
	 */
	void setMaterialDetails();

	/**
	 * Update material details
	 */
	void updateMaterialDetails();

	/**
	 * Update material color details
	 */
	void updateMaterialColorDetails();

	/**
	 * Apply specular material details
	 */
	void applySpecularMaterialDetails();

	/**
	 * Apply PBR material details
	 */
	void applyPBRMaterialDetails();

	/**
	 * Set animation details
	 * @param animationId animation Id
	 */
	void setAnimationDetails(const string& animationId);

	/**
	 * Apply animation details
	 * @param animationId animation id
	 */
	void applyAnimationDetails(const string& animationId);

	/**
	 * Set animation preview details
	 */
	void setAnimationPreviewDetails();

	/**
	 * Apply animation preview details
	 */
	void applyAnimationPreviewDetails();

	/**
	 * Set sound details
	 * @param soundId sound Id
	 */
	void setSoundDetails(const string& soundId);

	/**
	 * Update details panel
	 * @param outlinerNode outliner node
	 */
	void updateDetails(const string& outlinerNode);

	/**
	 * On material load diffuse texture
	 */
	void onMaterialLoadDiffuseTexture();

	/**
	 * On material clear diffuse texture
	 */
	void onMaterialClearDiffuseTexture();

	/**
	 * On material load diffuse transparency texture
	 */
	void onMaterialLoadDiffuseTransparencyTexture();

	/**
	 * On material clear diffuse transparency texture
	 */
	void onMaterialClearDiffuseTransparencyTexture();

	/**
	 * On material load normal texture
	 */
	void onMaterialLoadNormalTexture();

	/**
	 * On material clear normal texture
	 */
	void onMaterialClearNormalTexture();

	/**
	 * On material load specular texture
	 */
	void onMaterialLoadSpecularTexture();

	/**
	 * On material clear specular texture
	 */
	void onMaterialClearSpecularTexture();

	/**
	 * On material load PBR base color texture
	 */
	void onMaterialLoadPBRBaseColorTexture();

	/**
	 * On material clear PBR base color texture
	 */
	void onMaterialClearPBRBaseColorTexture();

	/**
	 * On material load PBR metallic roughness texture
	 */
	void onMaterialLoadPBRMetallicRoughnessTexture();

	/**
	 * On material clear PBR metallic roughness texture
	 */
	void onMaterialClearPBRMetallicRoughnessTexture();

	/**
	 * On material load PBR normal texture
	 */
	void onMaterialLoadPBRNormalTexture();

	/**
	 * On material load PBR normal texture
	 */
	void onMaterialClearPBRNormalTexture();

	/**
	 * On preview animations attachment 1 model load
	 */
	void onPreviewAnimationsAttachment1ModelLoad();

	/**
	 * On preview animations attachment 1 model clear
	 */
	void onPreviewAnimationsAttachment1ModelClear();

	// overridden methods
	void onValueChanged(GUIElementNode* node) override;
	void onActionPerformed(GUIActionListenerType type, GUIElementNode* node) override;
	void onFocus(GUIElementNode* node) override;
	void onUnfocus(GUIElementNode* node) override;

	/**
	 * Shows the error pop up
	 * @param caption caption
	 * @param message message
	 */
	void showErrorPopUp(const string& caption, const string& message);

	/**
	 * On quit
	 */
	void onQuit();

};
