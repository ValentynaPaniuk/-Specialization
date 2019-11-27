#include "Int.h"
#include <iostream>
using namespace std;


int Int::Addition(Int &amp1, Int &amp2)
{
	return (amp1.a+amp2.a);
}

int Int::Subtraction(Int &amp1, Int &amp2)
{
	
	return (amp1.a - amp2.a);
}

int Int::Multiplication(Int &amp1, Int &amp2)
{
	
	return (amp1.a * amp2.a);
}

int Int::Division(Int &amp1, Int &amp2)
{
	
	
	if (amp2.a != 0)
	{
		return (amp1.a / amp2.a);
	}
	else
	{
		cout << "Error!!!" << endl;
	}
}


Int::Int()
{
	cout << "Int Default construcror " << endl;
}

Int::Int(int a)
{
	cout << "Overload constructor." << endl;
	this->a = a;

}

Int::Int(const Int &other) //Конструктор копій
{
	this->a = other.a;
	cout << "Copy constructor" << endl;
}


Int::~Int()
{
	cout << "Int Defauil Destructor " << endl;
}

int Int::GetA()
{
	return a;
}

void Int::SetA(int a)
{
	this->a = a;
}

void Int::FillNumber()
{
	cout << "Enter number A: " << endl;
	cin >> this->a;
}

void Int::PrintNumber()
{
	cout <<" = "<< this->a << endl;
}

