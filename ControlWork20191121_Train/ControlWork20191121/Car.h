#pragma once
#include<iostream>
#include <string>
#include<ctime>

using namespace std;

/*Написати програму роботи з поїздами, на основі класів Car(Вагон) та  Train (Поїзд). Програма пропонує ввести з клавіатури:
Кількість поїздів;
Кількість вагонів для кожного поїзда.
На основі уведених даних створюються поїзди, виводиться загальна інформація про них та набір наступних звітів:
Поїзд в якому їхала найбільша кількість пасажирів.
Поїзд в якому їхала найменша кількість пасажирів.
Клас Car повинен містити поля:
1. тип  вагона(купе, плацкарт, спальний);
2. кількість пасажирів у вагоні
методи:
конструктори
методи доступу до полів
виводу інформації про вагон
*/

// constructor copy

//1. Реалізувати статичні поля і методи в домашній роботі з поїздами.

class Car
{
	int number;
	string typeCar;
	unsigned int numberOfPassengers;

public:
	Car();
	Car(int number, string typeCar, int numberOfPassengers);
	string GetTypeCar();
	int GetNumberOfPassengers();
	int GetNumber();
	void FillCar();
	void PrintCar();

	~Car();
};
