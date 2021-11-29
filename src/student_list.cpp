#include "student_list.hpp"
#include "json.hpp"

#include <fstream>

using json = nlohmann::json;

void student_list::add_points(size_t student_id, double points)
{
	size_t index = 0;
	for (auto& s : m_students)
	{
		if (s.m_id == student_id)
		{
			s.add_points(points);
			return;
		}
		++index;
	}
	throw std::invalid_argument {"Student is not in the student list!"};
}

void student_list::end_student_session(size_t student_id)
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
		s_data["exam_rating"] = s.m_exam_rating;
		output_data.push_back(s_data);
	}
	std::ofstream done_students_file("../exam_data/exam_grades.json");
	if (done_students_file.is_open())
	{
		done_students_file << output_data.dump(4);
	}
	else
		throw std::runtime_error("Could not open \"exam_grades.json\"!");
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
		m_students.clear();
		for (const auto& student : data)
		{
			m_students.emplace_back(student["id"],
				student["name"],
				student["surname"],
				student["average_rating"],
				evaluate_additional_questions_number(student["average_rating"]));
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
