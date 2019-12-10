﻿#include<iostream>
#include<string>
#include "Book.h"
#include "Disk.h"
#include"Magazine.h"
#include "CShop.h"

using namespace std;
/*
ООП
Постановка задачі
Є магазин "Веселка". В даному магазині продається наступна продукція:
книжки;
журнали;
аудіо диски.
Всі три види продукції представлені відповідними класами: Книга (Book), Журнал (Megazine), Аудіо диск (Audio). Програма має виводити наступні результати:
Виводити інформацію про всі книги, журнали і/або аудіо диски.
Виводити інформацію про найдорожчу книжку, журнал і/або аудіо диск.
Виводити інформацію про найдешевшу книжку, журнал і/або аудіо диск.
Виводити середню ціну книг, журналів і/або аудіо дисків.
Виводити нові книги, журнали і/або аудіо диски.
Хід розв’язку задачі
Необхідно створити шаблонний клас "CShop" (Магазин), який працює як звичайний шаблонний масив будь-якого типу та містить:
поля:
вказівник на тип масиву;
розмір масиву.
дадаткові методи:
пошук мінімального та максимального елемента масиву;
метод для сортування елементів масиву по зростанню або спаданню (наприклад, по ціні; на 12 балів);
метод для пошуку середнього арифметичного всіх елементів масиву;
/////////////////////////////////////////// перенавантажити оператор індексування.
Необхідно також створити наступний набір класів:
Книгa (Book), яка містить наступні поля:
назва книги;
видавництво;
автор;
ціна;
булівське поле, яке вказує чи книга є нова: true – нова, false – ні.
Журнал (Megazine), який містить наступні поля:
назва журналу;
ціна;
булівське поле, яке вказує чи журнал є новим: true – новий, false – ні.
Аудіо диск (Audio), який має містити наступні поля:
назва диску;
виконавець;
кількість треків;
ціна;
булівське поле, яке вказує чи аудіо диск є новим: true – новий, false – ні.
Для кожного класу написати необхідний набір методів.
В основній програмі, створити 3 об’єкти шаблонного класу "Магазин" для допустимих в програмі типів (Книги, Журнал, Аудіо диски). В результаті код набуде наступного вигляду: 

*/


int main()
{
	CShop<Book> shop(3);
	shop.ShowAll();
	cout << "Sorting max-min==============>>" << endl;
	shop.SortMaxMinElement();
	cout << "<<=================Sorting max-min=" << endl;
	
	cout << "Sorting min-max ==============>>" << endl;
	shop.SortMinMaxElement();
	cout << "Sorting min-max ==============>>" << endl;
	shop.AveragePrice();
	shop.MostExpensive();


	system("pause");
	return 0;
}