#pragma once
#include<iostream>
#include<string>

/*�������� ����� Student. 
������� �������� ������� ����(��'�, �������, ���� )
����������:
��������� ����������:
��������� ���������� ������ ������  (������ 5)
�������� 5 ��'���� ����� � ����������� �� ��������
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

