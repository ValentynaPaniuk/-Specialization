#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*Описати клас Студент(ім’я, курс, оцінка у 100-бальній системі).

Перевизначити для класу оператор виводу у потік.
Визначити функцію заповнення вектору(деку) студентів довільними даними
Визначити функцію виводу вмісту вектору(деку).
Впорядкувати вектор(дек) за іменами студентів по зростанню.
Відсортувати вектор(дек) за прізвищами студентів
Знайти кількість студентів, що добре навчаються(бал &gt;=74)
Cкопіювати студентів, що добре навчаються у інший контейнер(вектор, дек чи список)
Встановити у перші три елементи вектору(деку) студентів самих молодших курсів за
зростанням(partial_sort_copy).
Зберегти інформацію про студентів у текстовому файлі
Почитати інформацію про студентів з файлу у контейнер*/

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