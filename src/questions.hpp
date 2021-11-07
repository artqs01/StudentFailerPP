#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include "student.hpp"

#include <vector>
#include <fstream>
#include <array>

#define NUMBER_OF_TOPICS 4

class questions
{
    public:

		static questions& read_questions();

        std::string draw_questions();
        std::string add_additional_question(size_t topic_id);
        void reset_questions();

		questions(const questions&) = delete;
		questions operator=(const questions&) = delete;

    private:

		size_t questions_cnt[NUMBER_OF_TOPICS];
        std::vector<std::string> m_question_table[NUMBER_OF_TOPICS];

};

#endif
