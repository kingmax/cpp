#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;



int main()
{
	fs::path cd = fs::current_path();
	cout << cd << endl;
	cout << cd.filename() << endl;
	cout << cd.root_name() << endl;
	cout << cd.root_directory() << endl;
	cout << cd.root_path() << endl;
	cout << cd.parent_path() << endl;
	
	
	return 0;
}