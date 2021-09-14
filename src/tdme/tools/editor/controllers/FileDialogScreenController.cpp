#include <tdme/tools/editor/controllers/FileDialogScreenController.h>

#include <algorithm>
#include <string>
#include <vector>

#include <tdme/gui/events/GUIActionListener.h>
#include <tdme/gui/events/GUIChangeListener.h>
#include <tdme/gui/nodes/GUIElementNode.h>
#include <tdme/gui/nodes/GUINode.h>
#include <tdme/gui/nodes/GUINodeController.h>
#include <tdme/gui/nodes/GUIParentNode.h>
#include <tdme/gui/nodes/GUIScreenNode.h>
#include <tdme/gui/nodes/GUITextNode.h>
#include <tdme/gui/GUI.h>
#include <tdme/gui/GUIParser.h>
#include <tdme/os/filesystem/FileNameFilter.h>
#include <tdme/os/filesystem/FileSystem.h>
#include <tdme/os/filesystem/FileSystemInterface.h>
#include <tdme/utilities/Action.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>
#include <tdme/utilities/MutableString.h>
#include <tdme/utilities/StringTools.h>

using std::remove;
using std::string;
using std::vector;

using tdme::gui::events::GUIActionListenerType;
using tdme::gui::nodes::GUIElementNode;
using tdme::gui::nodes::GUINode;
using tdme::gui::nodes::GUINodeController;
using tdme::gui::nodes::GUIParentNode;
using tdme::gui::nodes::GUIScreenNode;
using tdme::gui::nodes::GUITextNode;
using tdme::gui::GUIParser;
using tdme::os::filesystem::FileNameFilter;
using tdme::os::filesystem::FileSystem;
using tdme::os::filesystem::FileSystemInterface;
using tdme::tools::editor::controllers::FileDialogScreenController;
using tdme::utilities::Action;
using tdme::utilities::Console;
using tdme::utilities::Exception;
using tdme::utilities::MutableString;
using tdme::utilities::StringTools;

FileDialogScreenController::FileDialogScreenController()
{
	this->cwd = FileSystem::getStandardFileSystem()->getCurrentWorkingPathName();
	this->applyAction = nullptr;
	this->enableFilter = false;
	this->filtered = false;
}

FileDialogScreenController::~FileDialogScreenController() {
	if (applyAction != nullptr) delete applyAction;
	if (cancelAction != nullptr) delete cancelAction;
}

GUIScreenNode* FileDialogScreenController::getScreenNode()
{
	return screenNode;
}

const string& FileDialogScreenController::getPathName()
{
	return cwd;
}

const string FileDialogScreenController::getFileName()
{
	return fileNameNode->getController()->getValue().getString();
}

void FileDialogScreenController::initialize()
{
	try {
		screenNode = GUIParser::parse("resources/engine/gui", "popup_filedialog.xml");
		screenNode->setVisible(false);
		screenNode->addActionListener(this);
		screenNode->addChangeListener(this);
		screenNode->addFocusListener(this);
		tabsHeaderNode = required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("filedialog_tabs-header"));
		pathNode = required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("filedialog_path"));
		filesNode = required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("filedialog_files"));
		favoritesNode = required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("filedialog_favorites"));
		recentNode = required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("filedialog_recent"));
		drivesNode = required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("filedialog_drives"));
		fileNameNode = required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("filedialog_filename"));
		typeDropDownNode = required_dynamic_cast<GUIElementNode*>(screenNode->getNodeById("filedialog_typedropdown"));
	} catch (Exception& exception) {
		Console::print(string("FileDialogScreenController::initialize(): An error occurred: "));
		Console::println(string(exception.what()));
	}
}

void FileDialogScreenController::dispose()
{
	screenNode = nullptr;
}

