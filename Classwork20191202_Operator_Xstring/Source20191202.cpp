#include <iostream>
#include <string>
#include <ctime>
#include "XString.h"
using namespace std;
/*���
������� ���� XString, ���� ����� �����. ���� ������� ������ ������� ������������:
����������� �� ������������, ���� �������� �������� ����� �������� 80 �������;
�����������, ���� ������� ����� �� �������� ���� ������, ��������� � ����� ���������;
����������� ����.
��� ����, ����� ���� ������� ������ ���� �������������� �������� ��� ������ � �������:

�������� *: ������� ��������� ����� �����, ���� ����������� ������ �������� ���� �����, 
����� �� ����� �������. ���������, ����������� �������� ����� "Microsoft" �� "Windows" 
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

	char arr[80];
	cout << "Enter text: ";
	cin >> arr;
	cout << "== A == "<< endl;
	XString a(arr);
	a.ShowInfoRow();
	cout << "\n== B ==" << endl;
	XString b(a);
	b.ShowInfoRow();
	cout << endl;
	cout << "Enter text: ";
	cin >> arr;
	cout << "== C ==" << endl;
	XString c(arr);
	
	cout << "\n== Operator * ==" << endl;
	c.operator*=(a);
	cout << "\n== Operator * ==" << endl;
	cout << endl;
	cout << "\n== Operator / ==" << endl;
	c.operator/=(a);
	cout << "\n== Operator / ==" << endl;
	cout << endl;
	cout << "\n== Operator + ==" << endl;
	c.operator+(a);
	cout << "\n== Operator + ==" << endl;
	cout << endl;



	system("pause");
	return 0;
}