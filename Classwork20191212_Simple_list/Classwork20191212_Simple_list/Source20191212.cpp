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
			this -> nextconteiner = nextconteiner;
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
				Conteiner<T> *current = this->head; //Створюємо об'єкт current 
				while (current->nextconteiner != nullptr)// Перевіряємо чи наступний контейнер не дорівнює Nullptr (кінець листа)
				{
					current = current->nextconteiner; // записується адреса наступного контейнеру в контейнер існуючий
				}
				current->nextconteiner = new Conteiner<T>(data);

			}
			this->Size++;

		};

		//Перегрузка оператора []


		

};


int main()
{
	//Створюємо об'єкт класу Nodelist
	Nodelist<int> list;
	
	cout << "Size = " << list.GetSize() << endl;
	list.Push(5);
	cout << "Counter N = >" << list.GetCounter() << endl;
	list.Push(3);
	cout << "Counter N = >" << list.GetCounter() << endl;
	list.Push(4);
	cout << "Counter N = >" << list.GetCounter() << endl;
	list.Push(6);
	cout << "Counter N = >" << list.GetCounter() << endl;
	cout << "Size = " << list.GetSize() << endl;



	system("pause");
	return 0;
}