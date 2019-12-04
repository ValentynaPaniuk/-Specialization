#include "Var.h"



Var::Var()
{
}

Var::Var(int a, double b, string c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

Var::Var(int a)
{
	this->a = a;
}

Var::Var(double b)
{
	this->b = b;
}

Var::Var(string c)
{
	this->c = c;
}

int Var::GetA()
{
	return a;
}

double Var::GetB()
{
	return b;
}

string Var::GetC()
{
	return c;
}

void Var::SetA(int a)
{
	this->a = a;
}

void Var::SetB(double b)
{
	this->b = b;
}

void Var::SetC(string c)
{
	this->c = c;
}

Var & Var::operator+(const Var & other)
{
	if (this->Type == other.)
	
	return *this;
}


Var::~Var()
{
}
