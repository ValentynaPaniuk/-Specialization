#include <iostream>
#include <string>
#include <ctime>
#include "XString.h"
using namespace std;
/*���
������� ���� XString, ���� ����� �����. ���� ������� ������ �������� ������������:
����������� �� ������������, ���� �������� �������� ����� �������� 80 �������;
�����������, ���� ������� ����� �� ��������� ���� ������, ��������� � ����� ���������;
����������� ����.
��� ����, ����� ���� ������� ������ ���� �������������� �������� ��� ������ � �������:

�������� *: ������� ��������� ����� �����, ���� ����������� ������ �������� ���� �����, 
����� �� ������ �������. ���������, ����������� �������� ����� "Microsoft" �� "Windows" 
���� ����� "ioso".

�������� /: ������� ��������� ����� �����, ���� ����������� ������ ������ ������� 
������� �����, ���� ���� � �������. ���������, ����������� ������ ����� "Microsoft" ��
"Windows" ���� ����� "Mcrft".

�������� +, �� �������� ������ ��� ����� (������������ �����). 
���������, ����������� ��������� ���� ����� "Microsoft" �� "Windows" ���� ����� 
"MicrosoftWindows".
�������� *=, /= �� +=, �� ���� �� ������������� ��������. */
int main()
{
	int size = 40;
	char *arr;
	cout << "== A == "<< endl;
	XString a(size);
	a.ShowInfoRow();
	cout << "\n== B ==" << endl;
	XString b(a);
	b.ShowInfoRow();
	cout << "== C ==" << endl;
	XString c(size);
	cout << endl;
	cout << "\n== Operator * ==" << endl;
	c.operator*(a);
	cout << "\n== Operator * ==" << endl;
	cout << endl;
	cout << "\n== Operator / ==" << endl;
	c.operator/(a);
	cout << "\n== Operator / ==" << endl;
	cout << endl;
	cout << "\n== Operator + ==" << endl;
	c.operator+(a);
	cout << "\n== Operator + ==" << endl;
	cout << endl;



	system("pause");
	return 0;
}