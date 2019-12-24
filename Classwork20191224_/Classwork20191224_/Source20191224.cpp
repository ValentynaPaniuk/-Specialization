#include <iostream>
#include <string>
using namespace std;

//Inheritance - nasliduvannia
class Human 
{
	string name;
	int age;

	public:

	string GetName()
	{
		return this->name;
	}

	void SetName(string name)
	{
		this->name = name;
	}

	int GetAge()
	{
		return this->age;
	}

	void SetAge(int age)
	{
		this->age = age;
	}

	void ShowInfo()
	{
		cout << "Name: " << GetName() << endl;
	};

	void Age()
	{
		cout << "Age " << this->name << ": " << this->age << endl;
	}
};

class Gunior: public Human
{
public:
	string position;
	void WriteCode()
	{
		cout <<this->position<<" "<<this->GetName() <<" white code every day" << endl;
	}
	

};

class Middle : public Gunior
{
public:
	bool customers = true;
	void WriteCode()
	{
		cout <<"Customers: "<<this->customers<<" "<< this->position << " " << this->GetName() << " white code every day and speak with partners every friday" << endl;
	}


};

class Senior : public Middle
{
public:

	void WriteCode()
	{
		cout << "Customers: " << this->customers << " " << this->position << " " << this->GetName() << " white code very good.\n " << endl;
	}
	void CreateDatabase()
	{
		cout <<this->GetName()<< " create database" << endl;
	}

};




int main()
{
	cout << "\n====================================================================\n" << endl;
	Human man1;
	string name = "Petya(class Human)";
	int age = 30;
	man1.SetName(name);
	man1.ShowInfo();
	man1.SetAge(age);
	man1.Age();
	
	cout << "\n====================================================================\n" << endl;
	string name1 = "Petya Petrov (class Gunior)";
	int age1 = 35;
	Gunior man2;
	man2.position = "Developer";
	man2.SetName(name1);
	man2.ShowInfo();
	man2.WriteCode();
	man2.SetAge(age1);
	man2.Age();

	cout << "\n====================================================================\n" << endl;
	string name2 = "Petya Petrov (class Middle)";
	int age2 = 40;
	Middle man3;
	man3.SetName(name2);
	man3.ShowInfo();
	man3.WriteCode();
	man3.SetAge(age2);
	man3.Age();
	 
	cout << "\n==================================================================\n" << endl;
	string name3 = "Petya Petrov (class Senior)";
	int age3 = 45;
	Senior man4;
	man4.SetName(name3);
	man4.ShowInfo();
	man4.WriteCode();
	man4.CreateDatabase();
	man4.SetAge(age3);
	man4.Age();

	cout << "\n=================================================================\n" << endl;

	system("pause");
	return 0;
}