#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
	int minValue();
	Node* remove(int value, Node *parent);

};


Node *CreateNewNode(int data) {
	Node *newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *Insert(Node *root, int data) {
	if (root == NULL) {
		root = CreateNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}

	return root;
}

bool Search(Node* root, int data) {
	if (root == NULL) {
		return false;
	}
	else if (root->data == data) {
		return true;
	}
	else if (data <= root->data) {
		return Search(root->left, data);
	}
	else {
		return Search(root->right, data);
	}
}


Node* Node::remove(int x, Node *root) {

	if (x < this->data) {
		if (left != NULL)
			return left->remove(x, this);
		else
			return NULL;
	}
	else if (x > this->data) {
		if (right != NULL)
			return right->remove(x, this);
		else
			return NULL;
	}
	else {
		if (left != NULL && right != NULL) {
			this->data = right->minValue();
			return right->remove(this->data, this);
		}
		else if (root->left == this) {
			root->left = (left != NULL) ? left : right;
			return this;
		}
		else if (root->right == this) {
			root->right = (left != NULL) ? left : right;
			return this;
		}
	}
}

int Node::minValue() {

	if (left == NULL)
		return data;
	else
		return left->minValue();

}





int main() {
	int number;
	int number2;
	Node *root = NULL;
	root = Insert(root, 50);
	root = Insert(root, 20);
	root = Insert(root, 23);
	root = Insert(root, 60);
	for (;;)
	{
		cout << "Enter number for search: " << endl;
		cin >> number;
		if (Search(root, number) == true)
		{
			cout << "Number: " << number << " Found" << endl;
		}
		else
		{ 
			cout << number << " Not found" << endl; 
		}

		if (Search(root, number) == true)
		{
			int choice;
			cout << "Do You want to delete number (1- Yes, 2 - No): " << endl;
			cin >> choice;
			if (choice == 1)
			{
				root->remove(number, root);
			}
			else
			{
				cout << "Keep looking for the number" << endl;
			}
				
		}
		
	}



	system("pause");
	return 0;
}

