#include "student_list.hpp"

#include <json.hpp>
#include <fstream>

void student::load_student_data(std::string data)
{
	
}

student_list::student_list()
{
	std::ifstream student_list_file;
	student_list_file.open(std::string{"../exam_data/student_list.txt"});

	if (student_list_file.is_open())
	{
		std::string line;
		while (!student_list_file.eof())
		{
			getline(student_list_file, line);
			if (line != "")
			{
				student n_student;
				n_student.load_student_data(line);
			}
		}
	}
	else
		throw std::runtime_error{"Could not open the file!"};
}
