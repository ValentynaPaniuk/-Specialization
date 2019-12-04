#include "XString.h"
#include <iostream>
using namespace std;


XString::XString()
{
	for (int i=0; i<80; i++)
	{
		this->arr[i] = ' ';
	}
	cout << "Default constructor" <<this<< endl;
}

XString::XString(char arr[])
{
	for (int i = 0; i < strlen(arr) + 1; i++)
	{
		this->arr[i] = arr[i];
	}
	cout << "Overload constructor " << this << endl;
}



XString::XString(XString & other)
{
	for (int i = 0; i < strlen(arr); i++)
	{
		this->arr[i] = other.arr[i];
	}
	
	cout << "Copy constructor " << this << endl;
}

void XString::ShowInfoRow()
{
	cout << "\nSIZE SHOW INFO= " << strlen(this->arr) << endl;
	cout << "Row: ";
	for (int i = 0; i < strlen(this->arr); i++)
	{
		cout << this->arr[i];
	}
	cout << endl;
	cout << "SIZE SHOW INFO= " << strlen(this->arr) << endl;
	
}

XString XString::operator*= (XString & other)
{
	char tmp[80] = {};
	int counter = 0;

	for (int i = 0; i < strlen(this->arr); i++)
	{
		for (int j = 0; j < strlen(other.arr); j++)
		{
			if (this->arr[i] == other.arr[j])
			{
				tmp[counter] = this->arr[i];
				counter++;
			}
		}
	}
	cout << "Identical letters: " << endl;
	for (int i = 0; i < strlen(tmp); i++)
	{
		cout << tmp[i] << " ";
	}
	cout << endl;

	return tmp;
}

XString XString::operator/=(const XString & other)
{
	char tmp[80] = {};
	int counter = 0;

	for (int i = 0; i < strlen(this->arr); i++)
	{
		int counter1 = 0;
		for (int j = 0; j < strlen(other.arr); j++)
		{
			if (this->arr[i] != other.arr[j])
			{
				counter1++;
			}
			if (counter1 == strlen(other.arr))
			{
				tmp[counter] = this->arr[i];
				counter++;
			}
		}
	}
	cout << "Different letters: " << endl;
	for (int i = 0; i < strlen(this->arr); i++)
	{
		cout << tmp[i] << " ";
	}
	cout << endl;
	
	return tmp;
}

XString XString::operator+(const XString & other)
{
	char arr3[80] = {};
	int j = 0;
	int size1 = strlen(this->arr);
	int size2 = strlen(other.arr);
	
	cout << "SIZE this ARR1: " << size1 << endl;
	cout << "SIZE other ARR2: " << size2 << endl;
	
	for (int i = 0; i < size1+size2; i++)
	{
		if (i < size1)
		{
			arr3[i] = this->arr[i];
		}
		else 
		{
			arr3[i] = other.arr[j];
			j++;
		}
	}

	cout << "\n******************" << endl;
	for (int i = 0; i < strlen(arr3); i++)
	{
		cout <<arr3[i] <<" ";
	}
	cout << endl;

	return *this;
}



XString::~XString()
{
	cout << "Default destructor" << endl;
}
