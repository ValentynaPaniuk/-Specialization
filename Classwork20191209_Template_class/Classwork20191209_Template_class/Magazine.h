#pragma once
#include <iostream>
using namespace std;
class CShop;
/*Журнал (Megazine), який містить наступні поля:
назва журналу;
ціна;
булівське поле, яке вказує чи журнал є новим: true – новий, false – ні.*/
class Magazine
{
	friend CShop;
	string name;
	double price;
	bool type;

public:
	Magazine();
	Magazine(string name, double price, bool type);
	~Magazine();
};

