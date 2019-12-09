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
	string name;
	string publHouse;
	string author;
	double price;
	bool type;
public:
	Book();
	Book(string name, string publHouse, string author, double price, bool type);

	void ShowInfo();
	~Book();
};

