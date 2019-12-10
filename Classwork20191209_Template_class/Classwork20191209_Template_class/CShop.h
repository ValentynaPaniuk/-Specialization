#pragma once
#include <iostream>
#include <string>
#include "Book.h"
#include "Disk.h"
#include "Magazine.h"

using namespace std;

template <typename T>
class CShop
{
	int size;
	T *arr;
	

public:
	CShop()
	{
		cout << "Default constructor arr" << this << endl;
	};
	CShop(int size) {
		this->size = size;
		this->arr = new T[this->size];
		for (int i = 0; i < this->size; i++)
		{
			arr[i];
		}

		cout << "Overload constructor arr" << this << endl;
	};
	
	void SortMaxMinElement()
	{
		int *tmp = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			tmp[i] = this->arr[i].GetPrice();
		}
		
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j<this->size; j++)
			{
				if (tmp[j] < tmp[j + 1])
				{
					swap(tmp[j], tmp[j + 1]);
				}
			}
		}
		
		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (tmp[i] == this->arr[j].GetPrice())
				{
					cout << this->arr[j].GetClassName() << " " << i + 1 << endl;
					this->arr[j].ShowInfo();
					cout << endl;
				}
			}
		}

		delete[]tmp;
		tmp = nullptr;
	};

	void ShowAll()
	{
		cout << "---------------------------------------------------------------" << endl;
		for (int i = 0; i < this->size; i++)
		{
			
			cout << this->arr[i].GetClassName() << " " << i + 1 << " : " << endl;
			this->arr[i].ShowInfo();
			
			cout << endl;
		}
		cout << "---------------------------------------------------------------" << endl;
	};


	void AveragePrice()
	{
		double summa = 0;

		for (int i = 0; i < this->size; i++)
		{
			summa += this->arr[i].GetPrice();
		}
		cout << "---------------------------------------------------------------" << endl;
		cout << this->arr[0].GetClassName() << "'s average price: " << double(summa) / double(this->size) << endl;
		cout << "---------------------------------------------------------------" << endl;
	};



	void SortMinMaxElement()
	{
		int *tmp = new int[this->size];
		for (int i = 0; i < this->size; i++)
		{
			tmp[i] = this->arr[i].GetPrice();
		}


		for (int i = 0; i < this->size; i++)
		{
			for (int j = this->size-1; j >= 0; j--)
			{
				if (tmp[j] < tmp[j - 1])
				{
					swap(tmp[j], tmp[j - 1]);
				}
			}
		}


		for (int i = 0; i < this->size; i++)
		{
			for (int j = 0; j < this->size; j++)
			{
				if (tmp[i] == this->arr[j].GetPrice())
				{
					
					cout << this->arr[j].GetClassName() << " " << i + 1 << endl;
					this->arr[j].ShowInfo();
					
					cout << endl;
				}
			}
		}

		delete[]tmp;
		tmp = nullptr;
	};


	void MostExpensive()
	{
		int max = 0;
		max = this->arr[0].GetPrice();
		for (int i = 0; i < this->size; i++)
		{
			if (max < this->arr[i].GetPrice())
			{
				max = this->arr[i].GetPrice();
			}
		}


		for (int i = 0; i < this->size; i++)
		{			
				if (this->arr[i].GetPrice() == max)
				{
					cout << "---------------------------------------------------------------" << endl;
					cout << "The most expensive: "<<this->arr[i].GetClassName()<<" :"<< endl;
					this->arr[i].ShowInfo();
					cout << "---------------------------------------------------------------" << endl;
					cout << endl;
				}
		}

	}

	void TheCheapest()
	{
		int min = 0;
		min = this->arr[0].GetPrice();

		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i].GetPrice() < min)
			{
					min = this->arr[i].GetPrice();
			}
		}

		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i].GetPrice() == min)
			{
				cout << "---------------------------------------------------------------" << endl;
				cout << "The cheapest price: " << this->arr[i].GetClassName() << " " << i + 1 << endl;
				this->arr[i].ShowInfo();
				cout << "---------------------------------------------------------------" << endl;
				cout << endl;
			}
		}
	}
	
	~CShop()
	{};
};

