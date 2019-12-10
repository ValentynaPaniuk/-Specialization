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
	string className;
	string name;
	string singer;
	int number;
	int price;
	bool type;
	static int counterDisk;

	
public:
	Disk();
	Disk(string name, string singer, int number, int price, bool type);

	void Showinfo();
	static int GetCounterDisk();
	string GetClassName();
	int GetPrice();


	~Disk();
};

