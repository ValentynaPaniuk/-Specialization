#include "Group.h"
#include "Student.h"

using namespace std;

unsigned int Group::CounterGroup = 0;

Group::Group()
{
	IDGroup = CounterGroup;
	cout << "Default constructor" << endl;
}

Group::Group(string nameGroup, string nameSpecialty, int sizeGroup, int course)
{
	this->nameGroup = nameGroup;
	this->nameSpecialty = nameSpecialty;
	this->sizeGroup = sizeGroup;
	this->course = course;
	CounterGroup++;
	IDGroup = CounterGroup;
	this->student = new Student[sizeGroup];
	cout << "==== Our group: ======" << endl;
	for (int i = 0; i < this->sizeGroup; i++)
	{
		
		student[i].FillStudent();
	}
	cout << "Overload constructor." << endl;
}


int Group::GetIDGroup()
{
	return IDGroup;
}

void Group::FillGroup()
{
	cout << "ID group =====>>>>>>>>>>" << IDGroup << endl;
	cout << "Enter name group";
	cin >> nameGroup;
	cout << "Enter name specialty: ";
	cin >> nameSpecialty;
	cout << "Enter size group: ";
	cin >> sizeGroup;
	cout << "Enter cource: ";
	cin >> course;

}

void Group::ShowInfoGroup()
{
	{
		cout << "===================================================================" << endl;
		cout << "Total groups in the database: " << IDGroup << endl;
		cout << "Cource: " << this->course << " Group: " << this->nameGroup << " Specialty: " << this->nameSpecialty << " Size:" << this->sizeGroup << ": " << endl;
		for (int i = 0; i <= this->sizeGroup; i++)
		{
			this->student[i+1].ShowInfoStudent();
		}
		cout << "===================================================================" << endl;
	}
}

void Group::ChangeStudentInfo()
{
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
	
}





Group::~Group()
{
	cout << "Default destructor" << endl;
}

