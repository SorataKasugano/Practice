#include <time.h>
#include "simulator.h"

int main()
{
	Simulator simulator;
	srand((unsigned)time(nullptr));
	simulator.initialize(2000, 100, 5, 100, 10);
	int school_number, class_number, student_number;
	while (true) 
	{
		std::cout << "Press any key to start a query about one student's course info.\n";
		system("pause");
		std::cout << "Please input school code(0000~9000,delta 1000):";
		std::cin >> school_number;
		std::cout << "Please input class code(000~900,delta 100):";
		std::cin >> class_number;
		std::cout << "Please input student number(00~19):22018" << school_number / 1000 << class_number / 100;
		std::cin >> student_number;
		simulator.query_student_course(school_number, class_number, 220180000 + school_number + class_number + student_number);
	}
	return 0;
}