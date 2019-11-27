#include <iostream>
#include <string>
#include <ctime>
#include "Int.h"

using namespace std;

int main()
{
	Int a(5);
	Int b(6);
	a.PrintNumber();
	b.PrintNumber();

		Int c;
	bool exit = false;
	int choise;
	while (!exit)
	{
		a.FillNumber();
		b.FillNumber();
		cout << "Enter choise: \n1 -Addition\t2 - Subtraction\t3 - Multiplication\t4 - Divisin, \t0 - Exit" << endl;
		cin >> choise;

		switch (choise)
		{
		case 1:
		{
			cout << a.GetA() << " + " << b.GetA() ;
			c.SetA(c.Addition(a, b));
			c.PrintNumber();


			break;
		}
		case 2:
		{
			cout << a.GetA() << " - " << b.GetA() ;
			c.SetA(c.Subtraction(a, b));
			c.PrintNumber();
			break;
		}
		case 3:
		{
			cout << a.GetA() << " * " << b.GetA();
			c.SetA(c.Multiplication(a, b));
			c.PrintNumber();
			break;

		}
		case 4:
		{
			cout << a.GetA() << " / " << b.GetA();
			c.SetA(c.Division(a, b));
			c.PrintNumber();
			break;
		}
		case 0:
		{
			cout << "Happy End" << endl;
			exit = true;
			break;
		}
		default:
		{
			cout << "ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		}
		}
	}

	cout << "\n ===========================================" << endl;
	Int s(a);
	Int d(b);
	Int i;
	cout << "**************  COPY CONSTRUCTOR ***********************" << endl;
	cout << "Enter choise: 1 -Addition\t2 - Subtraction\t3 - Multiplication\t4 - Divisin" << endl;
	cin >> choise;
	switch (choise)
	{
	case 1:
	{
		cout << s.GetA() << " + " << d.GetA() << endl;
		i.SetA(i.Addition(s, d));
		i.PrintNumber();


		break;
	}
	case 2:
	{
		cout << s.GetA() << " - " << d.GetA() << endl;
		i.SetA(i.Subtraction(s, d));
		i.PrintNumber();
		break;
	}
	case 3:
	{
		cout << s.GetA() << " * " << d.GetA() << endl;
		i.SetA(i.Multiplication(s, d));
		i.PrintNumber();
		break;

	}
	case 4:
	{
		cout << s.GetA() << " / " << d.GetA() << endl;
		i.SetA(i.Division(s, d));
		c.PrintNumber();
		break;
	}
	default:
	{
		cout << "ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
	}
	}

	

	system("pause");
	return 0;
}