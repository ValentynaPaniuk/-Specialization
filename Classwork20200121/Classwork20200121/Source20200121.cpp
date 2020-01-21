#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*ООП
Написати програму, яка дозволяє записувати в файл інформацію про результати сесії (оцінки) певної групи студентів. 
Організувати зчитування даної інформації з файлу та підрахунок середнього балу в групі.
Використайте, розроблені в уроці 6 класи Group ("Група") та Student ("Студент"). 
Додати методи Save() та Read() для запису та зчитування обєктів в/з файла.
Додаткове необов'язкове завдання (додаткових 12 балів)
Написати програму, яка виводить статистику по вказаному користувачем файлу в наступному вигляді:
кількість коротких слів (який складається максимум з 10 символів);
кількість великих слів;
кількість цифр;
кількість символів пунктуації, наприклад, (!), (,), (.), (-).
Крім того, у відповідь на написанення довільної клавіши або на певний пункт меню, здійснити заміну всіх цифр в файлі на символи (*), 
а додатково (на 12 балів) зробити видалення всіх символів пунктуації. */



class Student
{
	string name;
	string surname;
	unsigned int age;
	unsigned int ID;
	float average;

public:

	static unsigned int Counter;
	// Constructor
	Student() {
		Counter++;
		this->ID = Counter;
		cout << "Default constructor"<<this << endl;  }
	Student(string name, string surname, int age)
	{

		this->name = name;
		this->surname = surname;
		this->age = age;
		Counter++;
		this->ID = Counter;
		cout << "Overload constructor. STUDENT" << endl;
	};


	//Metody);
	int GetID()						{ return ID; };
	void SetName(string name)		{ this->name = name; };
	string GetName()				{ return name; };
	void SetSurname(string surname) { this->surname = surname; };
	string GetSurname()				{ return surname; };
	void SetAge(int age)			{ this->age = age; };
	int GetAge()					{ return age; };
	float GetAverage()				{ return average; }


	void FillStudent()
	{
		cout << "Student ID=> " << ID << endl;
		cout << "Enter Name student: ";
		cin >> this->name;
		cout << "Enter Surname student: ";
		cin >> this->surname;
		cout << "Enter Age student: ";
		cin >> this->age;
	};


	void ShowInfoStudent()
	{
		cout << name << " " << surname << " Age: " << age << endl;
		Average();


	};

	float Average() {
		int summagrades = 0;
		for (int i = 0; i < 5; i++)
		{
			int grades = rand() % 12 + 1;
			cout << "Grades " << i + 1 << " = " << grades << "; ";
			summagrades += grades;
			average = summagrades / 5;

		}
		cout << "                                Average score: " << average << endl;
		return average;
	};


	//Destructor
	~Student()
	{
		cout << "Default destructor" << endl;
	};

};

unsigned int Student::Counter = 0;



class Group
{
	string nameGroup;
	string nameSpecialty;
	unsigned int sizeGroup;
	unsigned int course;
	unsigned int IDGroup;
	
	Student *student;
  
public:
	static unsigned int CounterGroup;
	Group() 
	{
		this->IDGroup = CounterGroup;
		cout << "Default constructor" << endl;
	};
	Group(string nameGroup, string nameSpecialty, int sizeGroup, int course)
	{
		this->nameGroup = nameGroup;
		this->nameSpecialty = nameSpecialty;
		this->sizeGroup = sizeGroup;
		this->course = course;
		CounterGroup++;
		this->IDGroup = CounterGroup;
		this->student = new Student[sizeGroup];
		cout << "==== Our group: ======" << endl;
		for (int i = 0; i < this->sizeGroup; i++)
		{
			student[i].FillStudent();
			student[i].Average();
		}
		cout << "Overload constructor." << endl;
	};

	int GetIDGroup() { return IDGroup; };
	string GetNameGroup() { return nameGroup; };
	string GetNameSpecialty() { return nameSpecialty; };
	unsigned int GetSizeGroup() { return sizeGroup; };
	unsigned int GetCourse() { return course; };

	void SetIDGroup(int IDGroup) { this->IDGroup = IDGroup; };
	void SetNameGroup(string nameGroup) { this->nameGroup = nameGroup; };
	void SetNameSpecialty(string nameSpecialty) { this->GetNameSpecialty = nameSpecialty; };
	void SetSizeGroup(unsigned int sizeGroup) { this->sizeGroup = sizeGroup; };
	void SetCource (unsigned int course) { this->course = course; };




