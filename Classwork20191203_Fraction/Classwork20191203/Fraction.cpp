#include "Fraction.h"

using namespace std;

Fraction::Fraction()
{
	cout << "Default constructor" << endl;
	this->x = 0;
	this->y = 1;
}

Fraction::Fraction(int y)
{
	this->y = 1;

}

Fraction::Fraction(int x, int y)
{
	this->x = x;
	this->y = y;
	if (y <= 0)
	{
		cout << "Error! It is impossible to divide by zero" << endl;
	}
}

int Fraction::GetX()
{
	return x;
}

int Fraction::GetY()
{
	return y;
}

void Fraction::SetX(int x)
{
	this->x = x;
}

void Fraction::SetY(int y)
{
	this->y = y;
}

void Fraction::ShowInfoFraction()
{
	cout << "Number = "<<this->x << "/" << this->y << endl;
}

int Fraction::Reduction(int x, int y)
{
	while (y) 
	{
		int tmp = y;
		y = x % y;
		x = tmp;
		
	}
	cout << "           Greatest common factor: " << x << endl;
	return x;
}



void Fraction::Addition(Fraction & a, Fraction & b)
{
	int c = a.y*b.y;
	int y_a = c / a.y;
	int y_b = c / b.y;
	int x_a = a.x * y_a;
	int x_b = b.x * y_b;
	int x_ab = x_a + x_b;
	int z = Reduction(x_ab, c);
	cout << "Addishion: " << (x_a + x_b)/z << "/" << c/z << endl;
	
}

void Fraction::Multiplication(Fraction a, Fraction b)
{
	int a_x = a.x *b.x;
	cout << "AB_x = " << a_x << endl;
	int a_y = a.y * b.y;
	cout << "AB_y = " << a_y << endl;
	int z = Reduction(a_x, a_y);
	cout << "Multiplication: " << a_x / z << "/" << a_y/z << endl;
}

void Fraction::Division(Fraction a, Fraction b)
{
	int a_x = a.x*b.y;
	cout << "AB_x = " << a_x << endl;
	int a_y = a.y * b.x;
	cout << "AB_y = " << a_y << endl;
	int z = Reduction(a_x, a_y);
	cout << "Division: " << a_x / z << "/" << a_y / z << endl;
	
}

void Fraction::AddOne(Fraction a)
{
	cout <<"Number = "<< a.y << " / " << a.y<<endl;
	int a_x = a.x + a.y;
	int a_y = a.y;
	int z = Reduction(a_x, a_y);
	cout << "Adding a unit to a fraction: " << a_x / z << " / " << a_y / z << endl;

}

void Fraction::SubtractOne(Fraction &a)
{
	cout << "Number = " << a.y << " / " << a.y << endl;
	int a_x = a.x - a.y;
	int a_y = a.y;
	int z = Reduction(a_x, a_y);
	if ((a_y / z) < 0)
	{
		cout << "Subtract the unit from the fraction: " << (a_x / z)*(-1) << "/" << (a_y / z)*(-1) << endl;
	}
	else
	{
		cout << "Subtract the unit from the fraction: " << a_x / z << "/" << a_y / z << endl;
	}

}

void Fraction::IntDivision()
{
	cout <<"Int division: "<< this->x<<"/"<< this->y<<" = "<< (this->x / this->y) << endl;
}

void Fraction::DoubleDivision()
{
	double z = (double(this->x) / double(this->y));
	cout << "Double division: " << this->x << "/" << this->y << " = " << z << endl;
}

Fraction::~Fraction()
{
	cout << "Default destructor" << endl;
}

void Subtraction(Fraction & a, Fraction & b)
{
	int c = a.y*b.y;
	int y_a = c / a.y;
	int y_b = c / b.y;
	int x_a = a.x * y_a;
	int x_b = b.x * y_b;
	int x_ab = x_a - x_b;
	int z = a.Reduction(x_ab, c);
	if ((c / z) < 0)
	{
		cout << "Substraction: " << (x_ab / z)*(-1) << "/" << (c / z)*(-1) << endl;
	}
	else
	{
		cout << "Substraction: " << x_ab << "/" << c / z << endl;
	}
	
}
