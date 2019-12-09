#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "Disk.h"
#include "Magazine.h"

using namespace std;

class AudioDisk;
class Book;
class Magazine;

template <typename T>
class CShop
{
	/*friend Book;
	friend Magazine;
	friend Disk;*/

	int size;
	T *arr;
	

public:
	CShop();
	CShop(T *&arr, int size);
	
	//MaxElement(T *&arr, int size);
	//MinElement(T *&arr, int size);
	//Sorting(T *&arr, int size);
	//Average(T *&arr, int size);





	~CShop();
};

