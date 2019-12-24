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
скільки життя залишилось у жертви чи вона загинула. Нехай бій відбувається поступово, по натиснення клавіші spacebar (пробіла), 
щоб ми могли спостерігати його атака за атакою.

В кінці бою оголосіть, яка команда перемогла (перша/друга, синя/червона, альянс/орки - як вже ваша фантазія вам підскаже).
Не забудьте здійснити приведення типів там, де це необхідно.*/

class Unit 
{
	int hp;
	int attackdamage;
	int chancetododge;

public:

	int GetHp()
	{
		return hp;
	}

	void SetHp(int hp)
	{
		this->hp = hp;
	}

	int GetAttackdamage()
	{
		return attackdamage;
	}

	void SetAttackdamage(int attackdamage)
	{
		this->attackdamage = attackdamage;
	}

	int GetChancetododge()
	{
		return chancetododge;
	}

	void SetChancetododge(int chancetododge)
	{
		this->chancetododge = chancetododge;
	}


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

class Swordsman: public Unit
{
};

class Archer: public Unit
{
};

class Mage: public Unit
{
};


int main()
{


	system("pause");
	return 0;
}