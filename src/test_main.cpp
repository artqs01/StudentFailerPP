#include <iostream>

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "questions.hpp"

namespace fs = std::filesystem;

int main(int argc, char** argv)
{
	fs::current_path((fs::current_path()/
		fs::path(argv[0])).parent_path());
	std::cout << questions::get_questions().get();
}
