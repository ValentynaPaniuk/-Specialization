#include <iostream>
#include <string>
using namespace std;
/*Задание.
Реализовать базу данных ГАИ по штрафным квитанциям с помощью бинарного дерева. 
Ключом будет служить номер автомашины, значением узла — список правонарушений. 
Если квитанция добавляется в первый раз, то в дереве появляется новый узел, а в списке данные по правонарушению; 
если нет, то данные заносятся в существующий список. 

Необходимо также реализовать следующие операции:
•	 Полная распечатка базы данных (по номерам машин и списку правонарушений, числящихся за ними);
•	 Распечатка данных по заданному номеру;
•	 Распечатка данных по диапазону номеров.*/


struct Node {
	int data;
	string text;
	struct Node *left;
	struct Node *right;
		
};


Node *CreateNewNode(int data, string text) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->text = text;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *Insert(Node *root, int data, string text) 
{
	if (root == NULL) {
		root = CreateNewNode(data, text);
		
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data, text);
	}
	else {
		root->right = Insert(root->right, data, text);
	}

	return root;
}

bool Search(Node* root, int data, string text) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		cout << "Number of car1: " << root->data <<"\tViolation: "<<root->text<< endl;
		return true;
	}
	else if (data <= root->data) {
		return Search(root->left, data, text);
	}
	else {
		return Search(root->right, data, text);
	}
}

//кількість вузлів
size_t Count(Node* root, bool f = true)
{
	static size_t count;

	if (f)
		count = 1;

	if (root)
	{
		if ((root->left && !root->right) || (!root->left && root->right))
			++count;

		Count(root->left, false);
		Count(root->right, false);
	}

	return count;
}

//считает количество уровней в деревке моём :)(нужно для вывода деревка,чтобы знать на сколько уровней погружаться рекурсией)
void LEVEL(Node* root, int &i, int &max_level)
{
	if (root->left != NULL)
	{
		i++;
		if (max_level < i)
			max_level = i;
		LEVEL(root->left, i, max_level);
		i--;
	}
	if (root->right != NULL)
	{
		i++;
		if (max_level < i)
			max_level = i;
		LEVEL(root->right, i, max_level);
		i--;
	}
}

//выводит уровень № level у деревка :)
void display_level(Node* root, int &i, int level)
{
	if (i == level)
		cout <<"Car number: "<< root->data << "\tDescend: "<<root->text;
	if (root->left != NULL)
	{
		i++;
		display_level(root->left, i, level);
		i--;
	}
	if (root->right != NULL)
	{
		i++;
		display_level(root->right, i, level);
		i--;
	}
}


void display_all(Node* root)
{
	int i = 0;//нужна для сквозной нумерации уровня в рекурсиях.(по крайней мере моя башка не придумала ничего лучше этого костыля)
	int max_level = 0;
	LEVEL(root, i, max_level); //---узнаю максимальный уровень дерева
	/*cout << "max level = " << max_level << endl;*/
	
		cout << " ===   Full listing of the database === " << endl;
		for (int level = 0; level <= max_level; level++) //--цикл поочереди выводит каждый уровень девера, начиная с корня
		{
			/*if (level == 0)
				cout << "[ koren ] : ";
			else
				cout << "[" << level << " lvl] : ";*/
			display_level(root, i, level);//--функция вывода 1 уровня  дерева  
			cout << endl;
			
		}
		cout << "============================" << endl;
		
	
}



int main() {
	
	int number;
	int data;
	int count;
	bool f = true;

	bool exit = false;
	string text;
	int choice;

	Node *root = NULL;
	root = Insert(root, 10, "Exceeded speed");
	root = Insert(root, 20, "Drove to the red");
	root = Insert(root, 30, "Did not miss the pedestrian");
	root = Insert(root, 40, "Driving while intoxicated");

	count = Count(root, f);
	
		/*Полная распечатка базы данных (по номерам машин и списку правонарушений, числящихся за ними);
•	 Распечатка данных по заданному номеру;
•	 Распечатка данных по диапазону номеров.*/
	
		
		cout << "====== MENU ========" << endl;
		cout << "0 - EXIT\n1 - Full listing of the database\n2 - Printout of data for a given number\n3 - Number Range Printout" << endl;
		while (!exit)
		{
			cout << "Make your choice: ";
			cin >> choice;
			switch (choice)
			{
			case 0:
			{
				exit = true;
				break;
			}
			case 1:
			{
				display_all(root);
				break;
			}
			case 2:
			{
				cout << "Enter number of car for search: ";
				cin >> number;
				if (Search(root, number, text) == true)
				{
					cout << "This car is in the database" << endl;

				}
				else
				{
					cout << number << " Not found" << endl;
				}
				break;
			}
			case 3:
			{

				break;
			}
			default:
			{
				cout << "Error! Enter correct choice!";
			}
			}

		}
	system("pause");
	return 0;
}



