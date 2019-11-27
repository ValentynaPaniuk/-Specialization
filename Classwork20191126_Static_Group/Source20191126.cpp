#include <iostream>
#include <string>
#include <ctime>
#include "Student.h"
#include "Group.h"
using namespace std;
/*ООП
Створити клас Group ("Група"), що містить в собі наступні поля:
- назва групи
- курс
- назва спеціальності (char *)
- масив студентів, що також описаний окремим класом Student.
Даний клас містить набір методів, що дозволяють:
- здійснити модифікацію окремих полів класу (назви групи, курсу та спеціальності)
- вивести інформацію про групу вцілому
- змінювати інформацію про студентів.*/


int main()
{
	//Group group1("34C9", "Developer", 1, 4);
	//group1.ShowInfoGroup();
	Group group2("123","Grafic", 2, 3);
	group2.ShowInfoGroup();
	group2.ChangeStudentInfo();
	group2.ShowInfoGroup();

	 
	

	system("pause");
	return 0;
}