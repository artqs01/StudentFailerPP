#ifndef STUDENT_LIST_HPP
#define STUDENT_LIST_HPP

#include <vector>
#include <string>
#include <memory>

#define GETTER(name, value) const auto &name() const {return value;}

class topic
{
  public :
  friend class questions;

  std::string draw_question();
  GETTER(get_topic_name, m_topic_name);
  GETTER(get_level, m_level);

  topic() = default;

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
    GETTER(get_topic_list, m_topic_list);

    questions();

  private:

		std::vector<topic> m_topic_list;
    void load_questions();
};

#endif