bool FileDialogScreenController::setupFiles()
{
	class ExtensionFilter: public virtual FileNameFilter
	{
	public:
		bool accept(const string& pathName, const string& fileName) override {
			if (FileSystem::getStandardFileSystem()->isPath(pathName + "/" + fileName) == true) return true;
			if (extension.empty() == false) {
				if (StringTools::endsWith(StringTools::toLowerCase(fileName), "." + extension) == true) return true;
			} else {
				for (auto& extension : fileDialogScreenController->extensions) {
					if (StringTools::endsWith(StringTools::toLowerCase(fileName), "." + extension) == true) return true;
				}
			}
			return false;
		}

		/**
		 * Public constructor
		 * @param fileDialogScreenController file dialog screen controller
		 */
		ExtensionFilter(FileDialogScreenController* fileDialogScreenController, const string& extension): fileDialogScreenController(fileDialogScreenController), extension(extension) {
		}

	private:
		FileDialogScreenController* fileDialogScreenController;
		string extension;
	};

	//
	required_dynamic_cast<GUIParentNode*>(screenNode->getInnerNodeById(tabsHeaderNode->getId()))->replaceSubNodes("<tab id=\"filedialog_caption\" image=\"resources/engine/images/attention.png\" text=\"" + GUIParser::escapeQuotes(captionText)+ "\" closeable=\"true\"/>", true);
	pathNode->getController()->setValue(MutableString(cwd));

	//
	fileList.clear();
	auto success = true;
	try {
		auto directory = cwd;
		ExtensionFilter extensionsFilter(this, typeDropDownNode->getController()->getValue().getString());
		FileSystem::getStandardFileSystem()->list(directory, fileList, &extensionsFilter);
	} catch (Exception& exception) {
		Console::print(string("FileDialogScreenController::setupFileDialogListBox(): An error occurred: "));
		Console::println(string(exception.what()));
		success = false;
	}
	setupFiles(fileList);
	if (enableFilter == true) fileNameNode->getController()->setValue(MutableString("Type a string to filter the list..."));

	//
	filtered = false;

	//
	return success;
}

void FileDialogScreenController::setupFiles(const vector<string>& fileNameList, const string& selectedFileName) {
	auto filesInnerNode = required_dynamic_cast<GUIParentNode*>(filesNode->getScreenNode()->getInnerNodeById(filesNode->getId()));
	auto idx = 1;
	string filesInnerNodeSubNodesXML;
	filesInnerNodeSubNodesXML+=
		"<scrollarea width=\"100%\" height=\"100%\" background-color=\"{$color.element_midground}\">\n";
	for (auto& fileName : fileNameList) {
		auto fileImageName = getFileImageName(fileName);
		try {
			if (FileSystem::getStandardFileSystem()->isPath(cwd + "/" + fileName) == true) fileImageName = "folder";
		} catch (Exception& exception) {
			Console::print(string("FileDialogScreenController::setupFileDialogListBox(): An error occurred: "));
			Console::println(string(exception.what()));
		}
		filesInnerNodeSubNodesXML+=
			"<selectbox-option text=\"" +
			GUIParser::escapeQuotes(fileName) +
			"\" value=\"" +
			GUIParser::escapeQuotes(fileName) +
			"\"" +
			(selectedFileName == fileName?" selected=\"true\"":"") + " " +
			"image=\"{$icon.type_" + fileImageName + "}\" " +
			"/>\n";
	}
	filesInnerNodeSubNodesXML+= "</scrollarea>\n";
	try {
		filesInnerNode->replaceSubNodes(filesInnerNodeSubNodesXML, false);
	} catch (Exception& exception) {
		Console::print(string("FileDialogScreenController::setupFileDialogListBox(): An error occurred: "));
		Console::println(string(exception.what()));
	}
}

void FileDialogScreenController::setupFavorites() {
	auto favoritesInnerNode = required_dynamic_cast<GUIParentNode*>(favoritesNode->getScreenNode()->getInnerNodeById(favoritesNode->getId()));
	auto idx = 1;
	string favoritesInnerNodeSubNodesXML;
	favoritesInnerNodeSubNodesXML+=
		"<scrollarea width=\"100%\" height=\"100%\" background-color=\"{$color.element_midground}\">\n";
	for (auto& favorite: favorites) {
		auto fileImageName = "folder";
		favoritesInnerNodeSubNodesXML+=
			"<selectbox-option text=\"" +
			GUIParser::escapeQuotes(FileSystem::getStandardFileSystem()->getFileName(StringTools::endsWith(favorite, "/") == true?StringTools::substring(favorite, 0, favorite.size() - 1):favorite)) +
			"\" value=\"" +
			GUIParser::escapeQuotes(favorite) +
			"\" " +
			"image=\"{$icon.type_folder}\" " +
			"/>\n";
	}
	favoritesInnerNodeSubNodesXML+= "</scrollarea>\n";
	try {
		favoritesInnerNode->replaceSubNodes(favoritesInnerNodeSubNodesXML, false);
	} catch (Exception& exception) {
		Console::print(string("FileDialogScreenController::setupFavorites(): An error occurred: "));
		Console::println(string(exception.what()));
	}
}

