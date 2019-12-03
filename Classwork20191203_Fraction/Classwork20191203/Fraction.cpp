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
	cout << this->x << "/" << this->y << endl;
}

int Fraction::Reduction(int x, int y)
{
	while (y) 
	{
		int tmp = y;
		y = x % y;
		x = tmp;
		
	}
	cout << "Greatest common factor: " << x << endl;
	return x;
}



Fraction & Fraction::operator*(const Fraction & other)
{

	this->x*=other.x;
	this->y *= other.y;

	return *this;
}




void Fraction::IntDivision()
{
	cout <<"Int division = "<< this->x<<"/"<< this->y<<" = "<< (this->x / this->y) << endl;
}

void Fraction::DoubleDivision()
{
	double z = (double(this->x) / double(this->y));
	cout << "Double division = " << this->x << "/" << this->y << " = " << z << endl;
}

Fraction::~Fraction()
{
	cout << "Default destructor" << endl;
}
