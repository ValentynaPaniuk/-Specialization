#include "XString.h"
#include <iostream>
using namespace std;


XString::XString()
{
	cout << "Default constructor" << endl;
}

XString::XString(int size)
{
	
	this -> size = 80;
	this->arr = new char[this->size];
	cout << "Enter text (constructor):" << endl;
	for (int i = 0; i < this->size; i++)
	{
		cin >> arr[i];
		if (int(this->arr[i]) == 46)
		{
			break;
		}
	}
	cout << "\nOverload constructor " << this << endl;
	cout << "Constructor SIZE: " << strlen(this->arr) << endl;
}

XString::XString(XString &other)
{
	this->size = other.size;
	this->arr = other.arr;
	
	cout << "Copy constructor" << this << endl;
}

void XString::ShowInfoRow()
{
	cout << "\nSIZE SHOW INFO= " << strlen(this->arr) << endl;
	cout << "Row: " << endl;
	for (int i = 0; i < strlen(this->arr); i++)
	{
		cout << this->arr[i];
	}
	cout << endl;
	cout << "SIZE SHOW INFO= " << strlen(this->arr) << endl;
	
}



XString::~XString()
{
	arr = nullptr;
	delete[] arr;
	cout << "Default destructor" << endl;
}
