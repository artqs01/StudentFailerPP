#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include "utils.hpp"

#include <string>
#include <vector>

class student
{
	public:
		void add_points(double points) { m_exam_rating += points; };
		GET(get_id, m_id);
		GET(get_first_name, m_name);
		GET(get_surname, m_surname);
		GET(get_average_rating, m_average_rating);
		GET(get_exam_rating, m_exam_rating);
		GET(get_additional_questions_cnt, m_additional_questions_cnt);
		student() = default;
		friend class student_list;
	private:
		size_t m_id;
		std::string m_name;
		std::string m_surname;
		double m_average_rating;
		double m_exam_rating = 0;
		size_t m_additional_questions_cnt;
};


class student_list
{
	public:
		student_list();
		void save_test_ratings();
	private:
		std::vector<student> students;
		std::vector<student> sudents_after_exam;
};

#endif
