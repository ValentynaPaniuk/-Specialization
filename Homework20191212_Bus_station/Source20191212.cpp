#include <iostream>
#include <string>
using namespace std;

/*Побудувати клас для роботи з однозв’язним списком. Елемент списку містить наступну інформацію про автобус:

номер автобуса;
прізвище та ініціали водія;
номер маршруту.
Програма повинна забезпечувати:
початкове формування двох списків:
з даними про автобуси, які знаходяться в автопарку;
з даними про автобуси, які знаходяться на маршрутах.
При виїзді кождого автобуса з парку вводиться номер автобуса, і програма видаляє дані про цей автобус з списку автобусів, 
які знаходяться в автопарку, та записує ці дані в список автобусів, які знаходяться на маршруті.
аналогічна операція виконується для списків, якщо якийсь автобус повертається в автопарк;
по запиту видіються відомості про автобуси, які знаходяться в автопарку або на маршруті. 
*/


template <typename T>
class Station
{
public:
	//Constructor Station
	Station()
	{
		this->size = 0;
		this->head = nullptr;
		cout << "Default constructor Station" << this << endl;
	}
	// Destructor Station 
	~Station()
	{
		cout << "Destructor Station" << this << endl;
		DeleteFirst();
	}

	//Metor povernennia Size
	int GetSize()
	{
		return this->size;
	}

	//Metod stvorennia avtobusa na pochatok spyska
	void Push(T numberBus)
	{
		if (head == nullptr)
		{
			this->head = new Bus<T>(numberBus);
		}
		else
		{
			Bus<T> *tmp = this->head;
			while (tmp->nextBus!= nullptr)
			{
				tmp = tmp->nextBus;
			}
			tmp->nextBus = new Bus<T>(numberBus);
		}
		size++;
	}

	// Metod dodavannia odnogo avtobusa po indexy
	void Insert(T numberBus, const int index)
	{
		if (index == 0)
		{
			Pop(numberBus);
		}
		else
		{
			Bus<T> *prev = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->nextBus;
			}
			Bus<T> *newBus = new Bus<T>(numberBus, prev->nextBus);
			prev->nextBus = newBus;
			size++;
		}
	}

	//Metod dodavannia pershogo elementy
	void Pop(T numberBus)
	{
		head = new Bus<T>(numberBus, head);
		size++;
	}

	//Metod vydalyty za indeksom
	void RemoveByIndex(const int index)
	{
		if (index == 0)
		{
			DeleteFirst();
		}
		else
		{
			Bus<T> *prev = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->nextBus;
			}
			Bus<T> *toDel = prev->nextBus;
			prev->nextBus = toDel->nextBus;
			delete toDel;
			size--;
		}
	}

	//Metod peregruzky operatora []
	T &operator[](const int index)
	{
		int counter = 0;
		Bus<T> *bus = this->head;

		while (bus != nullptr)
		{
			if (bus == index)
			{
				return bus->numberBus;
			}
			bus = bus->nextBus;
			counter++;
		}
	}

	//Metod vydalennia pershogo elementa
	void DeleteFirst()
	{
		Bus<T> *tmp = head;
		head = head->nextBus;
		delete tmp;
		size--;
	}

	//Metod vyvody info about bus
	void ShowInfoAllBus(int size)
	{
		Bus<T> * tmp = head;
		for (int i = 0; i < size; i++)
		{
			tmp[i].ShowInfo();
		}
	}


private:
	template <typename T>
	class Bus
	{
	public:
		Bus *nextBus;
		T numberBus;
		string surname_driver;
		int route;
		//Constructor dlia Bus
		Bus(T numberBus = T(), Bus *nexBus = nullptr)
		{
			this->numberBus = numberBus;
			this->nextBus = nextBus;
			this->surname_driver = "Petrov";
			this->route = 852;

		}

		//Metod ShowInfo()
		void ShowInfo()
		{
			cout << "Number bus: " << numberBus << "\tSurname driver: " << this->surname_driver << "\tRoute: " << this->route << endl;
			system("pause");
		}

	};
	int size;
	Bus<T> *head;




};


int main()
{

	Station<int> bus1;

	int numberOfBuses = 0;

	
	

	cout << "Enter the number of buses: ";	 cin >> numberOfBuses;
	cout << "======================================" << endl;
	for (int i = 0; i < numberOfBuses; i++)
	{
		int value = 0; //znachennia dlia elementiv spysky
		cout << "Enter number of bus for number [" << i << "] element: "; cin >> value;
		bus1.Push(value);
	
	}

	bus1.ShowInfoAllBus(numberOfBuses);
	

	system("pause");
	return 0;
}