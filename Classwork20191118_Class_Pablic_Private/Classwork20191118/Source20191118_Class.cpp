# include <iostream>
# include <ctime>
# include <string>
# include <algorithm>
using namespace std;
/*ООП
Exercise 1
Завдання 1. Класна робота
Створити клас "Точка" (Point), який складається з двох полів типу int: X та Y. Необхідно забезпечити:
Введення координат точки користувачем
Вивід інформації про точку на екран
Можливість зміни будь-якої з координат на запит користувача (X або Y) */

class Point {
	int x, y;
	

public: //Модифікатори доступу - public, private, protected
	void ShowXY()
	{
		cout << "X = " << x << "\t Y = " << y << endl;
	}
	
	void AddKoordynaty(int newX=0,int newY=0)
	{
		x = newX;
		y = newY;
	}

};

/*Exercise 2
Написати клас "Банківський рахунок" (Account), який містить:
Номер рахунку
Розмір коштів на рахунку
Назва валюти рахунку (рублі, гривні, евро тощо), для позначення якої можна скористатись одним символом: R, G, E, $ тощо
Забезпечити можливість:
Відкривати рахунок та первинно вносити гроші на рахунок
Знімати гроші з рахунку
Докладати гроші на рахунок
ПРИМІТКА! На 12 балів реалізувати також можливість здійснювати переказ грошей з одного рахунку на другий.  */

class Account
{
	int account_number;
	double amountMoney;
	char currency;
	

public:
	void ShowInfo()
	{
		cout << "Number of account: " <<account_number<< " = " << amountMoney<<" "<<currency<<endl;
	}

	void AddAccount(int New_account_number, double newAmountMoney, char newCurrency)
	{
		account_number = New_account_number;
		amountMoney = newAmountMoney;
		currency = newCurrency;

	}

	void Money_transfer(Account newAccount1, Account newAccount2)
	{
		int choice;
		
		int choice_account1= 0;
		int choice_account2= 0;
		double choice_amoutMoney = 0;
		bool exit = false;
		while (!exit)
		{
			cout << "what types of banking transactions are you planning to do:\n1 - transfer funds from account to account;\n2 - withdraw money;\n3 - add money;\n4 - account status information\n0 - Exit" << endl;
			cin >> choice;

			if (choice == 1)
			{
				cout << "Enter the account number from which we will transfer funds: " << endl;
				cin >> choice_account1;
				cout << "Enter the account number where you will transfer the funds: " << endl;
				cin >> choice_account2;

				cout << "The currency in your account: " << newAccount1.account_number << " : " << newAccount1.currency << endl;
				cout << "The currency in your account:" << newAccount2.account_number << " : " << newAccount2.currency << endl;

				cout << "Enter how much you plan to transfer: " << endl;
				cin >> choice_amoutMoney;

				
				if (newAccount1.currency == newAccount2.currency)
				{
					if (choice_account1 == newAccount1.account_number && choice_account2 == newAccount2.account_number && choice_amoutMoney <= newAccount1.amountMoney)
					{
						newAccount1.amountMoney = newAccount1.amountMoney - choice_amoutMoney;
						newAccount2.amountMoney = newAccount2.amountMoney + choice_amoutMoney;
						newAccount1.ShowInfo();
						newAccount2.ShowInfo();
						system("pause");
					}
					else if (choice_account1 == newAccount2.account_number && choice_account2 == newAccount1.account_number && choice_amoutMoney <= newAccount2.amountMoney)
					{
						newAccount2.amountMoney = newAccount2.amountMoney - choice_amoutMoney;
						newAccount1.amountMoney = newAccount1.amountMoney + choice_amoutMoney;
						newAccount1.ShowInfo();
						newAccount2.ShowInfo();
						system("pause");
					}
					else
					{
						system("color 4");
						cout << "Please check the correct data entry" << endl;
					}
				}
				else
				{
					cout << "Currency accounts are different. You need to convert funds." << endl;

				}
			}
			else if (choice == 2)
			{
				cout << "Specify the account from which we will withdraw the money:  " << endl;
				cin >> choice_account1;
				cout << "How much money we will withdraw : " << endl;
				cin >> choice_amoutMoney;
				if (choice_account1 == newAccount1.account_number && choice_amoutMoney <= newAccount1.amountMoney)
				{
					newAccount1.amountMoney = newAccount1.amountMoney - choice_amoutMoney;
					newAccount1.ShowInfo();
				}
				else if (choice_account1 == newAccount2.account_number && choice_amoutMoney <= newAccount2.amountMoney)
				{
					newAccount2.amountMoney = newAccount2.amountMoney - choice_amoutMoney;
					newAccount2.ShowInfo();
				}
				else
				{
					cout << "Not enough money in the account" << endl;
				}

			}
			else if (choice == 3)
			{
				cout << "Please specify the account to which we will add the funds :  " << endl;
				cin >> choice_account1;
				cout << "How much money we will add: " << endl;
				cin >> choice_amoutMoney;
				if (choice_account1 == newAccount1.account_number && choice_amoutMoney <= newAccount1.amountMoney)
				{
					newAccount1.amountMoney = newAccount1.amountMoney + choice_amoutMoney;
					newAccount1.ShowInfo();
				}
				else if (choice_account1 == newAccount2.account_number && choice_amoutMoney <= newAccount2.amountMoney)
				{
					newAccount2.amountMoney = newAccount2.amountMoney + choice_amoutMoney;
					newAccount2.ShowInfo();
				}

			}
			else if (choice == 4)
			{
				newAccount1.ShowInfo();
				newAccount2.ShowInfo();
			}

			else if (choice == 0)
			{
				cout << "Exit" << endl;
				exit = true;
			}
		}
		
	}
};



int main()
{
	srand(unsigned(time(NULL)));

	//Exercise 1
	cout << "Exercise 1: " << endl;
	int newX = 0;
	int newY = 0;
	cout << "Enter X and Y " << endl;
	cin>>newX>>newY;

	Point krapka;
	
	krapka.AddKoordynaty(newX, newY);
	krapka.ShowXY();

	//Exercise 2

	cout << "Exercise 2: " << endl;
	Account newAccount1;
	int New_account_number = rand() % 1000000 + 1500000;
	double newAmountMoney=0;
	char newCurrency;
	cout << "============ Account number 1 ===============" << endl;
	cout << "Your account number 1: " << New_account_number << endl;
	cout << "What amount of money do you have to deposit ? " << endl;
	cin >> newAmountMoney;
	cout << "In what currency do you deposit money (g - gryvnya, $ - dolar, r - rubl)? " << endl;
	cin >> newCurrency;
	newAccount1.AddAccount(New_account_number, newAmountMoney, newCurrency);
	newAccount1.ShowInfo();
	cout << "\n============ Account number 2 ===============" << endl;
	Account newAccount2;
	int New_account_number2 = rand() % 1000000 + 1500000;
	double newAmountMoney2 = 0;
	char newCurrency2;
	cout << "Your account number 2: " << New_account_number2 << endl;
	cout << "What amount of money do you have to deposit ? " << endl;
	cin >> newAmountMoney2;
	cout << "In what currency do you deposit money (g - gryvnya, $ - dolar, r - rubl)? " << endl;
	cin >> newCurrency2;
	newAccount2.AddAccount(New_account_number2, newAmountMoney2, newCurrency2);
	newAccount2.ShowInfo();
	cout << "\n============ Banking transactions: ===============" << endl;
	newAccount1.Money_transfer(newAccount1, newAccount2);
	



	system("pause");
	return 0;
}
