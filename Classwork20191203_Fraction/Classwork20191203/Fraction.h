﻿#pragma once
#include <iostream>
using namespace std;
/*Завдання 1.
Визначити клас Дріб(чисельник та знаменник - цілі).
Визначити для класу:
//////////////////////////// o конструктор за замовчуванням( дріб 0/1)
//////////////////////////// o конструктор з 1 параметром (знаменник у дробу == 1)
//////////////////////////// o конструктор з 2 параметрами( передбачити валідацію для знаменника)
//////////////////////////// o методи доступу до полів класу
//////////////////////////// o метод виводу дробу на екран у вигляді чисельник / знаменник
//////////////////////////// o метод скорочення дробу
Операції
//////////////////////////// o додавання(+) двох дробів(глобальна функція)
//////////////////////////// o віднімання(-) двох дробів(дружня глобальна функція)
//////////////////////////// o множення(*) двох дробів(метод класу)
//////////////////////////// o ділення(/) двох дробів(метод класу)
//////////////////////////// o (++) 2 форми, збільшення дробу на 1(методи класу)
//////////////////////////// o (--) 2 форми, зменшення дробу на 1(глобальні функції)
o порівняння дробів (==, !=) (глобальні функції)
o порівняння дробів(>; <;) (методи класу)
////////////////////////// o перетворення до типу int, що повертає цілу частину дробу, наприклад, для дробу10/4 ціла частина рівна 2
////////////////////////// o перетворення до типу double, що повертає десятковий дріб, наприклад, звичайному дробу 10/4 відповідає десятковий дріб 2.5
//////////////////////////Валідація: знаменник не повинен дорівнювати нулю, 
//////////////////////////знаменник не повинен бути від’ємним(тобто дріб 1/ -2 перетворювати у -1/ 2)
Перевірити роботу класу*/

class Fraction
{
	int x; //Чисельник
	int y; //Знаменник

public:
	//o конструктор за замовчуванням( дріб 0/1)
	Fraction();
	//o конструктор з 1 параметром (знаменник у дробу == 1)
	Fraction(int y);
	//o конструктор з 2 параметрами( передбачити валідацію для знаменника)
	Fraction(int x, int y);

	//o методи доступу до полів класу
	int GetX();
	int GetY();
	void SetX(int x);
	void SetY(int y);
	//o метод виводу дробу на екран у вигляді чисельник / знаменник
	void ShowInfoFraction();
	
	//o метод скорочення дробу
	static int Reduction(int x, int y); //-------------------------- не працює
	//o додавання(+) двох дробів(глобальна функція)
	static void Addition(Fraction &a, Fraction &b);

	//o віднімання(-) двох дробів(дружня глобальна функція)
	friend void Subtraction(Fraction &a, Fraction &b);

	//o множення(*) двох дробів(метод класу)
	void Multiplication(Fraction a, Fraction b);

	//o ділення(/ ) двох дробів(метод класу)
	void Division(Fraction a, Fraction b);

	//o(++) 2 форми, збільшення дробу на 1(методи класу)
	void AddOne(Fraction a);
	
	//o(--) 2 форми, зменшення дробу на 1(глобальні функції)
	static void SubtractOne(Fraction &a);

	//o порівняння дробів(== , != ) (глобальні функції)

	//o порівняння дробів(>; , <;) (методи класу)

	//o перетворення до типу int, що повертає цілу частину дробу, наприклад, для дробу 10 / 4 ціла частина рівна 2
	void IntDivision();

	// o перетворення до типу double, що повертає десятковий дріб, наприклад, звичайному дробу 10 / 4 відповідає десятковий дріб 2.5
	void DoubleDivision();

	~Fraction();
};

