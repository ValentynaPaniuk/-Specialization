#pragma once
#include <iostream>
#include <string>

using namespace std;

/*���
�������� ���� Group ("�����"), �� ������ � ��� ������� ����:
- ����� �����
- ����
- ����� ������������ (char *)
- ����� ��������, �� ����� �������� ������� ������ Student.
����� ���� ������ ���� ������, �� ����������:
- �������� ����������� ������� ���� ����� (����� �����, ����� �� ������������)
- ������� ���������� ��� ����� �������
- �������� ���������� ��� ��������.*/


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

