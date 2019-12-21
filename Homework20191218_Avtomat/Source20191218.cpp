#include<iostream>
#include<string>
#include<ctime>
#include<conio.h>
#include<Windows.h>

using namespace std;
/*�������� 1
�������� �������� � ������ ������� - �������, �������, ����.
����� ���� �������������� (��������� ��������� � ��� ������� �������� ����������
� ����������� �����) � �쳺 ����������� � ������� � ����� � ��������� 70%. �����
���� � ������� �� ��������� �����.

������� ����������� � ������ �����, ������ 30 ����� � �쳺:
o ��������� ���� (������ ���� &quot;�������&quot;)
o �������� ���� (������)

������� �쳺:
o �������� �������(����� ����� �������� �������� � �������)
o ������� - ��������� ������� ���� 1 ����, �, ���� ���, ��������� ���� ����������
(���� ��� ����� �����, �� ������, � ������� ��������� ��������� &quot;������&quot; )
��� ������ � ������� �� ���������� ����������� ������ ����:
������� ��������� ���� 5, � �����������.
������� ��������� ���� 6, � ������.*/
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