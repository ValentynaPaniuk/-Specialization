#include <iostream>
#include <string>
#include <memory>

using namespace std;
/*Дано рядок(С або С++ на вибір). 
Перевірити чи він містить вірно записану IP-адресу.
Використати рядкові потоки. 
Наприклад, 255.255.255.0 - вірна, 
		   255.255.0.256, 
		   192.0.157 – невірні.
*/


int main()
{
	bool exit = false;
	char text[255];
	int x = 0, y = 0;
	cout << "************* EXERCISE 1 ********************" << endl;
	while (!exit)
	{
		cout << "Enter IP-address: ";
		cin >> text;
		for (int i = 0; i < strlen(text); i++)
		{
			
			if (int(text[i]) != 46)
			{
				y += int(text[i]);
				/*cout << "\nY = " << y << endl;*/
				if (y >= 50 && y <= 156 || y >= 206 && y <= 312  ||  y >= 362  && y <= 468 || y >= 516)
				{
					cout << "\n" << text[i] << " ";
					exit = true;
				}
				else
				{
					cout << "Not correact" << endl;
				}

				

			}



			/*else if (int(text[i]) == 46)
			{
				x++;
				cout << "\nX (.) = " << x << " " << endl;

			}*/

			
		}
		cout << endl;
	}
	//********************************************************************************

	system("pause");
	return 0;
}