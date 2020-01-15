#include <iostream>
#include <string>
#include <fstream>

using namespace std;
/*
Контрольна робота!

Реализовать следующие возможности:

Вся информация, должна сохранятся в бинарном файле, должна быть реализована
возможность добавления новых данных.*/

/*Создать класс СПРАВОЧНИК со следующими полями:
1. Название фирмы;
2. Владелец;
3. Телефон;
4. Адрес;
5. Род деятельности.*/
class Directory
{
	string nameFirm;
	string owner;
	string phone;
	string address;
	string typeActivity;

public:
	Directory() { cout << "Default constructor" << endl; };
	Directory (string nameFirm, string owner, string phone, string address, string typeActivity)
	{
		this->nameFirm = nameFirm;
		this->owner = owner;
		this->phone = phone;
		this->address = address;
		this->typeActivity = typeActivity;
		cout << "Overload constructor" << endl; 
	};

	void ShowInfo()
	{
		cout << "Name firm: " << this->nameFirm << " Owner: " << this->owner << " Phone: " << this->phone << "\nAddress: " << this->address << " Type of Activity: " << this->typeActivity << endl;
	}

	string GetNameFirm()
	{
		return this->nameFirm;
	}
	string GetNameOwner()
	{
		return this->owner;
	}

	string  GetPhone()
	{
		return this->phone;
	}

	string GetAddress()
	{
		return this->address;
	}

	string GetTypeActivity()
	{
		return this->typeActivity;
	}


	void SetNameFirm(string nameFirm) 
	{
		this->nameFirm = nameFirm;
	}

	void SetOwner(string owner)
	{
		this->owner = owner;
	}

	void SetPhone(string phone)
	{
		this->phone = phone;
	}

	void SetAddress(string address)
	{
		this->address = address;
	}

	void SetTypeActivity(string typeActivity)
	{
		this->typeActivity = typeActivity;
	}
	

	~Directory() { cout << "Default destructor" << endl; };
};


//5. Показ всех записей и добавление.

void ShowInfoAllFirms(Directory *arr, const int &SIZE)
{
	cout << "*********************************" << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << "Firm N: " << i + 1 << ": ";
		arr[i].ShowInfo();
	}
	cout << "*********************************" << endl;
}

//1. Поиск по названию;

void FindNameFirm(Directory *arr, const int &SIZE)
{
	bool isFindNameFirm = false;
	string findNameFirm;
	cout << "Search by company name" << endl;
	while (!isFindNameFirm)
	{
		cout << "Enter a BUSINESS NAME to search: " << endl; cin >> findNameFirm;
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[i].GetNameFirm() == findNameFirm)
			{
				isFindNameFirm = true;
				arr[i].ShowInfo();
			}
		}
		if (!isFindNameFirm)
		{
			cout << "Please, enter correct name of firm" << endl;
		}
	}
	cout << "=============================================" << endl;
}

//2. Поиск по владельцу;

void FindOwner(Directory *arr, const int &SIZE)
{
	bool isFindOwner = false;
	string findOwner;
	cout << "Search by Owner" << endl;
	while (!isFindOwner)
	{
		cout << "Enter OWNER to search: " << endl; cin >> findOwner;
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[i].GetNameOwner() == findOwner)
			{
				isFindOwner = true;
				arr[i].ShowInfo();
			}
		}
		if (!isFindOwner)
		{
			cout << "Please, enter correct Owner of firm" << endl;
		}
	}
	cout << "=============================================" << endl;
}

//3. Поиск по номеру телефона;


void FindPhone(Directory *arr, const int &SIZE)
{
	bool isFindPhone = false;
	string findPhone;
	cout << "Search by PHONE" << endl;
	while (!isFindPhone)
	{
		cout << "Enter PHONE to search: " << endl; cin >> findPhone;
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[i].GetPhone() == findPhone)
			{
				isFindPhone = true;
				arr[i].ShowInfo();
			}
		}
		if (!isFindPhone)
		{
			cout << "Please, enter correct Phone of firm" << endl;
		}
	}
	cout << "=============================================" << endl;
}


