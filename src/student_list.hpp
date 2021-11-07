#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include <vector>
#include <fstream>

class student
{
    public:

        std::string get_first_name() { return m_first_name; };
        std::string get_second_name() { return m_second_name; };
		size_t get_id() { return m_id; };
		size_t get_additional_questions_cnt() { return m_additional_questions_cnt; };
        double get_average_rating() { return m_average_rating; };
        double get_test_rating() { return m_exam_rating; };
        void add_points(double points) { m_exam_rating += points; };

    private:

        size_t m_id;
        std::string m_first_name;
        std::string m_second_name;
        double m_average_rating = 3.0;
        double m_exam_rating = 0;
        size_t m_additional_questions_cnt = 0;

};

class student_list 
{
    public:

		static student_list& load_student_list();

		void save_test_ratings();

		student_list(const student_list&) = delete;
		student_list operator=(const student_list&) = delete;

    private:

		std::fstream m_student_list_file;
		std::vector<student> m_student_list;
		std::vector<student> m_tested_student_list;

		student_list() = default;
};

#endif
