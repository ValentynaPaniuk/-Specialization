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
	// Конструктор для класу Nodelist
	Nodelist()
	{
		this->head = nullptr;
		this->Size = 0;
	};

	//Метод, що повертає кількість контейнерів
	int GetSize()
	{
		return this->Size;
	};

	//Метод, що додає контейнер в кінець(додає елемент списту)
	void Push(T data)
	{
		//Перевірка чи він перший в списку
		if (this->head == nullptr)
		{
			this->head = new Conteiner<T>(data);

		}
		else
		{
			Conteiner<T> *tmp = this->head; //Створюємо об'єкт tmp 
			while (tmp->nextconteiner != nullptr)// Перевіряємо чи наступний контейнер не дорівнює Nullptr (кінець листа)
			{
				tmp = tmp->nextconteiner; // записується адреса наступного контейнеру в контейнер існуючий
			}
			tmp->nextconteiner = new Conteiner<T>(data);

		}
		this->Size++;

	};

	//Перегрузка оператора []

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
	//Створюємо об'єкт класу Nodelist
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