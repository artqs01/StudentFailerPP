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

	questions q;
	std::cout << q.get_topic(0).get_topic_name() << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << q.draw_question(0) << std::endl;
	}
	std::cout << std::endl;
	std::cout << q.get_topic(1).get_topic_name() << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << q.draw_question(1) << std::endl;
	}
	std::cout << std::endl;
	std::cout << q.get_topic(2).get_topic_name() << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << q.draw_question(2) << std::endl;
	}
	std::cout << std::endl;
	std::cout << q.get_topic(3).get_topic_name() << std::endl;
	for (int i = 0; i < 22; i++)
	{
		std::cout << q.draw_question(3) << std::endl;
	}
	std::cout << std::endl;
	q.reset_questions_base();
	std::cout << q.get_topic(0).get_topic_name() << std::endl;
	for (int i = 0; i < 12; i++)
	{
		std::cout << q.draw_question(0) << std::endl;
	}
	std::cout << std::endl;
}

// std::cout << "\n";
