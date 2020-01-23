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

	char ip[16];
	char temp[4];
	int counter = 0;
	bool exit = false;
	cout << "****************** EXERCISE 1 ************************" << endl;
	while (!exit)
	{
		cout << "Enter IP: ";
		cin >> ip;

		int iterator = 0;
		for (int i = 0; i < strlen(ip) + 1; i++) {
			if (ip[i] == 46 || (i == strlen(ip) && counter == 3)) {
				if (atoi(temp) <= 255) counter++;
				for (int j = 0; j < 4; j++) {
					temp[j] = '\0';
					exit = true;
				}
				iterator = 0;
			}
			else {
				temp[iterator] = ip[i];
				iterator++;
			}
		}

		if (counter == 4) cout << "Correct" << endl;
		else cout << "not correct" << endl;

		for (int i = 0; i < strlen(ip); i++) {
			cout << ip[i];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}