#include <iostream>
#include <string>
using namespace std;
/*������� ���� "Fortress" (�������).

��� �������, �������� ���� "Shooter" (�������), ���� ���� ������ ��� ����: ����� �������� �� �� �������. 
³� ���� �������� �� "������" � ��������� ��� ����� ������� �������, ����������� � �������, �� ���� ����������. 
� ����� ���� �������� �� "���� �������", ��� ��������������� ����� � ������� �������, ��������� �� ��� ����� ���������.

������� �� ��� ������ �����: "Archer" (������), "Ranger" (��������) �� "Catapult" (����������), 
�� �������� �� "������", ���������� ����������� � ������� ����������� ��� ��, ��� ���� � ��� ��������. 
����� ��� ������ ������� �������, � ���������� - ��������.

³� ������ ���� ����������� ���� "ArcherTower" (C������� ����), 
� ��� ����� ������� �� ���� ���� (�������) ��� ����: ������� � ��������� 
(���������, ���� ������� ���������� ������������ ��� ����� �����������). 

³� ����� "�������� ����" � "����������" �� �������� ���� "Fortress". 
���� � �� ����������� ����� ������������ ����� ��� �������� ��� � ����� ��� ����������. 
������� �� ������� �� ����� ���� - ������� ���, ���� ���� � ��������, � �.�. - �� ������ ������� �� �����糿.

������ ����� ��������� ������ �� ��'���� ���������� �� �������. 
� ������� � ���� �� ������ � ��� �������� �� ���� ������������ ������������ ����� �������, 
� ������������ �� ���������� �� �������-����������� �� ������� �������������� �������. 
��� �����, ��� � main() ����� ���� �������� ��������: 

- �������� ��'��� ������� 
- ��������� ����� ��������, ���� ���������� � ��� � ���������� 
����, ������ �� ���� 6 �����, ����� ������� � ��������� ����� ����� ��� � ���� "�������", 
���� ���� ��'��� ��� ���� ��������. ������� �� �� ����� - 6 ����� �������, �� ����������������. 
��� ��'��� � ��� ������� ����.

���̲���! ���� ���������������� �������, �������� � �������� ���� ���� 4 �����, ��� ���� ���� �����,
�� �� ������ ������ ��������� ���� �� ���������, ������� ������ ����� ��� �������� 3 �� 4-� ����.

*/

/*��� �������, �������� ���� "Shooter" (�������), ���� ���� ������ ��� ���� :
����� �������� �� �� �������.
³� ���� �������� �� "������" � ��������� ��� ����� ������� �������, ����������� � �������, �� ���� ����������.
� ����� ���� �������� �� "���� �������", ��� ��������������� ����� � ������� �������, ��������� �� ��� ����� ���������.*/
class Shooter //�������
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

/*������� �� ��� ������ �����:
"Archer" (������), "Ranger" (��������) �� "Catapult" (����������), 
�� �������� �� "������", ���������� ����������� � ������� ����������� ��� ��, ��� ���� � ��� ��������. 
����� ��� ������ ������� �������, � ���������� - ��������.*/

class Archer : virtual public Shooter //������
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
	

class Ranger : virtual public Shooter//��������
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
class Catapult : public Shooter //����������
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


/*³� ������ ���� ����������� ���� "ArcherTower" (C������� ����), 
� ��� ����� ������� �� ���� ���� (�������) ��� ����: ������� � ��������� 
(���������, ���� ������� ���������� ������������ ��� ����� �����������). */
class ArcherTower : public Archer , public Ranger
{
public:
	ArcherTower(string name = "Stone", int counter = 1)
	{
		cout << "Overload constructor ArcherTower" << this << endl;
	};


	~ArcherTower() { cout << "Default destructor ArcherTower" << this << endl; };

};


/*³� ����� "�������� ����" � "����������" �� �������� ���� "Fortress". 
���� � �� ����������� ����� ������������ ����� ��� �������� ��� � ����� ��� ����������.
������� �� ������� �� ����� ���� - ������� ���, ���� ���� � ��������, � �.�. - �� ������ ������� �� �����糿.*/

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