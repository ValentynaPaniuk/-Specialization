#pragma once
#include <iostream>
#include <string>

using namespace std;

template <typename T>
class CShop
{
	int size;
	T *arr = new T arr[size];

public:
	CShop();
	CShop(T *&arr, int size);
	
//	MaxElement(T *&arr, int size);
	//MinElement(T *&arr, int size);
	//Sorting(T *&arr, int size);
	//Average(T *&arr, int size);





	~CShop();
};

