#include <cstdlib>
#include <string>

#include <tdme/tdme.h>
#include <tdme/application/Application.h>
#include <tdme/engine/Engine.h>
#include <tdme/engine/Version.h>
#include <tdme/os/filesystem/FileSystem.h>
#include <tdme/os/filesystem/FileSystemInterface.h>
#include <tdme/utilities/Console.h>
#include <tdme/utilities/Exception.h>

using tdme::application::Application;
using tdme::engine::Engine;
using tdme::engine::Version;
using tdme::os::filesystem::FileSystem;
using tdme::os::filesystem::FileSystemInterface;
using tdme::utilities::Console;
using tdme::utilities::Exception;
using tdme::utilities::StringTools;

namespace tdme {
namespace tools {
namespace cli {

/**
 * Delete VK cache
 * @author andreas.drewke
 * @version $Id$
 */
class DeleteVKCacheApplication final
	: public virtual Application
{
public:
	/**
	 * Public constructor
	 */
	DeleteVKCacheApplication() {
	}

	/**
	 * Public denstructor
	 */
	~DeleteVKCacheApplication() {
	}

	/**
	 * Main
	 * @param argc argument count
	 * @param argv argument values
	 */
	inline static void main(int argc, char** argv) {
		auto convertToTMApplication = new DeleteVKCacheApplication();
		convertToTMApplication->run(argc, argv, "Delete VK cache Application", nullptr, Application::WINDOW_HINT_INVISIBLE);
	}

	// overriden methods
	void display() override {
		Application::exit(0);
	}

	void dispose() override {
		Engine::getInstance()->dispose();
	}

	void initialize() override {
		Engine::getInstance()->initialize();
	}

	void reshape(int32_t width, int32_t height) override {
		Engine::getInstance()->reshape(width, height);
	}
};

};
};
};

int main(int argc, char** argv)
{
	Console::println(string("deletevkcache ") + Version::getVersion());
	Console::println(Version::getCopyright());
	Console::println();
	Console::println("Deleting shader/vk folder");
	try {
		FileSystem::getInstance()->removePath("shader/vk", true);
	} catch (Exception& exception) {
		Console::println(string() + "An error occurred: " + exception.what());
	}
	try {
		if (FileSystem::getInstance()->fileExists("shader/vk") == false) {
			FileSystem::getInstance()->createPath("shader/vk");
		}
	} catch (Exception& exception) {
		Console::println(string() + "An error occurred: " + exception.what());
	}
	Console::println("Creating shader/vk shader cache");
	tdme::tools::cli::DeleteVKCacheApplication::main(argc, argv);
	Console::println("Done");
}
