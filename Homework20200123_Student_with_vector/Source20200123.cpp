#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*������� ���� �������(���, ����, ������ � 100-������ ������).

������������� ��� ����� �������� ������ � ����.
��������� ������� ���������� �������(����) �������� ��������� ������
��������� ������� ������ ����� �������(����).
������������ ������(���) �� ������� �������� �� ���������.
³���������� ������(���) �� ��������� ��������
������ ������� ��������, �� ����� ����������(��� &gt;=74)
C�������� ��������, �� ����� ���������� � ����� ���������(������, ��� �� ������)
���������� � ����� ��� �������� �������(����) �������� ����� �������� ����� ��
����������(partial_sort_copy).
�������� ���������� ��� �������� � ���������� ����
�������� ���������� ��� �������� � ����� � ���������*/

class Student
{
	string name;
	string surname;
	int course;
	int number;

public:
	Student() { cout << "Default constructor" << endl; };
	Student(string name, string surname, int course, int number)
	{
		this->name = name;
		this->surname = surname;
		this->course = course;
		this->number = number;
		cout << "Overload constructor" << endl;
	};
	void ShowInfo()
	{
		cout << "Course: " << this->course << " Name: " << this->name << " " << this->surname << "\tAverage: " << this->number << endl;
	};

	int GetNumber() { return this->number; }
	

	~Student() {

		cout << "Default destructor" << endl;
	};
};

int main()
{
	//Student student("Vania", "Petrov", 15, 10);
	//student.ShowInfo();


	vector<Student> Arr;
	Arr.push_back(Student("Vania", "Petrov", 15, 10));
	Arr.push_back(Student("Slava", "Ivanov", 11, 12));
	Arr.push_back(Student("Nastya", "Yerotska", 8, 8));

	/*for (vector<Student>::const_iterator i = Arr.begin(); i < Arr.end(); i++)
	{
		cout << Arr.<< endl;

	}*/


	/*for (int i = 0; i < Arr.size(); i++)
	{
		Arr.at(i).ShowInfo();
	}

	for (int i = 0; i < Arr.size(); i++)
	{
		if (Arr.at(i).GetNumber() < Arr.at(i + 1).GetNumber())
		{
			Arr.swap;
		}

	}


	cout << "After sorting ====>>>> " << endl;
	for (int i = 0; i < Arr.size(); i++)
	{
		Arr.swap;
	}
*/


	system("pause");
	return 0;
}