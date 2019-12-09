#pragma once
#include <iostream>
using namespace std;

/*Журнал (Megazine), який містить наступні поля:
назва журналу;
ціна;
булівське поле, яке вказує чи журнал є новим: true – новий, false – ні.*/
class Magazine
{
	string name;
	double price;
	bool type;

public:
	Magazine();
	Magazine(string name, double price, bool type);
	~Magazine();
};

