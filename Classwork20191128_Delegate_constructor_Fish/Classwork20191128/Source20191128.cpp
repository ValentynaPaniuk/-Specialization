#include "Windows.h"
#include <iostream>
#include <string>
#include <ctime>
#include "Fish.h"

using namespace std;
/*Завдання 3.
////////Створити клас Риба з наступними полями
/////// координати (х, у)
/////// поле здоров’я( чим більше значення, тим більш сита риба); при значенні 0 риба
помирає
статичними полями :
/////// океан(озеро), де можуть переміщатися екземпляри класу Риба : двовимірний масив
/////// число живих екземплярів риб
та методами:
/////// конструктор(и)
 метод зображення риби
 метод приховування риби
 метод переміщення риби
///////Протестувати роботу класу: створити декілька екземплярів риб, помістити їх у &quot;океан&quot;
/////// вивести на екран кількість екземплярів риб.
Передбачити переміщення риб по &quot;океану&quot;. З кожним переміщенням почуття голоду риб
росте(здоров’я зменшується).
*Удосконалити клас Риба . У &quot;океані&quot; &quot;ростуть&quot; водорості. Риби збільшують своє
здоров’я, якщо при переміщенні натрапляють на водорість.*/

bool gamerunning = true;

int main()
{
	srand(unsigned(time(NULL)));
	string nameFish;
	int x, y, health;
	Fish fish;
	
	/*cout << "Name: ";
	cin >> nameFish;
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	cout << "Health: ";
	cin >> health;*/

	Fish fish1("Karp", 5,3,8);
	fish1.MovementFish();

	/*cout << "Name: ";
	cin >> nameFish;
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	cout << "Health: ";
	cin >> health;*/

	Fish fish2("Schuka", 3, 4, 15);
	fish2.MovementFish();

	/*cout << "Name: ";
	cin >> nameFish;
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	cout << "Health: ";
	cin >> health;*/

	Fish fish3("Delphin", 2, 3, 11);
	fish3.MovementFish();

	/*cout << "Name: ";
	cin >> nameFish;
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;
	cout << "Health: ";
	cin >> health;*/

	Fish fish4("Karas", 5, 8, 12);
	fish4.MovementFish();
	Fish::PrintOcean();


	cout << "*****************" << endl;
	/*int ID = fish4.GetID();
	Fish *arr = new Fish [ID];
	for (int i = 0; i < ID; i++)
	{
		arr[i].MovingFish();
		arr[i].PrintOcean();
	}*/
	
	fish1.ShowInfoFish();
	fish2.ShowInfoFish();
	fish3.ShowInfoFish();
	fish4.ShowInfoFish();
	cout << "All fishes: " << fish4.GetID() << endl;
	cout << "=======================================" << endl;

	//int ID = fish4.GetID();
	//Fish *fish = new Fish[ID];
	//while (gamerunning)
	//{
	//	system("cls");
	//	for (int i = 0; i < 10; i++)
	//	{
	//		cout<< ocean[i] << endl;
	//	}
	//	system("pause > nul");
	//	if (GetAsyncKeyState(VK_UP))
	//	{
	//		fish.MoveFish(1, 0);
	//	}
	//	if (GetAsyncKeyState(VK_DOWN))
	//	{
	//		fish.MoveFish(-1, 0);
	//	}
	//	if (GetAsyncKeyState(VK_RIGHT))
	//	{
	//		fish.MoveFish(0, 1);
	//	}
	//	if (GetAsyncKeyState(VK_LEFT))
	//	{
	//		fish.MoveFish(0, -1);
	//	}
	//}
	

	system("pause");
	return 0;
}