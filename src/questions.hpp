#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include <vector>
#include <fstream>
#include <array>
#include <memory>

#define NUMBER_OF_TOPICS 4

class questions
{
  public:

    static questions& get_questions();

    std::string draw_questions();
    std::string draw_additional_question(size_t topic_id);
      void reset_questions_cnt();

    std::string get() { return m_question_table[1][2]; };

  private:

		size_t questions_cnts[NUMBER_OF_TOPICS];
    std::string m_topic_names[NUMBER_OF_TOPICS];
    const char* m_topic_file_names[NUMBER_OF_TOPICS] =
    {
      "basic0.txt","basic1.txt","basic2.txt","advanced.txt"
    };
    std::vector<std::string> m_question_table[NUMBER_OF_TOPICS];
    inline static std::unique_ptr<questions> m_instance;

    void load_topic_from_file(size_t topic_id);

    questions();
};

#endif
