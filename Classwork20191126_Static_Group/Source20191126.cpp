#include <iostream>
#include <string>
#include <ctime>
#include "Student.h"
#include "Group.h"
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


int main()
{
	//Group group1("34C9", "Developer", 1, 4);
	//group1.ShowInfoGroup();
	Group group2("123","Grafic", 2, 3);
	group2.ShowInfoGroup();
	group2.ChangeStudentInfo();
	group2.ShowInfoGroup();

	 
	

	system("pause");
	return 0;
}