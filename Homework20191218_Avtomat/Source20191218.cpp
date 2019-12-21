#include<iostream>
#include<string>
#include<ctime>
#include<conio.h>
#include<Windows.h>

using namespace std;
/*Завдання 1
Напишіть програму з трьома класами - автомат, магазин, набій.
Кожен набій пронумерований (нумерація послідовна і при запуску програми починається
з випадкового числа) і вміє вистрілювати і влучати в мішень з імовірністю 70%. Кожен
набій у програмі має унікальний номер.

Магазин реалізований у вигляді стеку, містить 30 набоїв і вміє:
o заряджати набій (отримує його &quot;готовим&quot;)
o віддавати набій (верхній)

Автомат вміє:
o прийняти магазин(тобто можна змінювати магазини у автоматі)
o стріляти - попросити магазин дати 1 набій, і, якщо дав, попросити набій вистрелити
(набій при цьому скаже, чи влучив, а автомат передасть результат &quot;нагору&quot; )
При пострілі в консоль має виводитись повідомлення такого типу:
Автомат вистрелив кулю 5, і промахнувся.
Автомат вистрелив кулю 6, і влучив.*/
class Magazine
{
	class Bullet
	{
	public:
		Bullet *pNext;
		int number;
		Bullet(int number, Bullet *pNext = nullptr)
		{
			this->pNext = pNext;
			this->number = number;
		}
	};
	Bullet *head;
	int size;

public:
	Magazine()
	{
		this->head = head;
		this->size = 0;
	};

	void Push()
	{
		if (head == nullptr)
		{
			head = new Bullet(rand() % 10 + 1);
			this->size++;
		}
		else
		{
			Bullet *current = this->head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Bullet(current->number + 1);
			this->size++;
		}
	}


	void DeleteFirst()
	{
		Bullet *tmp = head;
		head = head->pNext;
		delete tmp;
		this->size--;
	}

	int GetSize()
	{
		return this->size;
	}

	bool operator[](int index)
	{
		int counter = 0;
		Bullet *current = this->head;
		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->number;
				current = current->pNext;
				counter++;
			}
		}
	}

	~Magazine()
	{

	};
};


class Avtomat
{
	Magazine magazine;

public:
	void Fire()
	{
		if (magazine.GetSize() > 0)
		{
			magazine.DeleteFirst();
			int hit = rand() % 10 + 1;
			if (hit > 0 && hit < 7)
			{
				cout<< "The machine gun fired from bullet " << magazine[0] << " and hit." << endl;
				this->ShowInfoAboutMagazine();
			}
			else
			{
				cout << "The machine gun fired from bullet " << magazine[0] << " and missed." << endl;
				this->ShowInfoAboutMagazine();
			}
		}
		else 
		{
			cout << "Magazine is empty, press R for reload." << endl;
				for (;;) 
				{
					char reload = _getch();
					if (reload == 'r' || reload == 'R') 
					{
					this->Reload();
					break;
					}
				}
		}
	}



	void ShowInfoAboutMagazine() {
		cout << "There are " << magazine.GetSize() << " bullets." << endl;
	}

	void Reload() {
		cout << "Reloading..." << endl;
		for (int i = magazine.GetSize(); i < 30; i++) {
			magazine.Push();
		}
		Sleep(2000);
		cout << "Reload complete!" << endl;
	}


};

int main()
{

	srand(unsigned(time(NULL)));

	Avtomat avtomat;
	bool exit = false;

	cout << "==== MENU AVTOMAT ==== " << endl;
	while (!exit) {
		cout << "0. Exit\n1. Firing machine gun\n2. Charge the charge\n3. Show info about avtomat\n";
		char choice;
		//choice = _getch();
		cin >> choice;
		switch (choice) {
		case '0':
			exit = true;
			break;
		case '1':
			avtomat.Fire();
			break;
		case '2':
			avtomat.Reload();
			break;
		case '3':
			avtomat.ShowInfoAboutMagazine();
			break;
		default:
			cout << "Incorrect value. Try again" << endl;
		}

		cout << endl;
	}


	system("pause");
	return 0;
}