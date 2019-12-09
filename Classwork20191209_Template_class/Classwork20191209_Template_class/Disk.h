#pragma once
#include <iostream>
#include "CShop.h"

using namespace std;

/*Аудіо диск (Audio), який має містити наступні поля:
назва диску;
виконавець;
кількість треків;
ціна;
булівське поле, яке вказує чи аудіо диск є новим: true – новий, false – ні.
*/

class Disk
{
	string name;
	string singer;
	int number;
	double price;
	bool type;

	
public:
	Disk();
	Disk(string name, string singer, int number, double price, bool type);
	~Disk();
};

