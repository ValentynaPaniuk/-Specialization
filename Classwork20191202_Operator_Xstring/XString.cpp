#include "XString.h"
#include <iostream>
using namespace std;


XString::XString()
{
	cout << "Default constructor" << endl;
}

XString::XString(int size)
{
	this -> size = 40;
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
	
	cout << "Copy constructor " << this << endl;
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

XString & XString::operator*(const XString & other)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] == other.arr[i])
			cout << arr[i]<<" ";
	}

	return *this;
}

XString & XString::operator/(const XString & other)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->arr[i] != other.arr[i])
			cout << arr[i] << " ";
	}

	return *this;
}

XString & XString::operator+(const XString & other)
{
	char *arr3;
	int size1 = strlen(this->arr);
	int size2 = strlen(other.arr);
	
	cout << "SIZE this ARR1: " << size1 << endl;
	cout << "SIZE other ARR2: " << size2 << endl;
	int j = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (i < size1)
		{
			this->arr[i] = this->arr[i];
		}
		else 
		{
			this->arr[i] = other.arr[j];
		}
	}

	cout << "\n******************" << endl;
	for (int i = 0; i < 40; i++)
	{
		cout <<this->arr[i] <<" ";
	}
	cout << endl;

	return *this;
}



XString::~XString()
{
	arr = nullptr;
	delete[] arr;
	cout << "Default destructor" << endl;
}
