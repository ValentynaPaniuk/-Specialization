#include <iostream>
#include <string>
#include <ctime>
#include "Var.h"
using namespace std;
/*Реалізувати клас Var («Універсальна змінна»). Об’єкти цього класу можуть зберігати в
собі значення наступних типів: 
int,
double,
String(рядок; клас, який був створений раніше ).
Наприклад:
void main()
{
Var a = 15;
Var b = &quot;Hello&quot;;
Var c = 7.8;
Var d = &quot;50&quot;;
b = a + d;
cout &lt;&lt; b; //отримаємо 65
if (a == b)
cout &lt;&lt; &quot;Equal&quot; &lt;&lt; endl;
else
cout &lt;&lt; &quot;Not Equal&quot; &lt;&lt; endl;

}
Для класу Var необхідно перевантажити:
o арифметичні оператори: +, -, *, /, +=, -=, *=, /=
o оператори порівняння: &lt;, &gt;, &lt;=, &gt;=, ==, !=
o оператори &lt;&lt; &gt;&gt;;
Додати також до класу Var приведення до типу: int, double, char*.

Основні моменти:
o В змінній типу Var в довільний момент часу може знаходитись лише одне
значення( або int, або double, або String).
o Тип значення зберігається у додатковому приватному полі(enum або char)
наприклад: char type; // &#39;i&#39; -- int, &#39;d&#39; -- double, &#39;і&#39; -- String, &#39;\0&#39; -- непроініціалізований
об&#39;єкт 
При перевантаженні операторів слід врахувати наступне: 
o якщо при виконанні операції типи значень двох операндів типу Var різні, тоді
необхідно приводити (конвертувати) значення другого операнду до типу значення
першого операнду і тільки після цього виконувати операцію.
o При цьому значення і тип другого операнду в самому об’єкті Var не змінюється. 
Наприклад:
Var a(10), b = &quot;120&quot;, c, d = &quot;str&quot;;

c = a + b;
cout &lt;&lt; c; //отримаємо 130
c = a + d;
cout &lt;&lt; c; //отримаємо 10, оскільки приведення &#39;str&#39; до int дає 0
c = b + a;
cout &lt;&lt; c; //отримаємо &quot;12010&quot;
*/
int main()
{
	Var a(5);
	Var b(5.3);
	Var c("12345");
	Var d("678");
	cout << "==========================================================================" << endl;
	cout << "||                             Convert to INT:                          ||" << endl;
	cout << "==========================================================================" << endl;
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	a.operator+(b);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	a.operator+(c);
	cout << "A = " << a.GetA() << " B = " << b.GetB() << " C = " << c.GetC() << endl;
	a.operator+(d);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	a.operator-(b);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	a.operator-(c);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	a.operator*(b);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	a.operator*(c);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	a.operator/(b);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	a.operator/(c);
	cout << endl;
	cout << "==========================================================================" << endl;
	cout << "||                    Convert to DOUBLE:								  ||" << endl;
	cout << "==========================================================================" << endl;
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	b.operator+(a);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	b.operator+(c);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	b.operator-(a);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	b.operator-(c);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	b.operator*(a);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	b.operator*(c);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	b.operator/(a);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	b.operator/(c);
	cout << "==========================================================================" << endl;
	cout << "||                     Convert to STRING:                               ||" << endl;
	cout << "==========================================================================" << endl;
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	c.operator+(a);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;
	c.operator+(b);
	cout << "Int A = " << a.GetA() << "\tDouble B = " << b.GetB() << "\tString C = " << c.GetC() << endl;

	cout << "A < B: " << endl;
	bool result1 = a<b;
	cout << "Result( < )" << result1 << endl;

	cout << "A > B: " << endl;
	bool result2 = a > b;
	cout << "Result( < ) " << result2 << endl;

	cout << "A == B: " << endl;
	bool result3 = a == b;
	cout << "Result( == ) " << result3 << endl;

	cout << "A != B: " << endl;
	bool result4 = a != b;
	cout << "Result( != ) " << result4 << endl;



	


	system("pause");
	return 0;
}