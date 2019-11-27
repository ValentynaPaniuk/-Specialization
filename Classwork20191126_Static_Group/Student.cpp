#include "Student.h"


unsigned int Student::Counter = 0;
Student::Student()
{
	Counter++;
	ID = Counter;
	cout << "Default constructor" << endl;
}

Student::Student(string name, string surname, int age)
{

	this->name = name;
	this->surname = surname;
	this->age = age;
	Counter++;
	ID = Counter;
	cout << "Overload constructor. STUDENT" << endl;
}

int Student::GetID()
{
	return ID;
}

void Student::SetName(string name)
{
	this->name = name;
}

string Student::GetName()
{
	return name;
}

string Student::GetSurname()
{
	return surname;
}



void Student::SetSurname(string surname)
{
	this->surname = surname;
}

void Student::SetAge(int age)
{
	this->age = age;
}

int Student::GetAge()
{
	return age;
}



void Student::FillStudent()
{
	cout << "Student ID=> " << ID << endl;
	cout << "Enter Name student: ";
	cin >> this->name;
	cout << "Enter Surname student: ";
	cin >> this->surname;
	cout << "Enter Age student: ";
	cin >> this->age;
}

void Student::ShowInfoStudent()
{
	cout << name << " " << surname << " Age: " << age << endl;
}


Student::~Student()
{
	cout << "Default destructor" << endl;
}


