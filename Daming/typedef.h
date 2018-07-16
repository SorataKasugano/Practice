#pragma once

//根据学生、班级、课程、教师和学校五种概念，请完成以下问题。
//1.	请设计五个类或结构体，分别表现这五个概念。
//2.	请模拟产生这一个地区的2000名学生、100个班级、5门课程、100个教师和10个学校的对象或变量。
//3.	请模拟进行学生分配学校和班级的过程，一个学生只能在一个学校的一个班级上学，班级学生数量在15 - 25之间。
//4.	请模拟进行教师教学任务分配，所有学校都开设5门课程。一个教师只能分配在一个学校的一门课程，但可以承担多个班级的教学。
//5.	请根据学校、班级和学生姓名或学号，查出其5门课程的任课老师。

#include <string>
#include <unordered_map>

struct Student
{
	int id;// 220189(school)9(class)19
	std::string name;
	/*...*/
};

struct Course
{
	int id;// 0 to 4
	std::string name;
	/*...*/
};

struct Teacher
{
	int id;// 120189(school)009
	std::string name;
	Course course;
	/*...*/
};

struct Klass
{
	int id;// 000 to 900
	std::string name;
	std::unordered_map<int, Student> students;
	std::unordered_map<int, Teacher> teachers;
	std::unordered_map<int, Course> courses;
	/*...*/
};

struct School
{
	int id;// 0000 to 9000
	std::string name;
	std::unordered_map<int, Klass> klasses;
	/*...*/
};