	void FillGroup() {
		cout << "ID group =====>>>>>>>>>>" << IDGroup << endl;
		cout << "Enter name group";
		cin >> nameGroup;
		cout << "Enter name specialty: ";
		cin >> nameSpecialty;
		cout << "Enter size group: ";
		cin >> sizeGroup;
		cout << "Enter cource: ";
		cin >> course;
	};
	void ShowInfoGroup() {
		

			cout << "===================================================================" << endl;
			cout << "Total groups in the database: " << this->IDGroup << endl;
			cout << "Cource: " << this->course << " Group: " << this->nameGroup << " Specialty: " << this->nameSpecialty << " Size:" << this->sizeGroup << ": " << endl;
			for (int i = 0; i < this->sizeGroup; i++)
			{
				cout << "\t\t Student N: " << i + 1 << endl;
				this->student[i].ShowInfoStudent();
				cout << "\t\t\t*******\t\t\t" << endl;
			}
			cout << "===================================================================" << endl;
		
	};
	void ChangeStudentInfo() {
		bool exit = 0;
		int choice;
		int x = 0;
		string newname;
		string newsurname;
		int newage;
		cout << "Enter the student number to edit the data: " << endl;
		cin >> x;
		cout << "*************************************" << endl;
		cout << "You want to change student:" << endl;
		student[x].ShowInfoStudent();
		student[x].Average();
		cout << "*************************************" << endl;
		while (!exit)
		{
			cout << "Enter choice:\n1 - change Name;\n2 - change Surname;\n3 - change Age;\n0 - EXIT" << endl;;
			cin >> choice;
			switch (choice)
			{
			case 1:
			{
				cout << "Enter name: " << endl;
				cin >> newname;
				student[x].SetName(newname);
				break;
			}
			case 2:
			{
				cout << "Enter surname: ";
				cin >> newsurname;
				student[x].SetSurname(newsurname);
				break;
			}
			case 3:
			{
				cout << "Enter age: " << endl;
				cin >> newage;
				student[x].SetAge(newage);
				break;
			}
			case 0:
			{
				exit = true;
				break;
			}
			default:
			{
				cout << "Error" << endl;
				break;
			}
			}
		}
		
	};


	///////////////////////////////////////////////
	void FillGroupFromFile()
	{
		string path = "db.txt";
		ifstream readFile;
		readFile.open(path);
		if (!readFile.is_open())
		{
			cout << "Can't open file " << endl;
		}
		else
		{
			cout << "======= STUDENTS GROUP: =========" << endl;

			char temp[255];
			readFile.getline(temp, 255);
			int SIZE = atoi(temp);
			student = new Student[SIZE];
			for (int i = 0; i < SIZE; i++)
			{
				readFile.getline(temp, 255);
				GetNameGroup() = temp;
				readFile.getline(temp, 255);
				GetNameSpecialty() = temp;
				readFile.getline(temp, 255);
				GetCourse() = temp;
				readFile.getline(temp, 255);

				readFile.getline(temp, 255);
				student[i].GetName() = temp;
				readFile.getline(temp, 255);
				student[i].GetSurname() = temp;
				readFile.getline(temp, 255);
			
			}

		}
		readFile.close();

	}
	///////////////////////////////////////////////




	//Zapys u fail
	void OutputCollectionInFile()
	{
		ofstream writeFile;
		string path = "db1.txt";
		string text;
		writeFile.open(path, ofstream::app);
		
		if (!writeFile.is_open())
		{
			cout << "Can't open file!" << endl;
		}
		else
		{
			cout << "File saved!" << endl;
			for (int i = 0; i < sizeGroup; i++)
			{
				writeFile << "**************   Student number: " << i + 1 << "**********************" << endl;
				writeFile << "Name Group:\t" << GetNameGroup() << endl;
				writeFile << "Name specialty:\t" << GetNameSpecialty() << endl;
				writeFile << "Size of group: \t" << GetSizeGroup() << endl;
				writeFile << "Course: \t" << GetCourse() << endl;
				writeFile << "Name student:\t" << student[i].GetName() << endl;
				writeFile << "Surname student:\t   " << student[i].GetSurname() << endl;
				writeFile << "Age student:\t   " << student[i].GetAge() << endl;
				writeFile << "Average student:\t   " << student[i].GetAverage() << endl;
			}

		}

		writeFile.close();
	}




	//Destructor
	~Group() { cout << "Default destructor Group" << this << endl; };

};

unsigned int Group::CounterGroup = 0;


int main()
{
	Group group2("123", "Grafic", 2, 3);
	group2.ShowInfoGroup();
	//FillGroupFromFile(group2);
	/*group2.ChangeStudentInfo();
	group2.ShowInfoGroup();*/
	group2.OutputCollectionInFile();


	system("pause");
	return 0;
}
