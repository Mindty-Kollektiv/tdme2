#pragma once

#include <string>
#include <unordered_map>

#include <tdme/tdme.h>
#include <tdme/gui/elements/fwd-tdme.h>
#include <tdme/gui/elements/GUIElement.h>
#include <tdme/gui/nodes/fwd-tdme.h>
#include <tdme/os/filesystem/FileSystemException.h>
#include <tdme/utilities/fwd-tdme.h>

using std::string;
using std::unordered_map;

using tdme::gui::elements::GUIElement;
using tdme::gui::nodes::GUINode;
using tdme::gui::nodes::GUINodeController;
using tdme::gui::nodes::GUIScreenNode;
using tdme::os::filesystem::FileSystemException;

/**
 * GUI menu header item element
 * @author Andreas Drewke
 */
class tdme::gui::elements::GUIMenuHeaderItem final: public GUIElement
{

private:
	STATIC_DLL_IMPEXT static string NAME;

public:
	// forbid class copy
	CLASS_FORBID_COPY(GUIMenuHeaderItem)

	/**
	 * Public constructor
	 */
	GUIMenuHeaderItem();

	// overridden methods
	const string& getName() override;
	const string getTemplate(const string& applicationPathName, const string& applicationSubPathName, const string& fileName = string()) override;
	unordered_map<string, string> getAttributes(GUIScreenNode* screenNode) override;
	GUINodeController* createController(GUINode* node) override;

};
