#pragma once
#include <string>
#include "Student.h"

using namespace std;

/*ООП
Створити клас Group ("Група"), що містить в собі наступні поля:
- назва групи
- курс
- назва спеціальності (char *)
- масив студентів, що також описаний окремим класом Student.
Даний клас містить набір методів, що дозволяють:
- здійснити модифікацію окремих полів класу (назви групи, курсу та спеціальності)
- вивести інформацію про групу вцілому
- змінювати інформацію про студентів.*/

class Group
{
	
	string nameGroup;
	string nameSpecialty;
	unsigned int sizeGroup;
	unsigned int course;
	unsigned int IDGroup;
	Student *student;

public:

	static unsigned int CounterGroup;

	//Constructors:
	Group();
	Group(string nameGroup, string nameSpecialty, int sizeGroup, int Course);

	//Metody:
	int GetIDGroup();
	void FillGroup();
	void ShowInfoGroup();
	void ChangeStudentInfo();
	



	//Destructor
	~Group();
};

