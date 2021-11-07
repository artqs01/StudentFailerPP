#include <iostream>

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main()
{
	std::fstream f;
	f.open("../test_data/basic1.txt",std::fstream::in);
	std::string s;
	if (f.is_open())
	{		
		getline(f, s);
	}
	std::cout << s;
}