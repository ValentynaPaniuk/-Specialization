#include<iostream>
#include<string>
#include<ctime>
#include "Student.h"

using namespace std;

/*�������� ����� Student. 
������� �������� ������� ����(��'�, �������, ���� )
����������:
��������� ����������:
��������� ���������� ������ ������  (������ 5)
�������� 5 ��'���� ����� � ����������� �� ��������
*/
int main()
{
	srand(unsigned(time(NULL)));
	const int SIZE = 3;
	Student students[SIZE];
	string name;
	string surname;
	int average;
	
		students->CreateClass(students, SIZE, name, surname);
		
		students->Sorting(students, SIZE);
		
	
	

	

	system("pause");
	return 0;
}