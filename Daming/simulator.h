#pragma once
#include <iostream>
#include "typedef.h"

class Simulator
{
public:
	std::string joint_name(const char* prefix, int suffix);
	std::vector<int> shuffle_array(int size);

	void initialize(int stu_cnt,int klass_cnt,int course_cnt,int teacher_cnt,int school_cnt);
	//void distribute_students();
	//void distribute_teachers();

	void query_student_course(int school_name, int class_number, int student_number);
	/*...*/

private:
	std::unordered_map<int, Student> students_;
	std::unordered_map<int, Teacher> teachers_;
	std::unordered_map<int, Course> courses_;
	std::unordered_map<int, School> schools_;
};