void FileDialogScreenController::setupRecent() {
	auto recentsInnerNode = required_dynamic_cast<GUIParentNode*>(recentNode->getScreenNode()->getInnerNodeById(recentNode->getId()));
	auto idx = 1;
	string recentsInnerNodeSubNodesXML;
	recentsInnerNodeSubNodesXML+=
		"<scrollarea width=\"100%\" height=\"100%\" background-color=\"{$color.element_midground}\">\n";
	for (auto& recent: recents) {
		auto fileImageName = getFileImageName(recent);
		recentsInnerNodeSubNodesXML+=
			"<selectbox-option text=\"" +
			GUIParser::escapeQuotes(FileSystem::getStandardFileSystem()->getFileName(recent)) +
			"\" value=\"" +
			GUIParser::escapeQuotes(recent) +
			"\" " +
			"image=\"{$icon.type_" + fileImageName + "}\" " +
			"/>\n";
	}
	recentsInnerNodeSubNodesXML+= "</scrollarea>\n";
	try {
		recentsInnerNode->replaceSubNodes(recentsInnerNodeSubNodesXML, false);
	} catch (Exception& exception) {
		Console::print(string("FileDialogScreenController::setupRecent(): An error occurred: "));
		Console::println(string(exception.what()));
	}
}

void FileDialogScreenController::setupDrives() {
	vector<string> drives;
	#if defined(_WIN32)
		for (char drive = 'A'; drive <= 'Z'; drive++) {
			string fileName;
			fileName+= drive;
			fileName+= ":";
			try {
				if (FileSystem::getStandardFileSystem()->fileExists(fileName + "/") == true) drives.push_back(fileName);
			} catch (Exception& exception) {
				Console::println("FileDialogScreenController::setupDrives(): " + exception.what());
			}
		}
	#else
		drives.push_back("/");
	#endif
	auto drivesInnerNode = required_dynamic_cast<GUIParentNode*>(drivesNode->getScreenNode()->getInnerNodeById(drivesNode->getId()));
	auto idx = 1;
	string drivesInnerNodeSubNodesXML;
	drivesInnerNodeSubNodesXML+=
		"<scrollarea width=\"100%\" height=\"100%\" background-color=\"{$color.element_midground}\">\n";
	for (auto& drive: drives) {
		drivesInnerNodeSubNodesXML+=
			"<selectbox-option text=\"" +
			GUIParser::escapeQuotes(drive) +
			"\" value=\"" +
			GUIParser::escapeQuotes(drive) +
			"\" " +
			"image=\"{$icon.type_drive}\" " +
			"/>\n";
	}
	drivesInnerNodeSubNodesXML+= "</scrollarea>\n";
	try {
		drivesInnerNode->replaceSubNodes(drivesInnerNodeSubNodesXML, false);
	} catch (Exception& exception) {
		Console::print(string("FileDialogScreenController::setupDrives(): An error occurred: "));
		Console::println(string(exception.what()));
	}
}

void FileDialogScreenController::show(const string& cwd, const string& captionText, const vector<string>& extensions, const string& fileName, bool enableFilter, Action* applyAction, Action* cancelAction)
{
	try {
		this->cwd = FileSystem::getStandardFileSystem()->getCanonicalPath(cwd, "");
		if (FileSystem::getStandardFileSystem()->isPath(this->cwd) == false) {
			this->cwd = FileSystem::getStandardFileSystem()->getCurrentWorkingPathName();
		}
	} catch (Exception& exception) {
		Console::print(string("FileDialogScreenController::show(): An error occurred: "));
		Console::print(string(exception.what()));
		Console::println(": using cwd!");
		this->cwd = FileSystem::getStandardFileSystem()->getCurrentWorkingPathName();
	}
	this->captionText = captionText;
	this->extensions = extensions;
	this->fileNameNode->getController()->setValue(fileName);
	this->enableFilter = enableFilter;
	setupFiles();
	screenNode->setVisible(true);
	if (this->applyAction != nullptr) delete this->applyAction;
	this->applyAction = applyAction;
	if (this->cancelAction != nullptr) delete this->cancelAction;
	this->cancelAction = cancelAction;
	{
		string extensionsDropDownOptionsXML = "<dropdown-option text=\"All supported extensions\" value=\"\" selected=\"true\"/>\n";
		for (auto& extension: extensions) {
			extensionsDropDownOptionsXML+= "<dropdown-option text=\"" + StringTools::toUpperCase(extension) + " Files\" value=\"" + StringTools::toLowerCase(extension) + "\" selected=\"false\" />\n";
		}
		required_dynamic_cast<GUIParentNode*>(screenNode->getInnerNodeById(typeDropDownNode->getId()))->replaceSubNodes(extensionsDropDownOptionsXML, true);
	}
	setupDrives();
	setupFavorites();
	setupRecent();
}

