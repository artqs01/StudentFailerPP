#include <iostream>

#include <string>
#include <iostream>
#include <fstream>
#include <filesystem>

#include "questions.hpp"

namespace fs = std::filesystem;


int main(int argc, char** argv)
{
		fs::current_path((fs::current_path() /
			fs::path(argv[0])).parent_path());

		for (size_t i = 0; i < 12; ++i)
			std::cout << questions::get_questions().draw_question(0) << "\n";

		questions::get_questions().reset_questions_base();

		std::cout << "\n";

		for (size_t i = 0; i < 12; ++i)
			std::cout << questions::get_questions().draw_question(0) << "\n";

		std::cout << "\n";

		for (size_t i = 0; i < NUMBER_OF_TOPICS; ++i)
			std::cout << questions::get_questions().get_topic_name(i) << "\n";
}
