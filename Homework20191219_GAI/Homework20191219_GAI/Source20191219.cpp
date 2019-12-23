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

Node *Insert(Node *root, int data, string text) {
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
		cout << "Number of car: " << root->data <<"\tViolation: "<<root->text<< endl;
		return true;
	}
	else if (data <= root->data) {
		cout << "Number of car: " << root->data << "\tviolation: " << root->text << endl;
		return Search(root->left, data, text);
	}
	else {
		cout << "Number of car: " << root->data << "\tviolation: " << root->text << endl;
		return Search(root->right, data, text);
	}
}



void ShowInfo(Node* root, int data, string text) {
	if (root->data == data)
	{
		cout << "Number of car: " << root->data << "\tViolation: " << root->text << endl;

	}
	else if (data <= root->data)
	{
		cout << "Number of car: " << root->data << "\tviolation: " << root->text << endl;
	}
	else
	{
		cout << "Number of car: " << root->data << "\tviolation: " << root->text << endl;

	}
}




int main() {
	
	int number;
	string text;
	Node *root = NULL;
	root = Insert(root, 10, "Exceeded speed");
	root = Insert(root, 20, "Drove to the red");
	root = Insert(root, 30, "Did not miss the pedestrian");
	

	cout << "Enter number of car for search: " << endl;
	cin >> number;
	if (Search(root, number, text) == true) 
	{
		cout << "Number: " <<number << " Found" << endl;
	}
	else 
	{
		cout << number << " Not found" << endl;
	}
	cout << "********************************" << endl;

	


	system("pause");
	return 0;
}



