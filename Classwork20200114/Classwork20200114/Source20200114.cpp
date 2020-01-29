#include<iostream>
#include<ctime>
#include<string>
using namespace std;

class Unit
{
protected:
	string className;
	short heatPoint;
	short damage;
	short dodge;
	bool isDead;

public:
	void showInfo() {
		cout << "|\tClass: " << this->className;
		if (!this->isDead) cout << "\t\tHP: " << this->heatPoint << "\t\tDamage: " << this->damage << "\t\tDodge: " << this->dodge << "%\t|" << endl;
		else cout << "\t\tHP: Dead" << "\tDamage: " << this->damage << "\t\tDodge: " << this->dodge << "%\t|" << endl;

	}

	template<typename T>
	void AttackOther(T &other) {
		short chance = rand() % 100 + 1;
		if (chance <= other.dodge) {
			other.heatPoint -= this->damage;
			cout << this->className << " attacked " << other.className << endl;
			if (other.heatPoint <= 0) {
				other.isDead = true;
				cout << this->className << " kill " << other.className << endl;
			}
		}
		else
		{
			cout << this->className << " dodged " << other.className << endl;
		}

	};

	string GetClassName() {
		return this->className;
	}

	short GetHeatPoints() {
		return this->heatPoint;
	}

	bool GetStatus() {
		return this->isDead;
	}


};

class Swordman : public Unit
{
public:
	Swordman() {
		this->className = "Swordman";
		this->heatPoint = 15;
		this->damage = 5;
		this->dodge = 60;
		this->isDead = false;
	}
};

class Archer : public Unit
{
public:
	Archer() {
		this->className = "Archer";
		this->heatPoint = 12;
		this->damage = 4;
		this->dodge = 40;
		this->isDead = false;
	}
};

class Mage : public Unit
{
public:
	Mage() {
		this->className = "Mage";
		this->heatPoint = 8;
		this->damage = 10;
		this->dodge = 30;
		this->isDead = false;
	}
};

void RandomizeTeam(Unit *team, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		int random = rand() % 3 + 1;

		switch (random)
		{
		case 1:
			team[i] = Swordman();
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

void ShowTeam(Unit *team, const int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		team[i].showInfo();
	}
}

void ShowAllTeams(Unit *Blue, Unit *Red, const int SIZE) {
	cout << "----------------------------------------TEAM BLUE----------------------------------------" << endl;
	ShowTeam(Blue, SIZE);
	cout << "----------------------------------------TEAM RED-----------------------------------------" << endl;
	ShowTeam(Red, SIZE);
	cout << "-----------------------------------------------------------------------------------------" << endl;
}

int LivingUnits(Unit *Units, const int SIZE) {
	int counter = 0;

	for (int i = 0; i < SIZE; i++) {
		if (!Units[i].GetStatus()) counter++;
	}

	return counter;
}

void ShowLivingUnits(Unit Units[], const int SIZE) {

	int counter = 0;

	for (int i = 0; i < SIZE; i++) {
		if (!Units[i].GetStatus()) {
			cout << counter + 1 << ". ";
			Units[i].showInfo();
			counter++;
		}
	}
}

int RealIndex(Unit *Units, const int SIZE, int choise) {
	int counter = 0;

	for (int i = 0; i < SIZE; i++) {
		if (!Units[i].GetStatus()) {
			if (counter == choise - 1) {
				return i;
			}
			counter++;
		}
	}
}

int FindSame(int ID, Unit *Blue, Unit *Red, const int SIZE) {
	bool flag = false;

	for (int i = 0; i < SIZE; i++) {
		if (Red[ID].GetClassName() == Blue[i].GetClassName()) {
			if (!Blue[i].GetStatus()) {
				return i;
			}
			else {
				continue;
			}

		}
	}
	if (!flag) {
		throw "Not found";
	}
}

void Attack(Unit *Blue, Unit *Red, const int SIZE) { // Code in this function isn't very good.
	bool exit = false;
	int choiseUnit;
	int choiseEnemy;

	while (!exit) {
		if (LivingUnits(Blue, SIZE) > 0 && LivingUnits(Red, SIZE) > 0) {
			cout << "Your live units: " << endl;
			ShowLivingUnits(Blue, SIZE);
			cout << "Choose the unit you want to attack: ";
			cin >> choiseUnit;
			choiseUnit = RealIndex(Blue, SIZE, choiseUnit);

			cout << "Enemy live units: " << endl;
			ShowLivingUnits(Red, SIZE);
			cout << "Select unit for attack: ";
			cin >> choiseEnemy;
			choiseEnemy = RealIndex(Red, SIZE, choiseEnemy);

			for (int i = 0; ; i++) {
				if (i == SIZE) i = 0;
				if (i == choiseEnemy && !Red[choiseEnemy].GetStatus()) {
					Blue[choiseUnit].AttackOther(Red[choiseEnemy]);
					break;
				}
			}

			if (LivingUnits(Red, SIZE) > 0) {

				choiseUnit = rand() % LivingUnits(Red, SIZE) + 1;
				choiseUnit = RealIndex(Red, SIZE, choiseUnit);

				try {
					choiseEnemy = FindSame(choiseUnit, Blue, Red, SIZE);
				}
				catch (...) {
					choiseEnemy = rand() % LivingUnits(Blue, SIZE) + 1;
					choiseEnemy = RealIndex(Blue, SIZE, choiseEnemy);
				}

				for (int i = 0; ; i++) {
					if (i == SIZE) i = 0;
					if (i == choiseEnemy && !Blue[choiseEnemy].GetStatus()) {
						Red[choiseUnit].AttackOther(Blue[choiseEnemy]);
						break;
					}
				}
			}
		}

		else if (LivingUnits(Blue, SIZE) > 0 && LivingUnits(Red, SIZE) <= 0) {
			cout << "Team Blue wins" << endl;
			exit = true;
		}
		else if (LivingUnits(Blue, SIZE) <= 0 && LivingUnits(Red, SIZE) > 0) {
			cout << "Team Red wins" << endl;
			exit = true;
		}

		system("pause");
	}
}


int main()
{
	srand(unsigned(time(NULL)));

	const int SIZE = 3;
	Unit *Blue = new Unit[SIZE], *Red = new Unit[SIZE];

	RandomizeTeam(Blue, SIZE);
	RandomizeTeam(Red, SIZE);

	ShowAllTeams(Blue, Red, SIZE);

	Attack(Blue, Red, SIZE);

	ShowAllTeams(Blue, Red, SIZE);

	system("pause");
	return 0;
}