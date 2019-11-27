#pragma once
#include <iostream>
#include <string>

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


class Student
{
	
	string name;
	string surname;
	unsigned int age;
	unsigned int ID;

public:

	static unsigned int Counter;
	// Constructor
	Student();
	Student(string name, string surname, int age);


	//Metody);
	int GetID();
	void SetName(string name);
	string GetName();
	void SetSurname(string surname);
	string GetSurname();
	void SetAge(int age);
	int GetAge();
	

	void FillStudent();


	void ShowInfoStudent();


	//Destructor
	~Student();

};

