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


template <typename T1, typename T2, typename T3>
class Station
{
private:

	template <typename T1, typename T2, typename T3>
	class Bus
	{
	public:
		Bus *nextBus;
		T1 numberBus;
		T2 surname_driver;
		T3 route;

		//Default constructor
		Bus() {
			cout << "Default constructor Bus " << this << endl;
		};

		//Constructor dlia Bus
		Bus(T1 numberBus, T2 surname_driver, T3 route, Bus *nexBus = nullptr)
		{
			this->numberBus = numberBus;
			this->nextBus = nextBus;
			this->surname_driver = surname_driver;
			this->route = route;
			cout << "Overload constructor Bus " << this << endl;

		}

			

	};

	
	Bus <T1, T2, T3> *head;
	int size;


public:

	
	//Constructor Station
	Station()
	{
		this->size = 0;
		this->head = nullptr;
		cout << "Default constructor Station " << this << endl;
	}
	

	//Metor povernennia Size
	int GetSize()
	{
		return this->size;
	}

	//Metod stvorennia avtobusa na pochatok spyska
	void Push(T1 numberBus, T2 surname_driver, T3 route)
	{
		if (head == nullptr)
		{
			this->head = new Bus<T1, T2, T3>(numberBus, surname_driver, route);
		}
		else
		{
			Bus<T1, T2, T3> *tmp = this->head;
			while (tmp->nextBus != nullptr)
			{
				tmp = tmp->nextBus;
			}
			tmp->nextBus = new Bus<T1, T2, T3>(numberBus, surname_driver, route);
		}
		this->size++;
	}

	// Metod dodavannia odnogo avtobusa po indexy
	void Insert(T1 numberBus, T2 surname_driver, T3 route, const int index)
	{
		if (index == 0)
		{
			Pop(numberBus, surname_driver, route);
		}
		else
		{
			Bus<T1, T2, T3> *prev = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->nextBus;
			}
			Bus<T1, T2, T3> *newBus = new Bus<T1, T2, T3>(numberBus, surname_driver, route, prev->nextBus);
			prev->nextBus = newBus;
			size++;
		}
	}

	//Metod dodavannia pershogo elementy
	void Pop(T1 numberBus, T2 surname_driver, T3 route)
	{
		head = new Bus<T1, T2, T3>(numberBus, surname_driver, route, head);
		this->size++;
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
			Bus<T1, T2, T3> *prev = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->nextBus;
			}
			Bus<T1, T2, T3> *toDel = prev->nextBus;
			prev->nextBus = toDel->nextBus;
			delete toDel;
			size--;
		}
	}

	//Metod peregruzky operatora []
	T1 &operator[](const int index)
	{
		int counter = 0;
		Bus<T1, T2, T3> *bus = this->head;

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
		Bus<T1, T2, T3> *tmp = this->head;
		this->head = head->nextBus;
		delete tmp;
		size--;
	}

	//Metod vyvodu na ekran
	void ShowInfo()
	{
		Bus<T1, T2, T3> *tmp = head;
		int counter = 0;
	
		while (tmp != nullptr)
		{
			cout << "Bus N " << counter + 1 << ": " << endl;
			cout << "Bus's number: " << tmp->numberBus << "\tSurname drivers: " << tmp->surname_driver << "\tRoute: " << tmp->route << endl;
			tmp = tmp->nextBus;
			counter++;
		}
		//cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl;
	}

	// Metod 
	void Transfer(const int index, Station &other)
	{
		if (index == 0)
		{
			other.Pop(this->head->numberBus, this->head->surname_driver, this->head->route);
			DeleteFirst();
		}

		else
		{
			Bus<T1, T2, T3> *prev = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->nextBus;
			}
			Bus<T1, T2, T3> *toDel = prev->nextBus;
		
			other.Pop(toDel->numberBus, toDel->surname_driver, toDel->route);
			prev->nextBus = toDel->nextBus;
			delete toDel;
			this->size--;
			
		}
	}

	// Destructor Station 
	~Station()
	{
		DeleteFirst();
		cout << "Default destructor Station " << this << endl;
	}
	

};


int main()
{

	Station<int, string, int> stationList;
	Station<int, string, int> wayList;

	int numberOfBuses = 0;
	int number = 0; //znachennia dlia elementiv spysky
	string surname;
	int route;
	int remoweNumber;
	
	
	cout << "Enter the number of buses: ";	 cin >> numberOfBuses;
	cout << "======================================" << endl;
	for (int i = 0; i < numberOfBuses; i++)
	{
		cout << "====================================================" << endl;
		cout << "Add information about bus N [" << i + 1 << "]" << endl;
		cout << "Enter number of bus for number: ";					cin >> number;
		cout << "Enter surname of driver bus number: ";				cin >> surname;
		cout << "Enter route of bus number: ";						cin >> route;
		cout << "====================================================" << endl;
		stationList.Push(number, surname, route);
	}

	stationList.ShowInfo();
	//wayList.ShowInfo();
	cout << "Renowe Number: " << endl;
	cin >> remoweNumber;
	stationList.Transfer(remoweNumber-1, wayList);
	cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl;
	cout << "************Way List ====>>>>>> " << endl;
	wayList.ShowInfo();
	cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl;
	cout << "************Station List ====>>>>>> " << endl;
	stationList.ShowInfo();
	cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+" << endl;

	system("pause");
	return 0;
}