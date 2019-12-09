#include "CShop.h"

using namespace std;




template<typename T>
CShop<T>::CShop()
{
};

template<typename T>
CShop<T>::CShop(T *& arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
		this->size = size;
	}
}







template<typename T>
CShop<T>::~CShop()
{
	this->arr = nullptr;
	delete[] this->arr;
}


