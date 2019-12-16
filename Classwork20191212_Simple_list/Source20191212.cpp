#include<iostream>
#include<string>
using namespace std;

//Обгортка над контейнером
template<typename T>
class Nodelist
{

private:

	//вкладений клас, який буде створювати один контейнер
	template <typename T>
	class Conteiner
	{

	public:
		Conteiner *nextconteiner; //вказівник на адресу наступного контейнера (next address)
		T data; //дані, що містяться в контейнері
		//Конструктор для класу Conteiner
		Conteiner(T data = T(), Conteiner *nextconteiner = nullptr)
		{
			this->data = data;
			this->nextconteiner = nextconteiner;
		};
	};


	//Виділяємо пам'ять під контейнер
	Conteiner<T> *head; // в цьому об'єктів будуть збурігатися адреси контейнерів
	int Size; // кількість контейнерів

public:
	//  Constructor for class Nodelist
	Nodelist()
	{
		this->head = nullptr;
		this->Size = 0;
	};

	//Metod dlia povernennia znachennia polia Size
	int GetSize()
	{
		return this->Size;
	};

	//Stvorenny conteynery (додає елемент списту)
	void Push(T data)
	{
		//Perevirka chy != nullprt
		if (this->head == nullptr)
		{
			this->head = new Conteiner<T>(data);

		}
		else
		{
			Conteiner<T> *tmp = this->head; //Stvoruiemo tymchasovyi masuv tmp 
			while (tmp->nextconteiner != nullptr)// Перевіряємо чи наступний контейнер не дорівнює Nullptr (кінець листа)
			{
				tmp = tmp->nextconteiner; // записується адреса наступного контейнеру в контейнер існуючий
			}
			tmp->nextconteiner = new Conteiner<T>(data);

		}
		this->Size++;

	};

	//Peregruzka operatora [] dlya dostupu do konkretnogo konteynera

	T &operator[] (const int index)
	{
		int counter = 0;
		Conteiner<T> *tmp = this->head;

		while (tmp != nullptr)
		{
			if (counter == index)
			{
				return tmp->data;
			}
			tmp = tmp->nextconteiner;
			counter++;
		}
	}


	



};


int main()
{
	//Stvoryuemo obekt list classy Nodelist
	Nodelist<int> list;

	cout << "Size = " << list.GetSize() << endl;
	list.Push(5);
	list.Push(6);
	list.Push(7);
	list.Push(8);
	
	cout << "Size = " << list.GetSize() << endl;
	cout <<"Data in conteiner number 0: " <<list[0] << endl;;


	system("pause");
	return 0;
}