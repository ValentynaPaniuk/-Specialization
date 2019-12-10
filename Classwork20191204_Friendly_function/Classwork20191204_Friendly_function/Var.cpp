#include "Var.h"
#include <sstream>
#include <string>



Var::Var()
{
	cout << "Default constructor" << this << endl;
}


Var::Var(int a)
{
	this->a = a;
	this->type = 'i';
	cout << "Overload constructor Int" << this << endl;
}

Var::Var(double b)
{
	this->b = b;
	this->type = 'd';
	cout << "Overload constructor Double" << this << endl;
}

Var::Var(string c)
{
	this->c = c;
	this->type = 's';
	cout << "Overload constructor String" << this << endl;
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
	if ((this->type == 'i' && other.type == 'i'))
	{
		this->a += other.a;
	}

	if ((this->type == 'd' && other.type == 'd'))
	{
		this->b += other.b;
	}
	
	if ((this->type == 's' && other.type == 's'))
	{
		this->c += other.c;
	}

	//========= Int ==============================
	if (this->type == 'i' && other.type == 'd')
	{
		this->a += (int(other.b));
		cout << "Int A + Double B = " << this->a << endl;
		cout << endl;
	}

	if (this->type == 'i' && other.type == 's')
	{
		/*stringstream geek(other.c);
		int x = 0;
		geek >> x;*/
		int x = stoi(other.c);
		cout << "INT C FROM STRING C(number) = " << x << endl;;
		this->a += x;
		cout << "int A + String C = " <<this->a << endl;
		cout << endl;
	}
	//========= Int ==============================

	// =============  Double ===================
	
	if (this->type == 'd' && other.type == 'i')
	{
		this->b += (double(other.a));
		cout << "Double B + Int A = " << this->b << endl;
		cout << endl;
	}

	if (this->type == 'd' && other.type == 's')
	{
		stringstream stream;
		double x = 0;
		stream<<x;
		
		cout << "Double C from STRING C(number) = " << x << endl;;
		this->b = this->b + x;
		cout << "Double B + String C = " << this->b << endl;
		cout << endl;
	}

	// =============  Double ===================

	// ======== String =========================================

	if (this->type == 's' && other.type == 'i')
	{
		this->c += (to_string(other.a));
		cout << "String C + Int A = " << this->c << endl;
		cout << endl;
	}

	if (this->type == 's' && other.type == 'd')
	{
		string x = to_string(other.b);
		cout << "STRING C from DOUBLE C " << x << endl;
		this->c += (to_string(other.b));
		cout << "Double B + String C = " << this->c << endl;
		cout << endl;
	}



	
	return *this;
}

Var & Var::operator-(const Var & other)
{
	if ((this->type == 'i' && other.type == 'i'))
	{
		this->a -= other.a;
	}

	if ((this->type == 'd' && other.type == 'd'))
	{
		this->b -= other.b;
	}

	if ((this->type == 's' && other.type == 's'))
	{
		cout << "We cannot subtract words" << endl;
	}

	//========== int ======================
	if (this->type == 'i' && other.type == 'd')
	{
		this->a -= (int(other.b));
		cout << "int A - double B= " << this->a << endl;
		cout << endl;
	}

	if (this->type == 'i' && other.type == 's')
	{
		stringstream geek(other.c);
		int x = 0;
		geek >> x;

		/*int x = stoi(other.c);*/
		cout << "Int C from STRING C(number) = " << x << endl;;
		this->a -= x;
		cout << "int A - string C = " << this->a << endl;
		cout << endl;
	}
	//========== int ======================
	// =============  Double ===================

	if (this->type == 'd' && other.type == 'i')
	{
		this->b -= (double(other.a));
		cout << "Double B - Int A = " << this->b << endl;
		cout << endl;
	}

	if (this->type == 'd' && other.type == 's')
	{
		stringstream stream;
		double x = 0;
		stream << x;

		cout << "Double C from STRING C(number) = " << x << endl;;
		this->b = this->b - x;
		cout << "Double B - String C = " << this->b << endl;
		cout << endl;
	}
	// =============  Double ===================
	   	  
	return *this;
}

Var & Var::operator*(const Var & other)
{
	if ((this->type == 'i' && other.type == 'i'))
	{
		this->a *= other.a;
	}

	if ((this->type == 'd' && other.type == 'd'))
	{
		this->b *= other.b;
	}

	if ((this->type == 's' && other.type == 's'))
	{
		cout << "	We cannot multiply words" << endl;
	}

	if (this->type == 'i' && other.type == 'd')
	{
		this->a *= (int(other.b));
		cout << "int A * double B= " << this->a << endl;
		cout << endl;
	}

	if (this->type == 'i' && other.type == 's')
	{
		stringstream geek(other.c);
		int x = 0;
		geek >> x;

		/*int x = stoi(other.c);*/
		cout << "Int C from string C(number) = " << x << endl;
		this->a *= x;
		cout << "int A * string C = " << this->a << endl;
		cout << endl;
	}

	// =============  Double ===================

	if (this->type == 'd' && other.type == 'i')
	{
		this->b *= (double(other.a));
		cout << "Double B * Int A = " << this->b << endl;
		cout << endl;
	}

	if (this->type == 'd' && other.type == 's')
	{
		stringstream stream;
		double x = 0;
		stream << x;

		cout << "Double C from STRING C(number) = " << x << endl;;
		this->b = this->b * x;
		cout << "Double B * String C = " << this->b << endl;
		cout << endl;
	}
	// =============  Double ===================

	   
	return *this;
}

Var & Var::operator/(const Var & other)
{
	if ((this->type == 'i' && other.type == 'i'))
	{
		this->a /= other.a;
	}

	if ((this->type == 'd' && other.type == 'd'))
	{
		this->b /= other.b;
	}

	if ((this->type == 's' && other.type == 's'))
	{
		cout << "We can't share words" << endl;
	}

	if (this->type == 'i' && other.type == 'd')
	{
		this->a /= (int(other.b));
		cout << "int A / double B= " << this->a << endl;
		cout << endl;
	}

	if (this->type == 'i' && other.type == 's')
	{
		stringstream geek(other.c);
		int x = 0;
		geek >> x;
		cout << "X=" << x << endl;
		if (x != 0)
		{

			cout << "Int C from string C(number) = " << x << endl;
			this->a /= x;
			cout << "int A / string C = " << this->a << endl;
		}
		else if (x <= 0)
		{
			cout << "Error!It is impossible to divide by zero" << endl;
		}
		cout << endl;
	}




	return *this;
}

Var & Var::operator<(const Var & other)
{
	if ((this->type == 'i' && other.type == 'i'))
	{
		this->a > other.a;
		cout << this->a << " > " << other.a << endl;
	}

	if ((this->type == 'd' && other.type == 'd'))
	{
		this->b > other.b;
	}

	if ((this->type == 's' && other.type == 's'))
	{
		this->c > other.c;
	}


	return *this;

}


Var::~Var()
{
	cout << "Default destructor" << this << endl;
}
