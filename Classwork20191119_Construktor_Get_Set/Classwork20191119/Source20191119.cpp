#include <iostream>
#include <string>
#include "Player.h"
#include "Account.h"
# include <ctime>;
using namespace std;


/*ООП
Написати клас "Карточка на знижку", який містить наступну інформацію:
Номер карточки
Розмір знижки (знижка передбачається накопичуваною; на початковому етапі вона рівна 1%. За кожні 1000 грн. покупки, сума знижки збільшується на 1%.)
Приховане допоміжне поле для збереження вартості накупленого товару
Забезпечити можливість:
Купляти товар з використанням карточки на знижку
Виводити інформацію про поточну величину знижки
Виводити інформацію про те, на яку суму ще необхідно докупити товару, щоб величина знижки збільшилась. */

int main() {
	srand(unsigned(time(NULL)));

	Player ronaldo("Cristiano Ronaldo", "Portugal", "Juventus", "Forward", 600, 20000000, 100000000);
	ronaldo.ShowPlayer();

	int goals = ronaldo.GetGoals();
	cout << "Ronaldo goals = > " << goals << endl;
	ronaldo.SetGoals(1);
	ronaldo.ShowPlayer();
	ronaldo.SetGoals(1);
	ronaldo.SetGoals(1);
	ronaldo.SetGoals(1);
	ronaldo.SetGoals(1);
	ronaldo.SetGoals(1);
	ronaldo.SetGoals(13);
	ronaldo.ShowPlayer();


	/*Player yarmolenko("Andrii Yarmolenko", "Ukraine", "West Ham", "Forward", 150, 5000000, 20000000);
	yarmolenko.ShowPlayer();

	Player maradonna;
	maradonna.ShowPlayer();*/


	//SPlayer test;

	cout << "\n\n==============   Exersice 2:===================" << endl;
	unsigned int number1 = rand()%10000+15000;
	double discount1 = 1;
	double cost1 = 0;
	double summa1 = 0;
	double maxSumma1 = 5000;

	Account card(number1, discount1, cost1, summa1, maxSumma1);
	card.ShowAccount();
	card.CostOfDiscount(number1, discount1, cost1, summa1, maxSumma1);




	system("pause");
	return 0;
}
