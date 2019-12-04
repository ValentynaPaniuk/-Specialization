#include <iostream>
#include <string>
#include <ctime>
#include "Fraction.h"

using namespace std;
/*Завдання 1.
Визначити клас Дріб(чисельник та знаменник - цілі).
Визначити для класу:
o конструктор за замовчуванням( дріб 0/1)
o конструктор з 1 параметром (знаменник у дробу == 1)
o конструктор з 2 параметрами( передбачити валідацію для знаменника)
o методи доступу до полів класу
o метод виводу дробу на екран у вигляді чисельник / знаменник
o метод скорочення дробу
Операції
o додавання(+) двох дробів(глобальна функція)
//////////////////////////////////////////////o віднімання(-) двох дробів(дружня глобальна функція)
o множення(*) двох дробів(метод класу)
o ділення(/) двох дробів(метод класу)
o (++) 2 форми, збільшення дробу на 1(методи класу)
o (--) 2 форми, зменшення дробу на 1(глобальні функції)
o порівняння дробів (==, !=) (глобальні функції)
o порівняння дробів(&gt;, &lt;) (методи класу)
o перетворення до типу int, що повертає цілу частину дробу, наприклад, для дробу
10/4 ціла частина рівна 2
o перетворення до типу double, що повертає десятковий дріб, наприклад, звичайному
дробу 10/4 відповідає десятковий дріб 2.5
Валідація: знаменник не повинен дорівнювати нулю, знаменник не повинен бути
від’ємним(тобто дріб 1/ -2 перетворювати у -1/ 2)
Перевірити роботу класу*/

int main()
{
Fraction a(12,24);
Fraction b(5, 3);

a.ShowInfoFraction();
b.ShowInfoFraction();

cout << "===========================" << endl;
a.ShowInfoFraction();
b.ShowInfoFraction();
Fraction::Addition(a, b);
cout << "===========================" << endl;
cout << "===========================" << endl;
a.ShowInfoFraction();
b.ShowInfoFraction();
Subtraction(a, b);
cout << "===========================" << endl;
cout << "===========================" << endl;
a.ShowInfoFraction();
b.ShowInfoFraction();
a.Multiplication(a, b);
cout << "===========================" << endl;
cout << "===========================" << endl;
a.ShowInfoFraction();
b.ShowInfoFraction();
a.Division(a, b);
cout << "===========================" << endl;
cout << "===========================" << endl;
a.ShowInfoFraction();
a.AddOne(a);
cout << endl;
b.ShowInfoFraction();
b.AddOne(b);
cout << "===========================" << endl;
cout << "===========================" << endl;
a.ShowInfoFraction();
a.SubtractOne(a);
cout << endl;
b.ShowInfoFraction();
b.SubtractOne(b);
cout << "===========================" << endl;
cout << "===========================" << endl;
a.ShowInfoFraction();
a.IntDivision();
b.ShowInfoFraction();
b.IntDivision();
cout << "===========================" << endl;
cout << "===========================" << endl;
a.ShowInfoFraction();
a.DoubleDivision();
b.ShowInfoFraction();
b.DoubleDivision();




	system("pause");
	return 0;
}