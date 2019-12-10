#pragma once
#include <string>
//#include "CShop.h"
using namespace std;

//class CShop;
/*Книгa (Book), яка містить наступні поля:
назва книги;
видавництво;
автор;
ціна;
булівське поле, яке вказує чи книга є нова: true – нова, false – ні.*/

class Book
{
	string className;
	string name;
	string publHouse;
	string author;
	int price;
	bool type;
	static int counterBook;
public:
	Book();
	Book(string name, string publHouse, string author, int price, bool type);

	void ShowInfo();
	int GetPrice();
	string GetClassName();
	static int GetCounterBook();

	~Book();
};

