#include<iostream>
#include<string>
using namespace std;

//�������� ��� �����������
template<typename T>
class Nodelist
{

private:

	//��������� ����, ���� ���� ���������� ���� ���������
	template <typename T>
	class Conteiner
	{

	public:
		Conteiner *nextconteiner; //�������� �� ������ ���������� ���������� (next address)
		T data; //���, �� �������� � ���������
		//����������� ��� ����� Conteiner
		Conteiner(T data = T(), Conteiner *nextconteiner = nullptr)
		{
			this->data = data;
			this->nextconteiner = nextconteiner;
		};
	};


	//�������� ���'��� �� ���������
	Conteiner<T> *head; // � ����� ��'���� ������ ���������� ������ ����������
	int Size; // ������� ����������

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

	//Stvorenny conteynery (���� ������� ������)
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
			while (tmp->nextconteiner != nullptr)// ���������� �� ��������� ��������� �� ������� Nullptr (����� �����)
			{
				tmp = tmp->nextconteiner; // ���������� ������ ���������� ���������� � ��������� ��������
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
	}


	



};


int main()
{
	//Stvoryuemo obekt list classy Nodelist
	Nodelist<int> list;

	cout << "Size = " << list.GetSize() << endl;
	list.Push(5);
	list.Push(6);
	list.Push(7);
	list.Push(8);
	
	cout << "Size = " << list.GetSize() << endl;
	cout <<"Data in conteiner number 0: " <<list[0] << endl;;


	system("pause");
	return 0;
}