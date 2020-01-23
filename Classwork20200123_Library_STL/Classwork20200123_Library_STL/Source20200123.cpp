#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> vArr;
	vArr.push_back(6); //Add new element
	vArr.push_back(12);
	vArr.push_back(24);
	vArr.push_back(48);
	vArr.push_back(96);

	vArr.pop_back(); //delete one element;
	cout << "Size vArr: " << vArr.size() << endl;
	vArr.clear(); // Chystymo masyv
	cout << "Size vArr after Clear: " << vArr.size() << endl;

	vArr.push_back(2);
	vArr.push_back(4);
	vArr.push_back(8);
	vArr.push_back(16);
	vArr.push_back(32);
	cout << "Size vArr: " << vArr.size() << endl;

	cout << "***************** " << endl;
	for (int i = 0; i < vArr.size(); i++)
	{
		cout << "vArr[ " << i << " ] = " << vArr[i] << endl;
	}
	cout << "***************** "<<endl;

	//Vyvid masyva
	for (int i = 0; i < vArr.size(); i++)
	{
		cout << vArr.at(i) << endl;
	}
	vArr.clear();
	vArr.reserve(50);//Vydiliaemo pamiat pid 50 elementiv
	cout << "Size vArr: " << vArr.size() << endl; // Skilki zapovnenyh conteyneriv
	cout << "Zarezervovano conteyneriv: " << vArr.capacity() << endl; // Skilki conteyneriv
	/*1*/ vArr.push_back(3);
	/*2*/ vArr.push_back(6);
	/*3*/ vArr.push_back(9);
	/*4*/ vArr.push_back(12);
	/*5*/ vArr.push_back(15);
	/*6*/ vArr.push_back(18);

	for (int i = 0; i < vArr.size(); i++)
	{
		cout << vArr.at(i) << endl;
	}

	cout << "Size vArr after zapovnennia: " << vArr.size() << endl; // Skilki zapovnenyh conteyneriv
	cout << "Zarezervovano conteyneriv after zapovnennia: " << vArr.capacity()<<endl; // Skilki conteyneriv
	//vArr.at(10) = 100; - pomylka

	/**************************************************************************/

	cout << " ****  ITERATOR ***** " << endl;
	/*vector<int>::iterator i;
	i = vArr.begin();
	i += 2;
	cout << "Iterator test: " << *i << endl;*/

	for (vector<int>::const_iterator i = vArr.begin(); i < vArr.end(); i++)
	{
		//*i = 10; // iakscho iterator CONST_ITERATOR
		vArr.at(1) = 100;
		cout <<"Znachennia komirky: "<< *i << endl;
	}

	cout << "\n *** Oberbneno vyvodymo chysla: " << endl;
	for (vector<int>::reverse_iterator i = vArr.rbegin(); i < vArr.rend(); i++)
	{
		//*i = 10; // iakscho iterator CONST_ITERATOR
		vArr.at(1) = 100;
		cout << "Znachennia komirky: " << *i << endl;
	}


	
	system("pause");
	return 0;
}