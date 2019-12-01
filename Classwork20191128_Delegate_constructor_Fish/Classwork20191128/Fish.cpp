#include "Fish.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/*Завдання 3.
Створити клас Риба з наступними полями
////// координати (х, у)
 поле здоров’я( чим більше значення, тим більш сита риба); при значенні 0 риба
помирає

статичними полями :
/////// океан(озеро), де можуть переміщатися екземпляри класу Риба : двовимірний масив
///////  число живих екземплярів риб

та методами:
 конструктор(и)
 метод зображення риби
 метод приховування риби
 метод переміщення риби
Протестувати роботу класу: 

створити декілька екземплярів риб, помістити їх у &quot;океан&quot;,
//////// вивести на екран кількість екземплярів риб.
Передбачити переміщення риб по &quot;океану&quot;. З кожним переміщенням почуття голоду риб
росте(здоров’я зменшується).
*Удосконалити клас Риба . У &quot;океані&quot; &quot;ростуть&quot; водорості. 
Риби збільшують своє здоров’я, якщо при переміщенні натрапляють на водорість.*/

int Fish :: counter = 0;
int Fish::ocean[10][10];


void Fish::MovementFish()
{
	bool curseX = rand() % 3;
	bool curseY = rand() % 3;
	if (curseX == true)
	{
		this->curseX++;
	}
	else 
	{
		this->curseX--;
	}
	if (curseY == true)
	{
		this->curseY++;
	}
	else
	{
		this->curseY--;
	}
}

void Fish::UpdateHealth()
{
	health--;
}

void Fish::UpdateFamile()
{
	famine++;
}

void Fish::UpdateX()
{
	this->x = rand() % 10 + 1;
	
}

void Fish::UpdateY()
{
	
	this->y = rand() % 10 + 1;
}




Fish::Fish()
{
}

Fish::Fish(string nameFish, int x, int y, int health)
{
	this->nameFish = nameFish;
	counter++;
	ID = counter;
	this->x = x;
	this->y = y;
	this->health = health;
	this->fish = new Fish[this->ID];
	
	
}

void Fish::ShowInfoFish()
{
	cout << nameFish <<" \t\t\t"<< GetID() <<" "<<" coordinates: " << "(" << x << ";" << y << ")   Health: " << health << endl;
}


int Fish::GetID()
{
	return ID;
}

int Fish::GetX()
{
	return x;
}

int Fish::GetY()
{
	return y;
}

void Fish::SetHealth(int health)
{
	UpdateHealth();
}

void Fish::SetFamile(int famine)
{
	UpdateFamile();
}

void Fish::SetX(int x)
{
	UpdateX();
}

void Fish::SetY(int y)
{
	UpdateY();
}




//this->x = rand() % 10 + 1;
//this->y = rand() % 10 + 1;


void Fish::MovingFish()
{
	srand(unsigned(time(NULL)));
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			
			if (i == this->x && j == this->y)
			{
				this->ocean[i][j] = ID;
			}
		}
			
	}
	cout << endl;
		
}

void Fish::MoveFish(int V, int H)
{
	int y2 = y + V;
	int x2 = x + H;
	if (ocean[y][x2] == 0)
	{
		ocean[y][x] = 0;
		x += H;
		ocean[y][x] = ID;
	}
	if (ocean[y2][x] == 0)
	{
		ocean[y][x] = 0;
		x += V;
		ocean[y][x] = ID;
	}

}

void Fish::goForward(Fish *fish)
{
	for (int i = 0; i < 9; i++)
	{
		cout << fish[i + 1].GetX() << "," << fish[i + 1].GetY();
	}
}

void Fish::goBack(Fish * fish)
{
	for (int i = 9; i > 1; i--)
	{
		cout << fish[i - 1].GetX() << "," << fish[i - 1].GetY() << endl;
	}
}


int Fish::GetCounter()
{
	return counter;
}

void Fish::PrintOcean()
{
		for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
		{

			cout << ocean[i][j] << " ";
		
			
		}
		cout << endl;
	}
	
}





Fish::~Fish()
{
}
