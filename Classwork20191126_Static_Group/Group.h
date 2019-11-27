#pragma once
#include <string>
#include "Student.h"

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

