#include <iostream>
#include <string>
using namespace std;
/*Написать программу, моделирующую работу автобусного парка. 
Сведения о каждом автобусе содержат: 
номер автобуса, 
фамилию и имя водителя, 
номер маршрута, 
количество мест в автобусе. 

Сформировать информацию об автобусах в виде бинарного дерева. 
Ключом для формирования дерева является номер автобуса. 
Программа должна:
■ Предоставить интерфейс типа «меню»; 
■ Выполнять поиск по указанному ключу; 
■ Выводить информацию о найденном автобусе на экран; 
■ Записать информацию об автобусах в упорядоченном виде в файл. */

struct Bus
{
	int data1;
	string data2;
	int data3;
	int data4;

	struct Bus*left;
	struct Bus*right;


};


Bus *CreateNewBus(int data1, string data2, int data3, int data4)
{
	Bus *newBus = new Bus();
	newBus->data1 = data1;
	newBus->data2 = data2;
	newBus->data3 = data3;
	newBus->data4 = data4;

	newBus->left = newBus->right = NULL;

	return newBus;

}

Bus *Insert(Bus *root, int data1, string data2, int data3, int data4)
{
	if (root == NULL)
	{
		root = CreateNewBus(data1, data2, data3, data4);
	}
	else if (data1 <= root->data1)
	{
		root->left = Insert(root->left, data1, data2, data3, data4);
	}
	else
	{
		root->right = Insert(root->right, data1, data2, data3, data4);
	}
	return root;
}


bool Search(Bus* bus, int data1) {
	if (bus == NULL) {
		return false;
	}
	else if (bus->data1 == data1) {
		return true;
	}
	else if (data1 <= bus->data1) {
		return Search(bus->left, data1);
	}
	else {
		return Search(bus->right, data1);
	}
}

void SearchIndex(Bus *bus)
{
	int number;
	cout << "Enter number for search: " << endl;
	cin >> number;
	if (Search(bus, number) == true)
	{
		cout << "Number " << number << " found" << endl;
	}
	else {
		cout << number << " Not found" << endl;
	}
}

void ShowInfo(Bus *root, int number)
{
	if (number == root->data1)
	{
		cout << "Info about bus N " << root->data1 << "\tDriver: " << root->data2 << "\tRoute number: " << root->data3 << "\tThenumber of seats on the bus: " << root->data4 << endl;

	}
}


int main()
{
	int number = 0;
	bool exit = false;
	Bus *root = NULL;
	root = Insert(root, 111, "Rivne-Lviv", 10, 34);
	root = Insert(root, 222, "Kyiv-Odesa", 11, 28);
	root = Insert(root, 123, "Kyiv-Odesa", 11, 28);
	root = Insert(root, 333, "Poltava-Ternopil", 12, 35);

	cout << "====  Menu ====== " << endl;
	cout << "1 - Find bus\n2 - Show info bus\n3 - White file info about bus" << endl;
	while (!exit)
	{
		cout << "Make your choice: ";
		cin >> number;
		switch (number)
		{
		case 1:
		{
			SearchIndex(root);
			break;
		}
		case 2:
		{
			break;
		}
		case 3:
		{
			break;
		}
		default:
			exit = true;
			break;
		}
	}

	
	
		
	




	system("pause");
	return 0;

}
