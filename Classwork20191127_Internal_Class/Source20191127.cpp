#include <iostream>
#include <string>

using namespace std;

class Train {
public:
	Train() {
		cout << "Default train constructor." << endl;
	}
	Train(string route, int distance, int sizeCar) {
		this->route = route;
		this->distance = distance;
		this->sizeCar = sizeCar;
		this->car = new Car[sizeCar];
		this->FillCar(this->sizeCar);
		cout << "Overload train constructor." << endl;
	}
	void ShowTrain() {
		cout << "========================================================" << endl;
		cout << "ROUTE: " << this->route << "\nDISTANCE: " << this->distance <<"\nTHERE ARE "<<sizeCar<<" CARS IN TOTAL: "<< endl;
		for (int i = 0; i < sizeCar; i++)
		{
			cout <<"NUMBER OF CAR: "<< i + 1<<" ";
			car[i].ShowCar();
		}
		cout << "========================================================" << endl;
	}

	string GetRoute()
	{
		return route;
	}
	void SetRoute(string route)
	{
		this->route = route;
	}
	int GetDistance()
	{
		return distance;
	}
	void SetDistance(int distance)
	{
		this->distance = distance;
	}


	void FillCar(int carSize)
	{
		string type;
		int passengers;
		for (int i = 0; i < carSize; i++)
		{
			cout << "Enter type car: ";
			cin >> type;
			cout << "Enter number of passengers: " << endl;
			cin >> passengers;
			car[i] = Car(type, passengers);
		}


	}

private:

	class Car {
	private:
		string type;
		int passengers;
	public:

		//constructors:
		Car() {
			cout << "Default car constructor. " << endl;
		}
		Car(string type, int passengers) {
			this->type = type;
			this->passengers = passengers;
			cout << "Overload car constructor. " << endl;
		}
		//Metody: 
		void ShowCar() {
			cout << "Type: " << this->type << "\tPassengers: " << this->passengers << endl;
		}
		void SetType(string type)
		{
			this->type = type;
		}
		string GetType()
		{
			return type;
		}

		void SetPassengers(int passengers)
		{
			this->passengers = passengers;
		}
		int GetPassengers()
		{
			return passengers;
		}

		
		~Car()
		{
			cout << "Destructor Car" << this << endl;
		};

	};


	string route;
	int distance;
	int sizeCar;
	Car *car;

public:
	~Train()
	{
		car = nullptr;
		delete[] car;
		cout << "Destructor Destructor Train" << this << endl;
	};

};

int main() {

	/*Train polissya("Rivne - Lviv", 210, "Lux", 200);
	polissya.ShowTrain();*/

	const int SIZE = 3;


	/*Train trains[SIZE]{
		Train("Rivne - Lviv", 210, "Lux", 200),
		Train("Charkiv - Uzgorod", 1110, "Lux", 210),
		Train("Kyiv - Odessa ", 610, "DeLux", 400)
	};
	for (int i = 0; i < SIZE; i++) {
		trains[i].ShowTrain();
	}*/

	cout << "**************************************" << endl;
	cout << "**************************************" << endl;

	int size;
	int carSize;
	string route;
	int distance;
	cout << " ============== Enter number of trains =====>>>>> ";
	cin >> size;
	Train *trains1 = new Train[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter route: ";
		cin >> route;
		cout << "Enter distance: ";
		cin >> distance;
		cout << "Enter number of Cars: " << endl;
		cin >> carSize;
		trains1[i] = Train (route, distance, carSize);
	}
	cout << "----------------------- LIST OF TRAINS: ----------------------- " << endl;
	for (int i = 0; i < size; i++)
	{
		trains1[i].ShowTrain();
	}
	cout << "----------------------- LIST OF TRAINS: ----------------------- " << endl;

	trains1 = nullptr;
	delete[] trains1;

	system("pause");
	return 0;
}