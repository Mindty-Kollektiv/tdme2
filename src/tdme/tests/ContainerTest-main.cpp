#include <string>
#include <vector>

#include <tdme/utilities/Console.h>

using std::vector;
using std::string;
using std::to_string;

using tdme::utilities::Console;

int main(int argc, char** argv)
{
	vector<int> v = { 1, 2, 3, 4, 5 };
	Console::println("v = { 1, 2, 3, 4, 5 }, capacity = " + to_string(v.capacity()));
	v.clear();
	Console::println("v.clear(), capacity = " + to_string(v.capacity()));
	v = { 1, 2, 3 };
	Console::println("v = { 1, 2, 3 }, capacity = " + to_string(v.capacity()));
    return 0;
}
