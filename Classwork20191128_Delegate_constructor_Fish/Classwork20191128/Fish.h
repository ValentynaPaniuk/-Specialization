#pragma once
#include <iostream>
/*Завдання 3.
Створити клас Риба з наступними полями
 координати (х, у)
 поле здоров’я( чим більше значення, тим більш сита риба); при значенні 0 риба
помирає
статичними полями :
 океан(озеро), де можуть переміщатися екземпляри класу Риба : двовимірний масив
 число живих екземплярів риб

та методами:
 конструктор(и)
 метод зображення риби
 метод приховування риби
 метод переміщення риби
Протестувати роботу класу: створити декілька екземплярів риб, помістити їх у &quot;океан&quot;,
вивести на екран кількість екземплярів риб.
Передбачити переміщення риб по &quot;океану&quot;. З кожним переміщенням почуття голоду риб
росте(здоров’я зменшується).
*Удосконалити клас Риба . У &quot;океані&quot; &quot;ростуть&quot; водорості. Риби збільшують своє
здоров’я, якщо при переміщенні натрапляють на водорість.*/

using namespace std;

class Fish
{
	string nameFish;
	int ID;
	int x;
	int y;
	int curseX;
	int curseY;
	int health;
	int famine;
	Fish *fish;

	
	
	static int ocean[10][10];
	static int counter;


	void UpdateHealth();
	void UpdateFamile();
	void UpdateX();
	void UpdateY();
	


public:
	Fish();
	Fish(string nameFish, int x, int y, int health);
	void ShowInfoFish();
	int GetID();
	int GetX();
	int GetY();

	void SetHealth(int health);
	void SetFamile(int famine);
	void SetX(int x);
	void SetY(int y);

	void HidingFish();
	void ProblemFish();
	void MovingFish();
	void MovementFish();


	
	static int GetCounter();
	static void PrintOcean();


	~Fish();
};


