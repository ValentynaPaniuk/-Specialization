#pragma once
#include "Train.h"
#include <iostream>
#include <string>
#include <ctime>
#include "Car.h"

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

static unsigned int counterCar = 0;

Car::Car()
{
	counterCar++;
	number = counterCar;
	cout << "Default constructor! " << endl;
}

Car::Car(int number, string typeCar, int numberOfPassengers)
{
	cout << "Overload constructor " << endl;
	counterCar++;
	number = counterCar;
	this->typeCar = typeCar;
	this->numberOfPassengers = numberOfPassengers;
}

string Car::GetTypeCar()
{
	return typeCar;
}


int Car::GetNumberOfPassengers()
{
	return numberOfPassengers;
}

int Car::GetNumber()
{
	return number;
}

void Car::FillCar()
{
	
	
}





void Car::PrintCar()
{
	cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
	cout << "Number of car: "<<this->number<<"\nType of car: " << this->typeCar << ";\t<<<<<<<<< === >>>>>>>\tNumber of passengers: " << this->numberOfPassengers << endl;
	cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << endl;

}


Car::~Car()
{
	cout << "Default destructor!" << endl;
}
