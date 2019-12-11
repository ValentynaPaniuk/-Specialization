#include<iostream>
#include<string>
#include "Circle.h"

using namespace std;

/*Задание 1 Создайте класс Circle(окружность) : 
■ Реализуйте через перегруженные операторы; 
■ Проверка на равенство радиусов двух окружностей(операция = = ); 
■ Сравнения длин двух окружностей(операция > ).
Пропорциональное изменение размеров окружности, путем изменения ее радиуса(операция += и -= )*/

class Circle
{

	double r;
	double p;
	int ID;
	static int counter;
	


public:
	Circle() {
		
			counter++;
			cout << "Enter radius for Circle N "<<counter<<"=> ";
			cin >> r;
			if (r <= 0)
			{
				cout << "Enter correct value radius" << endl;
			}
			this->ID = counter;
	};
	Circle(double r)
	{
		counter++;
		this->r = r;
		this->p = 3.14;
		this->ID = counter;
		cout << "Overload constructor Circle " << this << endl;
	};

	int GetID()
	{
		return ID;
	}

	static int GetCounter()
	{
		return counter;
	}

	void ShowInfo()
	{
		cout << "Circle "<< GetID() <<" radius = "<<r<< endl;
	}




	~Circle() {};

	bool operator==(const Circle &other)
	{
		return this->r == other.r;
	}


	bool operator!=(const Circle &other)
	{
		return !(this->r == other.r);
	}


	bool operator>(const Circle &other)
	{
		return (2*this->r*this->p) > (2*other.r*other.p);
	}

	bool operator<(const Circle &other)
	{
		return (this->r*this->p) < (other.r*other.p);
	}

	Circle &operator+= (double number)
	{
		this->r += number;
		cout << "Radius Circle N"<< GetID() <<" + number = " << this->r << endl;

		return *this;
	}


	Circle &operator-= (double number)
	{
		if (number < this->r)
		{
			this->r -= number;
			cout << "Radius Circle N" << GetID() << " - number = " << this->r << endl;
		}
		else
		{
			cout << "Enter the correct details.The radius cannot be negative" << endl;
		}
		return *this;
	}
	   

	
};

int Circle::counter = 0;



/*Задание 2 Создать класс Airplane (самолет) С помощью перегрузки операторов реализовать: 
■ Проверка на равенство типов самолетов (операция = =) 
■ Увеличение и уменьшение пассажиров в салоне самолета (операции ++ и - - в префиксной форме) 
■ Сравнение двух самолетов по максимально возможному количеству пассажиров на борту (операция>) */


class Airplane
{
	string type;
	int numberPassengers;
	static int counter;
	int ID;

public:
	Airplane() {
	
		counter++;
		this->ID = counter;
		cout << "Enter type of airlane N "<<GetID()<<": ";	cin >> type;
		cout << "Enter the number of passengers of airlane N " << GetID() << ": "; 	cin >> numberPassengers;
		if (numberPassengers <= 0)
		{
			cout << "Enter correct value number of passengers!" << endl;
		}
		
	};
	Airplane(string type, int numberPassengers) 
	{
		counter++;
		this->type = type;
		this->numberPassengers;
		this->ID = counter;
	};

	void ShowInfo()
	{
		cout << type << " N " << GetID() << " number of passengers: " << numberPassengers;
	}


	bool operator==(const Airplane &other)
	{
		return this->type == other.type;
	}

	bool operator!=(const Airplane &other)
	{
		return !(this->type == other.type);
	}


	bool operator<(const Airplane &other)
	{
		return (this->numberPassengers) < (other.numberPassengers);
	}

	bool operator>(const Airplane &other)
	{
		return (this->numberPassengers) > (other.numberPassengers);
	}





	Airplane &operator++ (int x)
	{
		if (this->numberPassengers > 0)
		{
			this->numberPassengers++;
			cout << "New number of passengers (++) of airplane N"<<GetID()<<" : " << this->numberPassengers << endl;
		}
		return *this;
	}

	Airplane &operator-- (int x)
	{
		if (this->numberPassengers > 0)
		{
			this->numberPassengers--;
			cout << "New number of passengers (--) of airplane N" << GetID() << " : " << this->numberPassengers << endl;
		}
		return *this;
	}




	int GetID()
	{
		return ID;
	}

	static int GetCounter()
	{
		return counter;
	}





	~Airplane() {};
};

int Airplane::counter = 0;

int main()
{
	cout << "******************* Exercise N 1 ************************ " << endl;

	Circle circle1;
	Circle circle2;
	circle1.ShowInfo();
	circle2.ShowInfo();
	bool result1 = circle1 == circle2;
	circle2.operator==(circle1);
	cout << "Result 1 (==): " << result1 << endl;

	bool result2 = circle1 != circle2;
	circle2.operator!=(circle1);
	cout << "Result 2 (!=): " << result2 << endl;

	bool result3 = circle1 > circle2;
	circle2.operator>(circle1);
	cout << "Result 3 (<): " << result3 << endl;

	bool result4 = circle1 < circle2;
	circle2.operator<(circle1);
	cout << "Result 4 (>): " << result4 << endl;

	circle1.operator+=(5.3);
	circle2.operator-=(2.6);

	cout << "\n ============================================================" << endl;
	cout << "******************* Exercise N 2 ************************ " << endl;
	Airplane a;
	Airplane b;

	bool res1 = a == b;
	a.operator==(b);
	cout << "Result 1 (type of airline 1 == type of airline 2): " << res1 << endl;

	bool res2 = a != b;
	a.operator!=(b);
	cout << "Result 2 (type of airline 1 != type of airline 2): " << res2<< endl;
	a++;
	b--;
	bool res3 = a > b;
	cout << "Result 3 (number of passengers airplane1 > number of passengers airplane2) " << res3 << endl;
	bool res4 = a < b;
	cout << "Result 4 (number of passengers airplane1 < number of passengers airplane2) " << res4 << endl;




	system("pause");
	return 0;

}