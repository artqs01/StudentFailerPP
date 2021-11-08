#include "questions.hpp"

#include <fstream>
#include <random>
#include <iostream>

questions::questions()
{
	for(size_t topic_id = 0; topic_id < NUMBER_OF_TOPICS; ++topic_id)
		load_questions(topic_id);
}

questions& questions::get_questions()
{
	if (!m_instance)
		m_instance = std::unique_ptr<questions>(new questions);
	return *m_instance;
}

std::string questions::draw_question(size_t topic_id)
{
	std::random_device rand_num_gen;
	std::uniform_int_distribution<size_t> question_generator(0, m_questions_cnts[topic_id] - 1);
	std::string question = "";

	if (m_questions_cnts[topic_id])
	{
		std::swap(m_question_table[topic_id][question_generator(rand_num_gen)],
			m_question_table[topic_id][m_questions_cnts[topic_id] - 1]);

		question = m_question_table[topic_id][m_questions_cnts[topic_id]-- - 1];
	}
	else
		throw std::runtime_error{"Question base limit reached!"};

	return question;
}

void questions::reset_questions_base()
{
	for (int i = 0; i < NUMBER_OF_TOPICS; ++i)
		m_questions_cnts[i] = m_question_table[i].size();
}

void questions::load_questions(size_t topic_id)
{
	std::ifstream topic_file;
	topic_file.open(std::string{"../exam_data/"} + m_topic_file_names[topic_id]);

	if (topic_file.is_open())
	{
		std::string line;
		getline(topic_file, line);
		m_topic_names[topic_id] = line;
		
		while (!topic_file.eof())
		{
			getline(topic_file, line);
			if (line != "")
			{
				m_question_table[topic_id].push_back(line);
			}
		}

		m_questions_cnts[topic_id] = m_question_table[topic_id].size();
	}
	else
		throw std::runtime_error{"Could not open the file!"};
}
