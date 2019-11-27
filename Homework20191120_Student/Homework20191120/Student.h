#pragma once
#include<iostream>
#include<string>

/*Створити класс Student. 
Описати необхідні приватні поля(Ім'я, Призвіще, тощо )
Функціонал:
Виведення інформації:
Можливість порахувати середю оцінку  (оцінок 5)
Створити 5 об'єктів класу і відсортувати по успішності
*/
using namespace std;
class Student
{
	string name;
	string surname;
	int average;
	
	void Average();

public:

	
	Student();
	Student(string name, string surname, int average);
	void PrintStudent();
	void CreateClass(Student students[], const int SIZE, string name, string surname);
	
	void Sorting(Student students[], const int SIZE);
	
	~Student();
};

