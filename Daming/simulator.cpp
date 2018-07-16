#include "simulator.h"

std::string Simulator::joint_name(const char* prefix, int suffix)
{
	char suf[5];
	_itoa_s(suffix, suf, 10);
	return std::string(prefix).append(suf);
}

std::vector<int> Simulator::shuffle_array(int size)
{
	std::vector<int> arr(size);
	for (int i = 0;i < size;i++) arr[i] = i;
	for (int i = size - 1;i > 0;i--)
	{
		int j = rand() % (i + 1);
		std::swap(arr[i], arr[j]);
	}
	return arr;
}

void Simulator::initialize(int stu_cnt, int klass_cnt, int course_cnt, int teacher_cnt, int school_cnt)
{
	students_.reserve(stu_cnt);
	courses_.reserve(course_cnt);
	teachers_.reserve(teacher_cnt);
	schools_.reserve(school_cnt);
	std::vector<int> stu_shff = shuffle_array(stu_cnt);
	std::vector<int> tea_shff = shuffle_array(teacher_cnt);
	for (int i = 0;i < course_cnt; i++)
	{
		std::string name = joint_name("course_", i);
		courses_[i] = { i,name };
	}
	for (int i = 0;i < school_cnt; i++)
	{
		std::string name = joint_name("school_", i);
		std::unordered_map<int, Klass> klasses;
		for (int j = 0;j < klass_cnt / school_cnt;j++)
		{
			std::string k_name = joint_name("klass_", j);
			klasses[j * 100] = { j * 100,k_name };
		}
		schools_[i * 1000] = { i * 1000,name,klasses };
	}

	for (int i = 0;i < stu_cnt;i++)
	{
		std::string name = joint_name("student_", stu_shff[i]);
		int school_num = (i / (stu_cnt / school_cnt)) * 1000;
		int klass_num = ((i % (stu_cnt / school_cnt)) / (stu_cnt / klass_cnt)) * 100;
		int student_num = 220180000 + school_num + klass_num + i % (stu_cnt / klass_cnt);
		Student student{ student_num,name };
		students_[student_num] = student;
		// distribute students to schools and classes
		schools_[school_num].klasses[klass_num].students[student_num] = student;
	}
	for (int i = 0;i < teacher_cnt; i++)
	{
		std::string name = joint_name("teacher_", tea_shff[i]);
		int course_num = i % course_cnt;
		int school_num = (i / (teacher_cnt / school_cnt)) * 1000;
		int teacher_num = 120180000 + school_num + i % (teacher_cnt / school_cnt);
		Teacher teacher{ teacher_num,name ,courses_[course_num] };
		teachers_[teacher_num] = teacher;
		// distribute teachers to schools and classes
		for (int j = 0, managed = 0;j < klass_cnt / school_cnt && managed < 5;j++)
		{// one teacher manages five class
			auto& klass = schools_[school_num].klasses[j * 100];
			if (klass.courses.find(course_num) == klass.courses.end())
			{
				klass.courses[course_num] = courses_[course_num];
				klass.teachers[teacher_num] = teacher;
				managed++;
			}
		}
	}
}

void Simulator::query_student_course(int school_number, int klass_number, int student_number)
{
	if (schools_.find(school_number) == schools_.end())
	{
		std::cerr << "Wrong school name.\n";
		return;
	}
	auto klasses = schools_[school_number].klasses;
	if (klasses.find(klass_number) == klasses.end())
	{
		std::cerr << "Wrong klass name.\n";
		return;
	}
	auto klass = schools_[school_number].klasses[klass_number];
	if (klass.students.find(student_number) == klass.students.end())
	{
		std::cerr << "Wrong student number.\n";
		return;
	}
	for (auto teacher : klass.teachers)
	{
		std::cout << "Course name: " << teacher.second.course.name
			<< "\nTeacher name: " << teacher.second.name << "\n";
	}
}
