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
		root->right = Insert(root->left, data1, data2, data3, data4);
	}
	return root;
}


bool Search(Bus *root, int data1)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data1 == data1)
	{
		return true;
	}
	else if (data1 <= root->data1)
	{
		return Search(root->left, data1);
	}
	else
	{
		return Search(root->right, data1);
	}
}





int main()
{
	int number = 0;
	string data2;
	int data3;
	int data4;
	Bus *root = NULL;
	root = Insert(root, 111, "Rivne-Lviv", 10, 34);
	root = Insert(root, 222, "Kyiv-Odesa", 11, 28);
	root = Insert(root, 333, "Poltava-Ternopil", 12, 35);

	cout << "Enter number for search: " << endl;
	cin >> number;
	if (Search(root, number) == true)
	{
		cout << "Number "<<number<<" found" << endl;
	}
	else {
		cout << number << " Not found" << endl;
	}

	system("pause");
	return 0;

}
