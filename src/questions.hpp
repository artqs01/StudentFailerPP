#ifndef QUESTIONS_HPP
#define QUESTIONS_HPP

#include "utils.hpp"

#include <vector>
#include <string>
#include <memory>

class topic
{
	public :
		std::string draw_question();
		GET(get_topic_name, m_topic_name);
		GET(get_level, m_level);
		topic() = default;
		friend class questions;
	private:
		std::string m_topic_name;
		int m_level;
		std::vector<std::string> m_question_table;
		size_t m_questions_cnt;
};

class questions
{
	public:
		void reset_questions_base();
		GET_CONTAINER_MEMBER(get_topic, m_topic_list, topic_id);
		std::string draw_question(size_t topic_id) { return m_topic_list[topic_id].draw_question(); };
		questions();
	private:
		std::vector<topic> m_topic_list;
		void load_questions();
};

#endif
