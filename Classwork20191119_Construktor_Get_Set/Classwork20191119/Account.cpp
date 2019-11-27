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

	Account :: Account(unsigned int newNumber, double newDiscount, double newCost, double newSumma, double newMaxSumma)
	{
		cout << "Default constructor" << endl;
		number = newNumber;
		discount = newDiscount;
		summa = newSumma;
		cost = newCost;
	}

	unsigned int Account :: GetNumber()
	{
		return number;
	}
	void Account :: SetNumber(unsigned int newNumber)
	{
		number = newNumber;
	}
	unsigned int Account :: Getdiscount()
	{
		return discount;
	}
	void Account :: SetDiscount(unsigned int newDiscount)
	{
		discount = newDiscount;
	}

	double Account::GetCost()
	{
		return cost;
	}

	void Account::SetCost(double newCost)
	{
		cost = newCost;
	}
	double Account :: GetSumma()
	{
		return summa;
	}
	void Account :: SetSumma(double newSumma)
	{
		summa = newSumma;
	}
		
	double Account :: GetMaxSumma()
	{
		return max_summa;
	}
	void Account :: SetMaxSumma(double newMaxSumma)
	{
		max_summa = newMaxSumma;
	}
	void Account :: ShowAccount()
	{
		cout << "Number account: " << number << "\nThe amount of purchase: " << summa << "\nDiscount: " << discount << endl;
	}
		
	void Account::CostOfDiscount(unsigned int newNumber, double newDiscount, double newCost, double newSumma, double newMaxSumma)
	{
		cout << "\n=================================================" << endl;
		cout << "Number of your Bank cards: " << newNumber << " funds in the account: "<< newMaxSumma <<" grn"<< endl;
		cout << "=================================================" << endl;
		while (!exit)
		{
			cout << "****************************" << endl;
			cout << "Enter the purchase amount ";
			cout << "(if You stop shopping - press 0): " << endl;
			cin >> newSumma;
			newCost += newSumma;
			newMaxSumma -= newSumma;
			if (newSumma == 0)
			{
				cout << "Exit" << endl;
				exit = true;
			}
			else if (newMaxSumma<=0)
			{
				cout << "!!!!!!!!!!!  There is not enough money  !!!!!!!!!!!!!!!" << endl;
				exit = true;
			}
			cout << "Account balance: " << newMaxSumma << " grn" << endl;
			cout << "****************************" << endl;
		}
		cout << endl;
		cout << "The cost without discount: " << newCost << endl;
		exit = false;
		tmp = newCost;
		while (!exit)
		{
			if (tmp >= 1000)
			{
				newDiscount++;
				x += 1000;
				tmp -= 1000;
				
			}
			if (newDiscount >= 10 || tmp < 1000 || newMaxSumma<=0)
			{
				exit = true;
			}
		}
		cout << newDiscount << " % discount v grn = " << newCost * (newDiscount / 100) << " grn" << endl;
		cout << "The cost of discount: " << newCost - (newCost * (newDiscount / 100)) << " grn" << endl;
		cout << "The amount of money for the extra discount " << x - (newCost - (newCost * (newDiscount / 100))) << " grn" << endl;
		cout << "Account " << newNumber<<" balance: "<< newMaxSumma <<" grn"<< endl;
		cout << endl;
	}
