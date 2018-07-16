#pragma once

//����ѧ�����༶���γ̡���ʦ��ѧУ���ָ��������������⡣
//1.	�����������ṹ�壬�ֱ������������
//2.	��ģ�������һ��������2000��ѧ����100���༶��5�ſγ̡�100����ʦ��10��ѧУ�Ķ���������
//3.	��ģ�����ѧ������ѧУ�Ͱ༶�Ĺ��̣�һ��ѧ��ֻ����һ��ѧУ��һ���༶��ѧ���༶ѧ��������15 - 25֮�䡣
//4.	��ģ����н�ʦ��ѧ������䣬����ѧУ������5�ſγ̡�һ����ʦֻ�ܷ�����һ��ѧУ��һ�ſγ̣������Գе�����༶�Ľ�ѧ��
//5.	�����ѧУ���༶��ѧ��������ѧ�ţ������5�ſγ̵��ο���ʦ��

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