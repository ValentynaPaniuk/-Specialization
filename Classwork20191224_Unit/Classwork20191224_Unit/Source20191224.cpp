#include <iostream>
#include <string>
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
	Unit() {};
	Unit(int hp, int attackdamage, double chancetododge) 
	{  this->hp = hp;
	   this->attackdamage = attackdamage;
	   this->chancetododge = chancetododge;
	};

	int GetHp()									{ return hp; }
	int GetAttackdamage() 						{ return attackdamage; }
	double GetChancetododge()					{ return chancetododge; }
	void SetHp(int hp)							{ this->hp = hp; }
	void SetAttackdamage(int attackdamage)		{ this->attackdamage = attackdamage; }
	void SetChancetododge(double chancetododge) { this->chancetododge = chancetododge; }
	virtual void ShowInfo() = 0;

	void Attack()
	{

	};
	void Evadeattacks()
	{


	};
	void Die()
	{

	};

};

class Swordsman: public Unit //(Мечник)
{
	int hp;
	int attackdamage;
	double chancetododge;
		
public:
	Swordsman() {};
	Swordsman(int hp, int attackdamage, double chancetododge)
	{
		this->hp = hp;
		this->attackdamage = attackdamage;
		this->chancetododge = chancetododge;
	};
	virtual void ShowInfo()
	{
		cout << "Swordsman" << endl;
	}

};

class Archer: public Unit //(Лучник)
{
	int hp;
	int attackdamage;
	double chancetododge;

public:

	Archer() {};
	Archer(int hp, int attackdamage, double chancetododge)
	{
		this->hp = hp;
		this->attackdamage = attackdamage;
		this->chancetododge = chancetododge;
	};

	virtual void ShowInfo()
	{
		cout << "Archer" << endl;
	}

	
};

class Mage: public Unit //(Маг)
{
	int hp;
	int attackdamage;
	double chancetododge;

public:

	Mage() {};
	Mage(int hp, int attackdamage, double chancetododge)
	{
		this->hp = hp;
		this->attackdamage = attackdamage;
		this->chancetododge = chancetododge;
	};

	virtual void ShowInfo()
	{
		cout << "Mage" << endl;
	}
	
	
};


int main()
{
	Unit *unit1[3];

	unit1[0] = new Swordsman(15, 5, 0.6);
	unit1[1] = new Archer(12, 4, 0.4);
	unit1[2] = new Mage(8, 10, 0.3);
	
	for (int i = 0; i < 3; i++)
	{
		unit1[i]->ShowInfo();
	}



	unit1[3] = nullptr;
	delete[] unit1;


	system("pause");
	return 0;
}