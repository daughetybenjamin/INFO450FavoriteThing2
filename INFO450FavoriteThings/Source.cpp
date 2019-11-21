#include <iostream>
#include <string>
#include "Vidya.h"
#include "VidyaList.h"
#include <fstream>
using namespace std;

int main() 
{
	int choice = 1;
	cout << "This application will track information that you input about several video games." << endl;
	VidyaList list1;
	string filePath;

	do
	{
		cout << "1. Read items from a file." << endl;
		cout << "2. Add a new item to your list." << endl;
		cout << "3. Display your current list." << endl;
		cout << "4. Save your current list to a file." << endl;
		cout << "0. Exit." << endl;
		cout << "Enter a number to choose from the above options: ";
		cin >> choice;
		cin.ignore();

		if (choice == 0)
		{
			break;
		}
		else if (choice == 1)
		{
			cout << "Enter the full file path: ";
			getline(cin, filePath);
			list1.readFile(filePath);
			cout << "\nSuccessfully loaded file. Check your list so far by using choice 3." << endl;
		}
		else if (choice == 2)
		{
			list1.addGame();
			cout << "\nSuccessfully added game to list." << endl;
		}
		else if (choice == 3)
		{
			list1.showList();
			cout << endl;
		}
		else if (choice == 4)
		{
			cout << "Enter the full file path: ";
			getline(cin, filePath);
			list1.saveFile(filePath);
			cout << endl << "Successfully saved file to given location." << endl;
		}
		else
		{
			cout << "Invalid response. Try again.";
		}
	} while (choice != 0);

	//

	system("pause");
	return 0;
}