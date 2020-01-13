#include<iostream>
#include<string>
using namespace std;

class Shooter
{
public:
	string nameAmmunition;
	int quantityAmmunition;

	Shooter(string nameAmmunition = "weapon", int quantityAmmunition = 1)
	{
		this->nameAmmunition = nameAmmunition;
		this->quantityAmmunition = quantityAmmunition;
	}

	void Fire() {
		if (this->quantityAmmunition > 0) {
			this->quantityAmmunition--;
			cout << "fired by " << this->nameAmmunition << ", remains: " << this->quantityAmmunition << endl;
		}
		else cout << "Not enough ammunition" << endl;
	}

	void GiveAmmo(string nameAmmunition, int quantityAmmunition) {
		this->nameAmmunition = nameAmmunition;
		this->quantityAmmunition = quantityAmmunition;
	}

};

class Archer : virtual public Shooter
{
public:
	Archer(string nameAmmunition = "arrow", int quantityAmmunition = 1)
	{
		Archer::GiveAmmo(nameAmmunition, quantityAmmunition);
	}

	void Fire() {
		cout << "Archer ";
		Shooter::Fire();
	}
};

class Ranger : virtual public Shooter
{
public:
	Ranger(string nameAmmunition = "arrow", int quantityAmmunition = 1)
	{
		Ranger::GiveAmmo(nameAmmunition, quantityAmmunition);
	}

	void Fire() {
		cout << "Ranger ";
		Shooter::Fire();
	}
};

class Catapult : public Shooter
{
public:
	Catapult(string nameAmmunition = "stone", int quantityAmmunition = 1)
	{
		Catapult::GiveAmmo(nameAmmunition, quantityAmmunition);
	}

	void Fire() {
		cout << "Catapult ";
		Shooter::Fire();
	}
};

class ArcherTower : public Archer, public Ranger
{
public:
	ArcherTower(string nameAmmunition = "stone", int quantityAmmunition = 1) {}
};

class Fortress : public ArcherTower, public Catapult
{
public:
	Fortress(int quantityArrow = 0, int quantityStone = 1) {
		ArcherTower::quantityAmmunition = quantityArrow;
		Catapult::quantityAmmunition = quantityStone;
	}
};

int main() {

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