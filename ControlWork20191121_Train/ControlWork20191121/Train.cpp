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
Клас Train повинен містити поля:
1. номер поїзда;
2. назва поїзда (сполучення, наприклад "Львів - Київ");
3. поле "вагони" - вказівник на тип Car, якому буде виділятися динамічна пам'ять розміром в кількість вагонів, де індекс даного масиву вказує на номер вагону;
4. кількість вагонів(може бути полем - константою).
class Train
{
const  int size; // константне поле, ініціалізують у списку ініціалізації конструктора int number;
Car * train = new Car [size];
// ….
public:
Train(int size, int number) : size(size), number(number)
{// …
}
методи:
Конструктори: по замовчуванню, з параметрами та копіювання;
Стандартні методи доступу до полів класу;
Метод для знаходження вагона з максимальною кількість пасажирів;
Метод для знаходження вагона з мінімальною кількість пасажирів;
Метод для знаходження загальної кількості пасажирів в поїзді;
Метод для виведення інформації про поїзд:
загальна кількість пасажирів.
загальна кількість вагонів.
номер вагону в якому їхала найменша кількість пасажирів
номер вагону в якому їхала найбільша кількість пасажирів. */

// constructor copy

//1. Реалізувати статичні поля і методи в домашній роботі з поїздами.

static unsigned int counterTrain = 0;


Train::Train()
{
	counterTrain++;
	this->numberTrain = counterTrain;
	cout << "Default constructor!!! " << endl;
}

Train::Train(int numberTrain, string nameTrain, int numberCars)
{
	counterTrain++;
	this->numberTrain = counterTrain;
	this->nameTrain = nameTrain;
	this->numberCars = numberCars;
	this->car = new Car[this->numberCars];

}

// constructor copy
Train::Train(const Train & other)
{
	this->numberTrain = other.numberTrain;
	this->nameTrain = other.nameTrain;
	this->numberCars = other.numberCars;
	this->car = new Car[other.numberCars];
	for (int i = 0; i < other.numberCars; i++)
	{
		this->car[i] = other.car[i];
	}
	cout << "Copy constructor " << this << endl; // ссилка на адресу об'єкта
}

void Train::FillTrain()
{
	
	string typeCar;
	int numberOfPassengers;
	for (int i = 0; i < this->numberCars; i++)
	{

		cout << " =====  Enter information about wagon number " << i+1 << ": ===========  " << endl;
		cout << "Enter the wagon type (compartment/ seat/ sleeping): " << endl;
		cin >> typeCar;
		cout << "Enter the number of passengers in the wagon: " << endl;
		cin >> numberOfPassengers;
		car[i] = Car(i, typeCar, numberOfPassengers);

	}
}


int Train::GetNumberTrain()
{
	return numberTrain;
}

void Train::PrintTrain()
{
	cout << "===========================================================================================================" << endl;
	cout << "|| Train number " << this->numberTrain << " direction of transportation: " << this->nameTrain << " with the number of cars: " << this->numberCars << " ||" << endl;
	cout << "===========================================================================================================" << endl;
	cout << "Total number of passengers: " << TotalPassengers() << endl;
	cout << "The minimum number of passengers in a car number: " << CarMinPassengers() << endl;
	cout << "The maximum number of passengers in the car number: " << CarMaxPassengers() << endl;
}

int Train::CarMaxPassengers()
{
	int temp = 0;
	int tempID = 0;
	for (int i = 0; i < this->numberCars; i++)
	{
		if (car[i].GetNumberOfPassengers() > temp)
		{
			temp = car[i].GetNumberOfPassengers();
			tempID = i;
		}
	}
	return tempID;
}

int Train::CarMinPassengers()
{
	int temp = car[0].GetNumberOfPassengers();
	int tempID = 0;
	for (int i = 0; i < this->numberCars; i++)
	{
		if (car[i].GetNumberOfPassengers() < temp)
		{
			temp = car[i].GetNumberOfPassengers();
			tempID = i;
		}
	}
	return tempID;
}

int Train::TotalPassengers()
{
	for (int i = 0; i < numberCars; i++)
	{
		this->summa += this->car[i].GetNumberOfPassengers();
	}
	return this->summa;
}







Train::~Train()
{
	cout << "Default destructor!!! " << endl;
	car = nullptr;
	delete[] car;
}