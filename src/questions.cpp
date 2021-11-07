#include "questions.hpp"

questions::questions()
{
	for(size_t topic_id = 0; topic_id < NUMBER_OF_TOPICS; ++topic_id)
		load_topic_from_file(topic_id);
}

questions& questions::get_questions()
{

	if (!m_instance)
		m_instance = std::unique_ptr<questions>(new questions);
	return *m_instance;
}


void questions::load_topic_from_file(size_t topic_id)
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
			m_question_table[topic_id].push_back(line);
		}
	}
	else
		throw std::runtime_error{"Could not open the file"};
}
