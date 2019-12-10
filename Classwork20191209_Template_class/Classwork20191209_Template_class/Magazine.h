#pragma once
#include <iostream>
using namespace std;

/*Журнал (Megazine), який містить наступні поля:
назва журналу;
ціна;
булівське поле, яке вказує чи журнал є новим: true – новий, false – ні.*/
class Magazine
{
	string className;
	string name;
	int price;
	bool type;
	static int counterMagazine;

public:
	Magazine();
	Magazine(string name, int price, bool type);

	void ShowInfo();
	static int GetCounterMagazine();
	string GetClassName();
	int GetPrice();

	~Magazine();
};

