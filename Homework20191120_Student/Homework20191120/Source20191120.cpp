#include<iostream>
#include<string>
#include<ctime>
#include "Student.h"

using namespace std;

/*Створити класс Student. 
Описати необхідні приватні поля(Ім'я, Призвіще, тощо )
Функціонал:
Виведення інформації:
Можливість порахувати середю оцінку  (оцінок 5)
Створити 5 об'єктів класу і відсортувати по успішності
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