#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include <vector>
#include <string>
#include <memory>

#define NUMBER_OF_TOPICS 4

class questions
{
  public:

    static questions& get_questions();

    std::string draw_question(size_t topic_id);
    void reset_questions_base();

    std::string get_topic_name(size_t topic_id) { return m_topic_names[topic_id]; };

  private:

		size_t m_questions_cnts[NUMBER_OF_TOPICS] = {};
    std::string m_topic_names[NUMBER_OF_TOPICS];
    const char* m_topic_file_names[NUMBER_OF_TOPICS] =
    {
      "basic0.txt","basic1.txt","basic2.txt","advanced.txt"
    };
    std::vector<std::string> m_question_table[NUMBER_OF_TOPICS];
    inline static std::unique_ptr<questions> m_instance;

    void load_questions(size_t topic_id);

    questions();
};

#endif
