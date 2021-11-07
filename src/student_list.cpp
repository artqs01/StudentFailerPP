#include "student_list.hpp"

student_list& student_list::load_student_list()
{
	static student_list slist;

	std::fstream student_list_file;
	student_list_file.open("../test_data/students.txt",std::fstream::in);

	return slist;
}
