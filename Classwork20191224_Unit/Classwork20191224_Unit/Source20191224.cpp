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
protected:
	string name;
	int hp;
	int attackdamage;
	double chancetododge;
	bool dead;
	
public:
	Unit() { cout << "Default Constructor Unit"<<this<< endl; };
	

	string GetName()	{ return this->name;}
	int GetHp()			{ return this->hp; }
	bool GetStatus()	{ return this->dead; }
	
	
	void ShowInfo()
	{
		cout << "*\tClass: " << this->name;
		if (!this->dead)
		{
			cout << "\tHP: " << this->hp << "\tDamage: " << this->attackdamage << "\tChancetododge " << this->chancetododge<<" %\t*\n";
		}
		else
		{
			cout<<"\t HP: dead "<< "\tDamage: " << this->attackdamage << "\tChancetododge " << this->chancetododge<<"%\t*";
		}
	};

	template<typename T>
	void AttackOther(T &other)
	{
		int chance = rand() % 100 + 1;
		if (chance <= other.chancetododge)
		{
			other.hp -= this->attackdamage;
			cout << this->name << " attacted " << other.name << endl;
			if (other.hp <= 0)
			{
				cout << this->name << " kill " << other.name << endl;
			}
		}
	}



	~Unit() { cout << "Default Destructor Unit " << this << endl; };

};



class Swordsman: public Unit //(Мечник)
{
			
public:

	Swordsman()
	{
	
		this->name = "Swordman";
		this->hp = 15;
		this->attackdamage = 5;
		this->chancetododge = 60;
		this->dead = false;
		cout << "Overload Constructor Swordsman " << this << endl;
	};
	
	~Swordsman() { cout << "Default Destructor Swordsman " << this << endl; };

};

class Archer: public Unit //(Лучник)
{
	public:

	
	Archer()
	{
		this->name = "Archer";
		this->hp = 12;
		this->attackdamage = 4;
		this->chancetododge = 40;
		this->dead = false;
		cout << "Overload Constructor Archer " << this << endl;
	};

	
	~Archer() { cout << "Default Destructor Archer " << this << endl; };
};

class Mage: public Unit //(Маг)
{
	
public:

	
	Mage()
	{
		this->name = "Mage";
		this->hp = 8;
		this->attackdamage = 10;
		this->chancetododge = 30;
		this->dead = false;
		cout << "Overload Constructor Mage " << this << endl;
	};

		
	~Mage() { cout << "Default Destructor Mage " << this << endl; };
	
};

void RandomTeam(Unit *team, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		int random = rand() % 3 + 1;
		switch (random)
		{
		case 1:
			team[i] = Swordsman();
			break;
		case 2:
			team[i] = Archer();
			break;
		case 3:
			team[i] = Mage();
			break;
		default:
			break;
		}
	}
}

void ShowTeam(Unit *team, const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Gamer :" << i+1 << endl;
		team[i].ShowInfo();
	}
}

void ShowAllTeams(Unit *team1, Unit *team2, const int SIZE)
{
	cout << "********************************* ONE TEAM ******************************" << endl;
	ShowTeam(team1, SIZE);
	cout << "\n******************************* TWO TEAM ******************************" << endl;
	ShowTeam(team2, SIZE);
	cout << "\n***********************************************************************" << endl;
}

void Attack(Unit *team1, Unit *team2, const int SIZE)
{
	bool exit = false;
	while (!exit)
	{
		for (int i = 0; i < SIZE; i++)
		{
			cout << "==>> " << i + 1 << endl;
			team1[i].AttackOther(team2[i]);
			cout << "==>> " << i + 1 << endl;
			team2[i].AttackOther(team1[i]);
			if (team1[i].GetHp <= 0)
			{
				cout << "TEAM " << i + 1 << " DIED" << endl;
			}

			if (team2[i].GetHp <= 0)
			{
				cout << "TEAM "<< i+1 <<" DIED" << endl;
			}
			system("pause");
		}
	
	
	}
}


int main()
{
	srand(unsigned(time(NULL)));
	const int SIZE = 3;
	Unit *One = new Unit[SIZE];
	Unit *Two = new Unit[SIZE];
	RandomTeam(One, SIZE);
	RandomTeam(Two, SIZE);
	ShowAllTeams(One, Two, SIZE);
	Attack(One, Two, SIZE);


	system("pause");
	return 0;
}