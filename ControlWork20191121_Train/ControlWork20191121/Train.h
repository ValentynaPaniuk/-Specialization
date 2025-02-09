﻿#pragma once
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
class Train
{
	int numberTrain;
	string nameTrain;
	int numberCars;
	int summa;
	Car *car; //Динамічно виділяється пам'ять під кількість вагонів в поїзді

	

public:
	//конструктори
	Train();
	Train(int numberTrain, string nameTrain, int numberCars);
	Train(const Train &other);

	//Методи

	int GetNumberTrain();
	void PrintTrain();
	void FillTrain();
	int CarMaxPassengers();
	int CarMinPassengers();
	int TotalPassengers();





	~Train();

};

