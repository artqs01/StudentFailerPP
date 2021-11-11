#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include <string>
#include <vector>

using json = nlohmann::json;

// class student
// {
//     public:

//         std::string get_first_name() { return m_first_name; };
//         std::string get_second_name() { return m_second_name; };
// 		size_t get_id() { return m_id; };
// 		size_t get_additional_questions_cnt() { return m_additional_questions_cnt; };
//         double get_average_rating() { return m_average_rating; };
//         double get_test_rating() { return m_exam_rating; };

//         void load_student_data(std::string data);
//         void add_points(double points) { m_exam_rating += points; };

//     private:

//         size_t m_id;
//         std::string m_first_name;
//         std::string m_second_name;
//         double m_average_rating;
//         double m_exam_rating = 0;
//         size_t m_additional_questions_cnt;

// };


class student_list
{
    public:
        student_list();
		void save_test_ratings();

    private:

		std::vector<json> m_students;
		std::vector<json> m_students_after_exam;

};

#endif
