#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include "student.hpp"

#include <vector>
#include <fstream>

class student_list 
{
    public:

		static student_list& open_student_list();

		void save_test_ratings();

		student_list(const student_list&) = delete;
		student_list operator=(const student_list&) = delete;

    private:
		student_list();

		std::fstream m_student_list_file;
		std::vector<student> m_student_list;
		std::vector<student> m_tested_student_list;
};

#endif
