#include "student_list.hpp"

#include "json.hpp"
#include <fstream>

using json = nlohmann::json;

void student_list::end_student_session(int student_id)
{
	size_t index = 0;
	for (auto& s : m_students)
	{
		if (s.m_id == student_id)
		{
			m_students_after_exam.push_back(s);
			m_students.erase(m_students.begin() + index);
			return;
		}
		++index;
	}
	throw std::invalid_argument {"Student is not in the student list!"};
}

void student_list::save_ratings_as_json()
{
	json output_data;
	for (auto s : m_students_after_exam)
	{
		json s_data;
		s_data["id"] = s.m_id;
		s_data["name"] = s.m_name;
		s_data["surname"] = s.m_surname;
		s_data["avreage_rating"] = s.m_avreage_rating;
		s_data["exam_rating"] = s.m_exam_rating;
		output_data.push_back(s_data);
	}
	std::ofstream done_students_file("../exam_data/students_completed.json");
	if (done_students_file.is_open())
	{
		done_students_file << output_data;
	}
	else
		throw std::runtime_error("Could not open \"students_completed.json\"!");
}

const student& student_list::get_student(int student_id) const
{
	for (auto& s : m_students)
	{
		if (s.m_id == student_id)
			return s;
	}
	throw std::invalid_argument {"Student is not in the student list!"};
}

student_list::student_list()
{
	load_student_list();
}

void student_list::load_student_list()
{
	std::ifstream students_file("../exam_data/students.json");

	if (students_file.is_open())
	{
		json data;
		students_file >> data;

		size_t i = 0;
		m_students.resize(data.size());
		for (const auto& student : data)
		{
			m_students[i].m_id = student["id"];
			m_students[i].m_name = student["name"];
			m_students[i].m_surname = student["surname"];
			m_students[i].m_avreage_rating = student["average_rating"];
			m_students[i].m_additional_questions_cnt =
				evaluate_additional_questions_number(m_students[i].m_avreage_rating);
			++i;
		}
	}
	else
		throw std::runtime_error("Could not open \"students.json\"!");
}

size_t student_list::evaluate_additional_questions_number(double avreage_rating)
{
	return (avreage_rating - 3) * 2;
}
