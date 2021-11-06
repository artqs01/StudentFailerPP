#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class student
{
    public:

        std::string get_first_name();
        std::string get_second_name();
		size_t get_student_id();
		size_t get_additional_questions_cnt();
        double get_average_rating();
        double get_test_rating();
        void set_test_rating();
        void add_points(double points);

    private:

        size_t m_student_id;
        std::string m_first_name;
        std::string m_second_name;
        double m_average_rating = 3.0;
        double m_test_rating = 0;
        size_t m_additional_questions_cnt = 0;

};

#endif