//4. Поиск по роду деятельности;
void FindTypeActivity(Directory *arr, const int &SIZE)
{
	bool isFindTypeActivity = false;
	string findTypeActivity;
	cout << "Search by ACTIVITY" << endl;
	while (!isFindTypeActivity)
	{
		cout << "Enter OWNER to search: " << endl; cin >> findTypeActivity;
		for (int i = 0; i < SIZE; i++)
		{
			if (arr[i].GetTypeActivity() == findTypeActivity)
			{
				isFindTypeActivity = true;
				arr[i].ShowInfo();
			}
		}
		if (!isFindTypeActivity)
		{
			cout << "Please, enter correct Owner of firm" << endl;
		}
	}
	cout << "=============================================" << endl;
}

void AddNewFirm(Directory *&arr, int &SIZE)
{
	
	Directory tempArr;
	string nameFirm1;
	string owner1;
	string phone1;
	string address1;
	string typeActivity1;

	cout << "Add new firm: "; cin >> nameFirm1; 
	tempArr.SetNameFirm(nameFirm1);
	cout << "Enter Owner of firm: "; cin >> owner1;
	tempArr.SetOwner(owner1);
	cout << "Enter Phone of firm: "; cin >> phone1;
	tempArr.SetPhone(phone1);
	cout << "Enter Address of firm: "; cin >> address1;
	tempArr.SetAddress(address1);
	cout << "Enter Type Activity of firm: "; cin >> typeActivity1;
	tempArr.SetTypeActivity(typeActivity1);


	Directory *newArr = new Directory[SIZE + 1];
	for (int i = 0; i < SIZE; i++)
	{
		newArr[i].SetNameFirm(arr[i].GetNameFirm()) ;
		newArr[i].SetOwner(arr[i].GetNameOwner())  ;
		newArr[i].SetPhone(arr[i].GetPhone())  ;
		newArr[i].SetAddress(arr[i].GetAddress()) ;
		newArr[i].SetTypeActivity(arr[i].GetTypeActivity()) ;
	}
	newArr[SIZE].SetNameFirm(tempArr.GetNameFirm()) ;
	newArr[SIZE].SetOwner(tempArr.GetNameOwner());
	newArr[SIZE].SetPhone(tempArr.GetPhone()) ;
	newArr[SIZE].SetAddress(tempArr.GetAddress());
	newArr[SIZE].SetTypeActivity(tempArr.GetTypeActivity());

	   	 	
	delete[] arr;
	arr = newArr;
	SIZE++;

}



void OutputCollectionInFile(Directory *arr, int &SIZE)
{
	ofstream writeFile;
	string path = "db.txt";
	string text;
	writeFile.open(path, ofstream::app);
	if (!writeFile.is_open())
	{
		cout << "Can't open file!" << endl;
	}
	else
	{
		cout << "File saved!" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			writeFile << "**************   Firm number: " << i + 1 << "**********************" << endl;
			writeFile << "Name of firm:\t"<<arr[i].GetNameFirm() << endl;
			writeFile << "Owner of firm:\t" << arr[i].GetNameOwner() << endl;
			writeFile << "Phone of firm:\t" << arr[i].GetPhone() << endl;
			writeFile << "Address of firm:\t" << arr[i].GetAddress()<< endl;
			writeFile << "Activity of firm:\t" <<arr[i].GetTypeActivity() << endl;
			
		}

	}

	writeFile.close();
}



int main()
{
	int SIZE = 2;
	Directory directory1("Step", "Korch", "44352174", "Rivne, Pushkina st.", "Education");
	Directory directory2("RDGU", "Ministry of Education", "36225134", "Rivne, Tolstogo st.", "Education");
	Directory *arr = new Directory[SIZE];
	arr[0] = directory1;
	arr[1] = directory2;
	ShowInfoAllFirms(arr, SIZE);
	FindNameFirm(arr, SIZE);
	FindOwner(arr, SIZE);
	FindPhone(arr, SIZE);
	FindTypeActivity(arr, SIZE);
	cout << "|||||||||||||||||" << endl;
	AddNewFirm(arr, SIZE);
	cout << "|||||||||||||||||" << endl;
	ShowInfoAllFirms(arr, SIZE);
	OutputCollectionInFile(arr, SIZE);




	system("pause");
	return 0;
}