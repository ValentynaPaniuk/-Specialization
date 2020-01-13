#include <iostream>
#include <string>
#include <ctime>
using namespace std;
/*ООП
Опишіть класи "Swordsman" (Мечник), "Archer" (Лучник) і "Mage" (Маг), 
кожен з яких є екземпляром базового класу "Unit" (штука, елемент) в комп'ютерній грі, і може атакувати, ухилятись від атак і вмирати.

У мечника 15 хіт-поінтів (життів), пошкодження при атаці 5, шанс ухилятись 60%.
Лучник: 12 hp, 4 dmg, 40% dodge
Маг: 8 hp, 10 dmg, 30% dodge


В main() створіть два масива (ворогуючі сторони) по три юніта в кожному, 
причому тип юніта (мечник, лучник чи маг) має задаватись випадково, при заповненні цих масивів. 
Тобто один раз запустивши вашу програму, може створитись три лучники проти мечника і двох магів, 
іншого - лучник, мечник і маг проти двох мечників і лучника і т.д.

Далі в циклі земулюйте бій між ними, поки бійці однієї з сторін всі не загинуть. 
В консоль при цьому виводьте повідомлення хто кого атакував, чи вдалась атака, 
скільки життя залишилось у жертви чи вона загинула. 

Нехай бій відбувається поступово, по натиснення клавіші spacebar (пробіла), 
щоб ми могли спостерігати його атака за атакою.

В кінці бою оголосіть, яка команда перемогла (перша/друга, синя/червона, альянс/орки - як вже ваша фантазія вам підскаже).
Не забудьте здійснити приведення типів там, де це необхідно.*/

class Unit 
{
	int hp;
	int attackdamage;
	double chancetododge;
	
public:
	Unit() { cout << "Default Constructor Unit"<<this<< endl; };
	Unit(int hp, int attackdamage, double chancetododge) 
	{  this->hp = hp;
	   this->attackdamage = attackdamage;
	   this->chancetododge = chancetododge;
	   cout << "Overload Constructor Unit " << this << endl;
	};

	int GetHp()									{ return hp; }
	int GetAttackdamage() 						{ return attackdamage; }
	double GetChancetododge()					{ return chancetododge; }
	void SetHp(int hp)							{ this->hp = hp; }
	void SetAttackdamage(int attackdamage)		{ this->attackdamage = attackdamage; }
	void SetChancetododge(double chancetododge) { this->chancetododge = chancetododge; }
	virtual void ShowInfo() = 0;

	void Attack()						{ ShowInfo(); 	cout << "attack " << "\t\t\t\t\t\t\t\t";};
	void Evadeattacks() { ShowInfo(); this->hp--; cout << "evade attacks " << endl; }
	void Die() { if (this->hp == 0) { ShowInfo(); cout << "Die " << " "; } };
	~Unit() { cout << "Default Destructor Unit " << this << endl; };

};



class Swordsman: public Unit //(Мечник)
{
	int hp;
	int attackdamage;
	double chancetododge;
		
public:
	Swordsman() { cout << "Default Constructor Swordsman " << this << endl; };
	Swordsman(int hp, int attackdamage, double chancetododge)
	{
		this->hp = hp;
		this->attackdamage = attackdamage;
		this->chancetododge = chancetododge;
		cout << "Overload Constructor Swordsman " << this << endl;
	};
	virtual void ShowInfo()
	{
		cout << "Swordsman" << " HP " << this->hp << "   ";
	}


	~Swordsman() { cout << "Default Destructor Swordsman " << this << endl; };

};

class Archer: public Unit //(Лучник)
{
	int hp;
	int attackdamage;
	double chancetododge;

public:

	Archer() { cout << "Default Constructor Archer " << this << endl; };
	Archer(int hp, int attackdamage, double chancetododge)
	{
		this->hp = hp;
		this->attackdamage = attackdamage;
		this->chancetododge = chancetododge;
		cout << "Overload Constructor Archer " << this << endl;
	};

	virtual void ShowInfo()
	{
		cout << "Archer" << " HP " << this->hp << "   ";
	}

	
	~Archer() { cout << "Default Destructor Archer " << this << endl; };
};

class Mage: public Unit //(Маг)
{
	int hp;
	int attackdamage;
	double chancetododge;

public:

	Mage() { cout << "Default Constructor Mage " << this << endl;  };
	Mage(int hp, int attackdamage, double chancetododge)
	{
		this->hp = hp;
		this->attackdamage = attackdamage;
		this->chancetododge = chancetododge;
		cout << "Overload Constructor Mage " << this << endl;
	};

	virtual void ShowInfo()
	{
		cout << "Mage" << " HP " << this->hp << "   ";
	}
	
	~Mage() { cout << "Default Destructor Mage " << this << endl; };
	
};


int main()
{
	srand(unsigned(time(NULL)));
	int x;
	Unit *unit1[3];
	Unit *unit2[3];
	bool exit = false;

	unit1[0] = new Swordsman(15, 5, 0.6);
	unit1[1] = new Archer(12, 4, 0.4);
	unit1[2] = new Mage(8, 10, 0.3);


	cout << "Unit 1 =================================" << endl;
	for (int i = 0; i < 3; i++)
	{
		x = rand() % 3 + 1;
		if (x == 1)
		{ unit1[i]= new Swordsman(15, 5, 0.6);}
		else if (x == 2)
		{ unit1[i]= new Archer(12, 4, 0.4);}
		else if (x == 3)
		{ unit1[i] = new Mage(8, 10, 0.3);	}

	}

	for (int i = 0; i < 3; i++)
	{ 
		unit1[i]->ShowInfo();
	}

	cout << endl;
	cout << "Unit 1 ===================================" << endl;
	cout << "\nUnit 2 =================================" << endl;
	for (int i = 0; i < 3; i++)
	{
		x = rand() % 3 + 1;
		if (x == 1)
		{ unit2[i] = new Swordsman(15, 5, 0.6);}
		else if (x == 2)
		{ unit2[i] = new Archer(12, 4, 0.4);}
		else if (x == 3)
		{ unit2[i] = new Mage(8, 10, 0.3);}
	}

	for (int i = 0; i < 3; i++)
	{
		unit2[i]->ShowInfo();
	}
	cout << endl;
	cout << "Unit 2 =================================" << endl;
	/*
	while (!exit)
	{
		for (int i = 0; i < 3; i++)
		{
			unit1[i]->Attack();
			unit2[i]->Evadeattacks();

			unit2[i]->Attack();
			unit1[i]->Evadeattacks();
			
			cout << "\n\n================= THE END " << i << " fight\n\n\n" << endl;
			system("pause");
			
			
		}
		cout << endl;
	}*/
	


	system("pause");
	return 0;
}