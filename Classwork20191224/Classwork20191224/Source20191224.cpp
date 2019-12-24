#include <iostream>
#include<string>
using namespace std;


//Agregacia - koly dva classy okremo
class Fuel {

private:
	string fuel = "Diesel";
public:
	string GetFuel()
	{
		return this->fuel;
	}

};


//Compozycia - koly vkladenyi class
class Car {
public:
	void Drive()
	{
		TDI.Drive();
	}

	void GassStation()
	{
	cout<<diesel.GetFuel()<<endl;
	}

private:
	class Engine
	{
	public:

		void Drive()
		{
			cout << "Drive..." << endl;
		}
	
	};
	
	Engine TDI;
	Fuel diesel;

};




int main()
{

	Car car;
	car.Drive();
	car.GassStation();


	system("pause");
	return 0;
}
