#include "questions.hpp"

#include <fstream>
#include <random>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

questions::questions()
{
	load_questions();
	reset_questions_base();
}

std::string topic::draw_question()
{
	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<size_t> question_generator(0, m_questions_cnt - 1);
	std::string question = "";

	if (m_questions_cnt)
	{
		std::swap(m_question_table[question_generator(rng)],
			m_question_table[m_questions_cnt - 1]);
		question = m_question_table[m_questions_cnt-- - 1];
	}
	else
	{
		throw std::runtime_error{"Question base limit reached!"};
	}

	return question;
}

void questions::reset_questions_base()
{
	for (auto& topic : m_topic_list)
	{
		topic.m_questions_cnt = topic.m_question_table.size();
	}
		
}

void questions::load_questions()
{
	std::ifstream questions_file("../exam_data/questions.json");

	if (questions_file.is_open())
	{
		json data;
		questions_file >> data;

		size_t i = 0;
		m_topic_list.resize(data.size());
		for (const auto& topic_set : data)
		{
			m_topic_list[i].m_topic_name = topic_set["topic"];
			m_topic_list[i].m_level = topic_set["level"];
			auto question_set = topic_set["questions"];
			std::copy(question_set.begin(), question_set.end(),
				std::back_inserter(m_topic_list[i].m_question_table));
			m_topic_list[i].m_questions_cnt = m_topic_list[i].m_question_table.size();
			++i;
		}
	}
	else
		throw std::runtime_error("Could not open \"questions.json\"!");
}
