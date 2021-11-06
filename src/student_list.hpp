#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include "student.hpp"

#include <vector>

class student_list
{
    public:

        void open_student_list(std::fstream student_list_file);
		void save_test_ratings();

    private:

		static std::fstream m_student_list_file;
		std::vector<student> m_student_list;

};

#endif
