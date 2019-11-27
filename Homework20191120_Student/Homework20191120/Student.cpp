#include "Student.h"
#include <iostream>
#include<string>
# include <ctime>

using namespace std;
/*Створити класс Student. 
Описати необхідні приватні поля(Ім'я, Призвіще, тощо )
Функціонал:
Виведення інформації:
Можливість порахувати середю оцінку  (оцінок 5)
Створити 5 об'єктів класу і відсортувати по успішності
*/


Student::Student() // дефолтний конструктор
{

}
Student::Student(string name, string surname, int average)
{
	cout << "Overload constructor == = > " << endl;
	this->name = name;
	this->surname = surname;
	this->average = average;

};

void Student::PrintStudent()
{
	cout << "***********************************************" << endl;
	cout << this->name << " " << this->surname <<"\nAvarage: "<<this->average<< endl;
	cout << "***********************************************" << endl;
}
void Student::CreateClass(Student students[], const int SIZE, string name, string surname)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout<<"=== Add student number " << i+1 << " : " << endl;
		cout << "Enter name: " << endl;
		cin >> name;
		cout << "Enter surname: " << endl;
		cin >> surname;
		students[i] = Student(name, surname, average);
		students[i].Average();
		
	}
	for (int i = 0; i < SIZE; i++)
	{
		students[i].PrintStudent();
	}

}
void Student::Sorting(Student students[], const int SIZE)
{
	cout << "\n\n Sorting students by achievement: " << endl;
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (students[j].average > students[j + 1].average)
			{
				swap(students[j], students[j + 1]);
			}
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		students[i].PrintStudent();
	}

}
void Student::Average()
{
	int summagrades = 0;
	for (int i = 0; i < 5; i++)
	{
		int grades = rand() % 12 + 1;
		cout << "Grades " << i+1 << " = " <<grades<<"; ";
		summagrades += grades;
		average = summagrades / 5;

	}
	cout << "                                Average score: " << average << endl;

}
;





Student::~Student()
{
	cout << "Default destructor! " << endl;
}
