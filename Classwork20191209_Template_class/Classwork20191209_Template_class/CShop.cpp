#include "CShop.h"

using namespace std;




template<typename T>
CShop<T>::CShop()
{
	cout << "Default constructor arr" << this << endl;
}




template<typename T>
CShop<T>::CShop(T *&arr, int size)
{
	this->size = size;
	T *arr = new T[this->size];
	Book *book = new Book[size];
	Magazine *magazine = new Magazine[size];
	Disk *disk = new Disk[size];
	
		
	if (typeid(T).name() == typeid(Book).name())
	{
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = book[i].price;
		}
	}

	if (typeid(T).name() == typeid(Magazine).name())
	{
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = magazine[i].price;
		}
	}

	if (typeid(T).name() == typeid(Disk).name())
	{
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = disk[i].price;
		}
	}

	
	cout << "Overload constructor arr" << this << endl;
}







template<typename T>
CShop<T>::~CShop()
{
	this->arr = nullptr;
	delete[] this->arr;
}


