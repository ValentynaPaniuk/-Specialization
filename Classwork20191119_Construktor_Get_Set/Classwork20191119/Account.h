#pragma once
# include <iostream>
# include <string>
# include "Account.h"
using namespace std;

/*ООП
Написати клас "Карточка на знижку", який містить наступну інформацію:
Номер карточки
Розмір знижки (знижка передбачається накопичуваною; на початковому етапі вона рівна 1%. За кожні 1000 грн. покупки, сума знижки збільшується на 1%.)
Приховане допоміжне поле для збереження вартості накупленого товару
Забезпечити можливість:
Купляти товар з використанням карточки на знижку
Виводити інформацію про поточну величину знижки
Виводити інформацію про те, на яку суму ще необхідно докупити товару, щоб величина знижки збільшилась. */
class Account
{
	unsigned int number;
	double discount;
	double cost = 0;
	double summa = 0;
	double max_summa = 0;

	double x = 1000;
	double tmp;
	bool exit = false;

public:
	
	//Конструктор
	Account(unsigned int newNumber, double newDiscount, double cost, double newSumma, double newMaxSumma);

	//Методи
	unsigned int GetNumber();
	void SetNumber(unsigned int newNumber);
	unsigned int Getdiscount();
	void SetDiscount(unsigned int newDiscount);
	double GetCost();
	void SetCost(double newCost);
	double GetSumma();
	void SetSumma(double newSumma);
	double GetMaxSumma();
	void SetMaxSumma(double max_summa);
	void ShowAccount();
	void CostOfDiscount(unsigned int newNumber, double newDiscount, double newCost, double newSumma, double newMaxSumma);


};

