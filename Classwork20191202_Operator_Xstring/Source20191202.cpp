#include <iostream>
#include <string>
#include <ctime>
#include "XString.h"
using namespace std;
/*ООП
Створіть клас XString, який описує рядок. Клас повинен містити наступні конструктори:
конструктор по замовчуванню, який дозволяє створити рядок довжиною 80 символів;
конструктор, який створює рядок та ініціалізує його рядком, переданим в якості параметра;
конструктор копій.
Крім того, даний клас повинен містити набір перевантажених операцій для роботи з рядками:

операція *: повинна повертати новий рядок, який утворюється шляхом перетину двох рядків, 
тобто їх спільні символи. Наприклад, результатом перетину рядків "Microsoft" та "Windows" 
буде рядок "ioso".

операція /: повинна повертати новий рядок, який утворюється шляхом відбору символів 
першого рядка, яких немає в другому. Наприклад, результатом ділення рядка "Microsoft" на
"Windows" буде рядок "Mcrft".

операцію +, що дозволяє додати два рядки (конкатенація рядків). 
Наприклад, результатом додавання двох рядків "Microsoft" та "Windows" буде рядок 
"MicrosoftWindows".
операцій *=, /= та +=, які діють по вищеописаному принципу. */
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