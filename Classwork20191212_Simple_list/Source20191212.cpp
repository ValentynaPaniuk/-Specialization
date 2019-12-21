#include<iostream>
#include<string>
using namespace std;

//Obgortka nad konteynerom
template<typename T>
class Nodelist
{



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
			while (tmp->nextconteiner != nullptr)// Pereviriaemo chu nastupnyi conteyner ne Nullptr (kinec lista)
			{
				tmp = tmp->nextconteiner; // zapysuemo address naxt conteiner v isnuyuchyi conteiner
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
	};

	//Metod vydalennia pershogo conteinera
	void DeleteFirst()
	{
		Conteiner<T> *tmp = head;
		head = head->nextconteiner;
		delete tmp;
		this->Size--;
	};

	//Metod vydalennia vsih conteineriv
	void ClearList()
	{
		while (Size)
		{
			DeleteFirst();
		}
	};

	//Vstavka elementa
	void Insert(T data, const int index)
	{
		if (index == 0)
		{
			Pop(data);
		}

		else
		{
			Conteiner<T> *prev = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->nextconteiner;
			}
			Conteiner<T> *newConteiner = new Conteiner<T>(data, prev->nextconteiner);
			prev->nextconteiner = newConteiner;
			this->Size++;
		}
	};

	//Dodaty pershyi conteiner
	void Pop(T data)
	{
		head = new Conteiner<T>(data, head);
		this->Size++;
	}

	//Vydalennia po index conteinera
	void RemoveByIndex(const int index)
	{
		if (index == 0)
		{
			DeleteFirst();
		}
		else
		{
			Conteiner<T> *prev = this->head;
			for (int i = 0; i < index - 1; i++)
			{
				prev = prev->nextconteiner;
			}
			Conteiner<T> *toDel = prev->nextconteiner;
			prev->nextconteiner = toDel->nextconteiner;
			delete toDel;
			this->Size--;
		}
	
	}

	//Destructor Nodelist
	~Nodelist()
	{
		cout << "Destructor Nodelist " << this << endl;
		DeleteFirst();
	};


private:

	//вкладений клас, який буде створювати один контейнер
	template <typename T>
	class Conteiner
	{

	public:
		Conteiner *nextconteiner; //vkazivnyk na adresy nastypnogo konteinera (next address)
		T data; //dani, sho e v konteyneri
		//Construktor dlya klasy Conteiner
		Conteiner(T data = T(), Conteiner *nextconteiner = nullptr)
		{
			this->data = data;
			this->nextconteiner = nextconteiner;
		};
	};

	//Vydilyaemo pamyat pid conteiner
	Conteiner<T> *head; // v obekti zberigauitsia dani pro adress conteinera
	int Size; /* kilkist conteyneriv*/
};


int main()
{
	Nodelist<int> list;
	int containersCount = 0;
	cout << "How many number do you want to use? " << endl;
	cin >> containersCount;
	cout << "==========================================" << endl;

	for (int i = 0; i < containersCount; i++) {
		int choice = 0;
		cout << "Enter " << i << " element: " << endl;
		cin >> choice;
		list.Push(choice);
	}

	for (int i = 0; i < list.GetSize(); i++) {
		cout << "Elem[" << i << "] = " << list[i] << endl;
	}


	cout << "List size =====> " << list.GetSize() << endl;
	list.DeleteFirst();
	cout << "After delete first conteiner=> " << endl;
	cout << "List size =====> " << list.GetSize() << endl;
	cout << "Testing Pop =====>" << endl;
	list.Pop(22);
	list.Pop(123);
	list.Pop(231);
	cout << "Testing Pop" << endl;
	for (int i = 0; i < list.GetSize(); i++) {
		cout << "Elem[" << i << "] = " << list[i] << endl;
	}
	cout << "Before insert ";
	list.Insert(1001, 1);
	cout << list[1] << endl;
	cout << "After insert ============================" << endl;

	for (int i = 0; i < list.GetSize(); i++) {
		cout << "Elem[" << i << "] = " << list[i] << endl;
	}
	cout << "List size =====> " << list.GetSize() << endl;

	cout << "Remove by index #########################" << endl;
	list.RemoveByIndex(5);
	cout << list[1] << endl;
	cout << "Remove by index " << endl;

	for (int i = 0; i < list.GetSize(); i++) {
		cout << "Elem[" << i << "] = " << list[i] << endl;
	}
	cout << "List size =====> " << list.GetSize() << endl;
	/*cout << "Clear list: " << endl;*/
	/*list.ClearList();
	cout << "List size =====> " << list.GetSize() << endl;*/



	system("pause");
	return 0;
}