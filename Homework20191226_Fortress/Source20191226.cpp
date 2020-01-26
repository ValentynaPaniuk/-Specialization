#include <iostream>
#include <string>
using namespace std;
/*Описати клас "Fortress" (Фортеця).

Для початку, напишіть клас "Shooter" (стрілець), який буде містити два поля: назва аммуніції та її кількість. 
Він може виконати дію "постріл" і витратити для цього одиницю амуніції, повідомляючи в консоль, як вона називалась. 
А також може здійснити дію "дати амуніцію", яка встановлюватиме назву і кількість амуніції, отримуючі ці дані через параметри.

Стрілець має три дочірні класи: "Archer" (Лучник), "Ranger" (Рейнджер) та "Catapult" (Катапульта), 
які заміщають дію "постріл", доповнюючи повідомлення в консоль інформацією про те, хто саме з них вистрілив. 
Перші два повинні стріляти стрілами, а катапульта - каменями.

Від перших двох породжується клас "ArcherTower" (Cтрілкова вежа), 
у якої запас амуніції має бути один (спільний) для обох: лучника і рейнджера 
(подумайте, який механізм множинного успадкування тут варто застосувати). 

Від класів "стрілкова вежа" і "катапульта" має походити клас "Fortress". 
Лише в її конструкторі мають поставлятись стріли для стрілкової вежі і камені для катапульти. 
Додайте до фортеці ще кілька полів - товщина стін, стан воріт у відсотках, і т.д. - по вашому бажанню та фантазії.

Більше ніяких допоміжних методів чи об'єктів створювати не потрібно. 
В кожного з полів чи методів у цій ієрархії має бути встановлений максимальний рівень захисту, 
і успадкування має відбуватись по найвищо-допустимому по захисту специфікаторові доступу. 
Але таким, щоб в main() можна було виконати наступне: 

- створити об'єкт фортеці 
- вистрілити тричі лучником, двічі рейнджером і раз з катапульти 
Отже, всього має бути 6 класів, вінцем творіння і фінальним дитям серед них є клас "Фортеця", 
лише один об'єкт якої буде створено. Зверніть на це увагу - 6 класів описано, всі використовуються. 
Але об'єкт у всій програмі один.

ПРИМІТКИ! Коли створюватиметься фортеця, доставте в стрілкову вежу лише 4 стріли, тоді буде явно видно,
що на другий постріл рейнджеру стріл не вистачить, оскільки лучник перед тим витратив 3 із 4-х стріл.

*/

/*Для початку, напишіть клас "Shooter" (стрілець), який буде містити два поля :
назва аммуніції та її кількість.
Він може виконати дію "постріл" і витратити для цього одиницю амуніції, повідомляючи в консоль, як вона називалась.
А також може здійснити дію "дати амуніцію", яка встановлюватиме назву і кількість амуніції, отримуючі ці дані через параметри.*/
class Shooter //Стрілець
{

public:
	string name;
	int counter;

	Shooter(string name = "weapon", int counter = 1)
	{	this->name = name;
		this->counter = counter;
		cout << "Overload constructor Shooter" << this << endl;
	};

	void Fire() 
	{ 	
		if (this->counter > 0)
		{
			this->counter--;
			cout << " fire " << this->name << endl;
			cout << "Remains: " << this->counter << endl;
		}
		else
		{
			cout << "Not enough ammunotion" << endl;
		}
		
	}

	void GiveAmmo(string name, int counter)
	{
		this->name = name;
		this->counter = counter;

	}

	~Shooter() { cout << "Default destructor Shooter" << this << endl; };

};

/*Стрілець має три дочірні класи:
"Archer" (Лучник), "Ranger" (Рейнджер) та "Catapult" (Катапульта), 
які заміщають дію "постріл", доповнюючи повідомлення в консоль інформацією про те, хто саме з них вистрілив. 
Перші два повинні стріляти стрілами, а катапульта - каменями.*/

class Archer : virtual public Shooter //Лучник
{
	
public:
	Archer(string name = "Arrows", int counter = 1)
	{ 
		Archer::GiveAmmo(name, counter);
		cout << "Overload constructor Archer" << this << endl; 
	};

	void Fire()
	{
		cout << "Archer "; Shooter::Fire();
	}



	~Archer() { cout << "Default destructor Archer" << this << endl; };
};
	

class Ranger : virtual public Shooter//Рейнджер
{

public:
	Ranger(string name = "Arrows", int counter = 1)
	{
		Ranger::GiveAmmo(name, counter);
		cout << "Overload constructor Ranger" << this << endl;
	};

	void Fire() { cout << "Ranger "; Shooter::Fire(); 	}

	~Ranger() { cout << "Default destructor Ranger" << this << endl; };
};
class Catapult : public Shooter //Катапульта
{
	
public:
	Catapult(string name = "Stones", int counter = 1)
	{
		Catapult::GiveAmmo(name, counter);
		cout << "Overload constructor Catapult" << this << endl;
	};
	void Fire() {
		cout << "Catapult ";
		Shooter::Fire();
	}

	~Catapult() { cout << "Default destructor Catapult" << this << endl; };
};


/*Від перших двох породжується клас "ArcherTower" (Cтрілкова вежа), 
у якої запас амуніції має бути один (спільний) для обох: лучника і рейнджера 
(подумайте, який механізм множинного успадкування тут варто застосувати). */
class ArcherTower : public Archer , public Ranger
{
public:
	ArcherTower(string name = "Stone", int counter = 1)
	{
		cout << "Overload constructor ArcherTower" << this << endl;
	};


	~ArcherTower() { cout << "Default destructor ArcherTower" << this << endl; };

};


/*Від класів "стрілкова вежа" і "катапульта" має походити клас "Fortress". 
Лише в її конструкторі мають поставлятись стріли для стрілкової вежі і камені для катапульти.
Додайте до фортеці ще кілька полів - товщина стін, стан воріт у відсотках, і т.д. - по вашому бажанню та фантазії.*/

class Fortress : public ArcherTower, public Catapult
{
	
public:
	Fortress(int arrowsArcherTower = 0, int stonesCatapult = 1) 
	{
		ArcherTower::counter = arrowsArcherTower;
		Catapult::counter = stonesCatapult;
		cout << "Overload constructor Fortress" << this << endl;
	};



	~Fortress() { cout << "Default destructor Fortress" << this << endl; };
};

int main()
{
	Fortress fortress(4, 4);

	fortress.Archer::Fire();
	fortress.Archer::Fire();
	fortress.Archer::Fire();

	fortress.Ranger::Fire();
	fortress.Ranger::Fire();

	fortress.Catapult::Fire();


	system("pause");
	return 0;
}