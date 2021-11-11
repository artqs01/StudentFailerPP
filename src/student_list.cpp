#include "student_list.hpp"

#include <json.hpp>
#include <fstream>

student_list::student_list()
{
	std::ifstream student_list_file;
	student_list_file.open(std::string{"../exam_data/student_list.txt"});

	if (student_list_file.is_open())
	{
		while (!student_list_file.eof())
		{
			
		}
	}
	else
		throw std::runtime_error{"Could not open the file!"};
}
