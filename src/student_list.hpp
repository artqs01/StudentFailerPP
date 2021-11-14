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
		GET(get_name, m_name);
		GET(get_surname, m_surname);
		GET(get_average_rating, m_avreage_rating);
		GET(get_exam_rating, m_exam_rating);
		GET(get_additional_questions_cnt, m_additional_questions_cnt);
		student() = default;
		friend class student_list;
	private:
		size_t m_id;
		std::string m_name;
		std::string m_surname;
		double m_avreage_rating;
		double m_exam_rating = 0;
		size_t m_additional_questions_cnt;
};


class student_list
{
	public:
		void end_student_session(size_t student_id);
		void save_test_ratings();
		GET_CONTAINER_MEMBER(get_student, m_students, student_id);
		student_list();
	private:
		std::vector<student> m_students;
		std::vector<student> m_sudents_after_exam;
		void load_student_list();
		size_t evaluate_additional_questions_number(double avreage_rating);
};

#endif
