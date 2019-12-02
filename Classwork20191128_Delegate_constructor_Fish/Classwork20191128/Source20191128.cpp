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
	int x;
	int y;
	int health = 10;
	int famine = 10;
	

	Fish fish1("Karp", 5,3,8);
	Fish fish2("Schuka", 3, 4, 15);
	Fish fish3("Delphin", 2, 3, 11);
	Fish fish4("Karas", 5, 8, 12);
	


	cout << "*****************" << endl;
		
	for (int choise =0; choise = 150; choise++)
	{
		system("cls");
			
		fish1.MovingFish();
		fish1.SetHealth(health);
		fish1.SetFamile(famine);
		
		fish2.MovingFish();
		fish2.SetHealth(health);
		fish2.SetFamile(famine);
		
		fish3.MovingFish();
		fish3.SetHealth(health);
		fish3.SetFamile(famine);
		
		fish4.MovingFish();
		fish4.SetHealth(health);
		fish4.SetFamile(famine);
		
		
		Fish::PrintOcean();
		

		cout << "=======================================" << endl;
		fish1.ShowInfoFish();
		fish2.ShowInfoFish();
		fish3.ShowInfoFish();
		fish4.ShowInfoFish();
		system("pause");
		//Sleep(60);
	}
	cout << "All fishes: " << fish4.GetID() << endl;
	
	


	system("pause");
	return 0;
}