void FileDialogScreenController::close()
{
	screenNode->setVisible(false);
	if (applyAction != nullptr) delete applyAction;
	if (cancelAction != nullptr) delete cancelAction;
	applyAction = nullptr;
	cancelAction = nullptr;
}

void FileDialogScreenController::onValueChanged(GUIElementNode* node)
{
	if (node->getId() == typeDropDownNode->getId()) {
		setupFiles();
	} else
	if (node->getId() == filesNode->getId()) {
		try {
			auto selectedFile = node->getController()->getValue().getString();
			if (FileSystem::getStandardFileSystem()->isDrive(selectedFile) == true) {
				auto lastCwd = cwd;
				cwd = selectedFile;
				if (setupFiles() == false) {
					cwd = lastCwd;
					setupFiles();
				}
			} else
			if (FileSystem::getStandardFileSystem()->isPath(cwd + "/" + selectedFile) == true) {
				auto lastCwd = cwd;
				try {
					cwd = FileSystem::getStandardFileSystem()->getCanonicalPath(cwd, selectedFile);
				} catch (Exception& exception) {
					Console::print(string("FileDialogScreenController::onValueChanged(): An error occurred: "));
					Console::println(string(exception.what()));
				}
				if (setupFiles() == false) {
					cwd = lastCwd;
					setupFiles();
				}
			} else {
				if (filtered == true) {
					setupFiles(fileList, selectedFile);
					filtered = false;
				}
				fileNameNode->getController()->setValue(selectedFile);
			}
		} catch (Exception& exception) {
			Console::print(string("FileDialogScreenController::onValueChanged(): An error occurred: "));
			Console::println(string(exception.what()));
			fileNameNode->getController()->setValue(MutableString());
		}
	} else
	if (node->getId() == fileNameNode->getId()) {
		try {
			if (enableFilter == true) {
				auto filterString = StringTools::toLowerCase(node->getController()->getValue().getString());
				if (FileSystem::getStandardFileSystem()->fileExists(cwd + "/" + filterString) == true) {
					auto selectedFile = node->getController()->getValue().getString();
					setupFiles(fileList, selectedFile);
				} else {
					vector<string> fileListFiltered;
					for (auto file: fileList) {
						if (StringTools::toLowerCase(file).find(filterString) != -1) fileListFiltered.push_back(file);
					}
					setupFiles(fileListFiltered);
					filtered = true;
				}
			}
		} catch (Exception& exception) {
			Console::print(string("FileDialogScreenController::onValueChanged(): An error occurred: "));
			Console::println(string(exception.what()));
			fileNameNode->getController()->setValue(MutableString());
		}
	}
}

