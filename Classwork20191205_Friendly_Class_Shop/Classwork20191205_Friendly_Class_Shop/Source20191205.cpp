#include <iostream>
#include <string>
#include "Shop.h"
#include "Book.h"
#include "AudioDisk.h"
#include "Magazine.h"
using namespace std;
/*ООП
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
Виводити нові книги, журнали і/або аудіо диски. */

int main()
{
	Book book1("Kobzar", "Shevchenko", 400, 2018, 328);
	Book book2("Azbuka", "Narod", 50, 2011, 120);
	Book book3("Education", "RSGU", 100, 2019, 100);
	
	Book *books = new Book[Book::GetCounterBook()];
	books[0] = book1;
	books[1] = book2;
	books[2] = book3;
	
	Magazine magazine1("Vogue", "Svitanok", 60, 2017, 60);
	Magazine magazine2("Natali", "Ranok",50, 2019, 100);
	Magazine magazine3("Maliatko", "Svitanok", 30, 2019, 40);

	Magazine *magazines = new Magazine[Magazine::GetCounterMagazine()];
	magazines[0] = magazine1;
	magazines[1] = magazine2;
	magazines[2] = magazine3;

	
	AudioDisk disk1("English", "Paisadini", 2019, 200);
	AudioDisk disk2("Polish", "Paisadini", 2018, 180);
	AudioDisk disk3("Franch", "Paisadini", 2017, 170);

	AudioDisk *disks = new AudioDisk[AudioDisk::GetCounterDisk()];
	disks[0] = disk1;
	disks[1] = disk2;
	disks[2] = disk3;

	
	Shop shop1("SLOVO", "Soborna 255", 3000);
	shop1.ShovInfoShop();
	shop1.AllBooks(books, Book::GetCounterBook());
	shop1.AllMagazine(magazines, Magazine::GetCounterMagazine());
	shop1.AllDisk(disks, AudioDisk::GetCounterDisk());

	shop1.MostExpensivePriceBook(books, Book::GetCounterBook());
	shop1.MostExpensivePriceMagazine(magazines, Magazine::GetCounterMagazine());
	shop1.MostExpensivePriceDisk(disks, AudioDisk::GetCounterDisk());

	shop1.TheCheapestPriceBook(books, Book::GetCounterBook());
	shop1.TheCheapestPriceMagazine(magazines, Magazine::GetCounterMagazine());
	shop1.TheCheapestPriceDisk(disks, AudioDisk::GetCounterDisk());

	shop1.AveragePriceBook(books, Book::GetCounterBook());
	shop1.AveragePriceMagazine(magazines, Magazine::GetCounterMagazine());
	shop1.AveragePriceDisk(disks, AudioDisk::GetCounterDisk());



	system("pause");
	return 0;
}