void FileDialogScreenController::onActionPerformed(GUIActionListenerType type, GUIElementNode* node)
{
	if (type == GUIActionListenerType::PERFORMED) {
		if (node->getId() == pathNode->getId()) {
			auto lastCwd = cwd;
			cwd = pathNode->getController()->getValue().getString();
			if (setupFiles() == false) {
				cwd = lastCwd;
				setupFiles();
			}
		} else
		if (node->getId() == "filedialog_apply") {
			auto recent = cwd + "/" + fileNameNode->getController()->getValue().getString();
			try {
				if (FileSystem::getStandardFileSystem()->isPath(recent) == false) {
					recents.erase(remove(recents.begin(), recents.end(), recent), recents.end());
					recents.push_back(recent);
				}
			} catch (Exception& exception) {
				// no op
			}
			if (applyAction != nullptr) {
				applyAction->performAction();
				delete applyAction;
				applyAction = nullptr;
			}
		} else
		if (node->getId() == "filedialog_abort" ||
			StringTools::startsWith(node->getId(), "filedialog_caption_close_") == true) { // TODO: a.drewke, check with DH
			if (cancelAction != nullptr) {
				cancelAction->performAction();
				delete cancelAction;
				cancelAction = nullptr;
			}
			close();
		} else
		if (node->getId() == "filedialog_favorites_add") {
			favorites.erase(remove(favorites.begin(), favorites.end(), cwd), favorites.end());
			favorites.push_back(cwd);
			setupFavorites();
		} else
		if (node->getId() == "filedialog_favorites_remove") {
			auto favorite = favoritesNode->getController()->getValue().getString();
			favorites.erase(remove(favorites.begin(), favorites.end(), favorite), favorites.end());
			setupFavorites();
		} else
		if (node == favoritesNode) {
			cwd = favoritesNode->getController()->getValue().getString();
			setupFiles();
		} else
		if (node == drivesNode) {
			cwd = drivesNode->getController()->getValue().getString();
			setupFiles();
		}
	}
}

void FileDialogScreenController::onFocus(GUIElementNode* node) {
	if (node->getId() == "filedialog_filename") {
		if (enableFilter == true) node->getController()->setValue(MutableString(""));
	}
}

void FileDialogScreenController::onUnfocus(GUIElementNode* node) {
}

const string FileDialogScreenController::getFileImageName(const string& fileName) {
	auto fileNameLowerCase = StringTools::toLowerCase(fileName);
	if (StringTools::endsWith(fileNameLowerCase, ".ogg") == true) {
		return "sound";
	} else
	// C++/C code
	if (StringTools::endsWith(fileNameLowerCase, ".h") == true) {
		return "script";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".cpp") == true) {
		return "script";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".c") == true) {
		return "script";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".fnt") == true) {
		return "font";
	} else
	// images
	if (StringTools::endsWith(fileNameLowerCase, ".ico") == true) {
		return "texture";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".icns") == true) {
		return "texture";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".png") == true) {
		return "texture";
	} else
	// models
	if (StringTools::endsWith(fileNameLowerCase, ".dae") == true) {
		return "mesh";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".fbx") == true) {
		return "mesh";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".glb") == true) {
		return "mesh";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".tm") == true) {
		return "mesh";
	} else
	// property files
	if (StringTools::endsWith(fileNameLowerCase, ".properties") == true) {
		return "script";
	} else
	// shader
	if (StringTools::endsWith(fileNameLowerCase, ".cl") == true) {
		return "script";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".frag") == true) {
		return "script";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".glsl") == true) {
		return "script";
	} else
	if (StringTools::endsWith(fileNameLowerCase, ".vert") == true) {
		return "script";
	} else
	// tdme empty
	if (StringTools::endsWith(fileNameLowerCase, ".tempty") == true) {
		return "prototype";
	} else
	// tdme trigger
	if (StringTools::endsWith(fileNameLowerCase, ".ttrigger") == true) {
		return "prototype";
	} else
	// tdme envmap
	if (StringTools::endsWith(fileNameLowerCase, ".tenvmap") == true) {
		return "prototype";
	} else
	// tdme model
	if (StringTools::endsWith(fileNameLowerCase, ".tmodel") == true) {
		return "prototype";
	} else
	// tdme scene
	if (StringTools::endsWith(fileNameLowerCase, ".tscene") == true) {
		return "scene";
	} else
	// tdme particle system
	if (StringTools::endsWith(fileNameLowerCase, ".tparticle") == true) {
		return "particle";
	} else
	// tdme terrain
	if (StringTools::endsWith(fileNameLowerCase, ".tterrain") == true) {
		return "terrain";
	} else
	// tdme script
	if (StringTools::endsWith(fileNameLowerCase, ".tscript") == true) {
		return "script";
	} else
	// xml
	if (StringTools::endsWith(fileNameLowerCase, ".xml") == true) {
		return "gui";
	} else
	// files without ending
	if (fileName.rfind(".") == string::npos ||
		(fileName.rfind("/") != string::npos &&
		fileName.rfind(".") < fileName.rfind("/"))) {
		return "script";
	}
	return string();
}
