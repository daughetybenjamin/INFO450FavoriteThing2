#include <iostream>
#include <string>
#include "Vidya.h"
#include "VidyaList.h"
#include <fstream>
using namespace std;

VidyaList::VidyaList()
{
	numGames = 0;
}

void VidyaList::addGame()
{
	int i;
	cout << "Enter the information for game " << numGames + 1 << "." << endl;
	games[numGames].getVidyaInput();
	for (i = 0; i < numGames; i++)
	{
		if (games[numGames] == games[i])
		{
			cout << "You've already added this game. Please try again." << endl;
			numGames--;
		}
	}
	numGames++;
}

void VidyaList::showList()
{
	if (numGames != 0)
	{
		cout << endl << "Here is the list of games you've added:" << endl;
		int i;
		for (i = 0; i < numGames; i++)
		{
			cout << games[i];
		}
		cout << "Total number of games is " << numGames << "." << endl;
	}
	else
	{
		cout << "You currently have no games added. Try opening a file or adding games." << endl;
	}
}

void VidyaList::readFile(string filePath)
{
	ifstream inputFile;
	inputFile.open(filePath, ios::in);
	if (!inputFile)
	{
		cout << "Could not open file. Make sure the file exists and you entered it correctly." << endl;
		return;
	}

	string name;
	string genre;
	int price;
	string system;
	string publisher;
	int hoursPlayed;
	string inputString;

	while (!inputFile.eof())
	{
		getline(inputFile, inputString, '|');
		if (inputString.length() >= 1)
		{
			name = inputString;
			getline(inputFile, genre, '|');
			getline(inputFile, inputString, '|');
			price = stoi(inputString);
			getline(inputFile, system, '|');	
			getline(inputFile, publisher, '|');
			getline(inputFile, inputString, '|');
			hoursPlayed = stoi(inputString);

			games[numGames].setName(name);
			games[numGames].setGenre(genre);
			games[numGames].setPrice(price);
			games[numGames].setSystem(system);
			games[numGames].setPublisher(publisher);
			games[numGames].setHoursPlayed(hoursPlayed);
			numGames++;
		}
	}

	inputFile.close();
}

void VidyaList::saveFile(string filePath)
{
	int i;
	ofstream outputFile;
	outputFile.open(filePath, ios::trunc);
	if (!outputFile)
	{
		outputFile.open(filePath, ios::out);
	}

	for (i = 0; i < numGames; i++)
	{
		outputFile << games[i].getName() << "|";
		outputFile << games[i].getGenre() << "|";
		outputFile << games[i].getPrice() << "|";
		outputFile << games[i].getSystem() << "|";
		outputFile << games[i].getPublisher() << "|";
		outputFile << games[i].getHoursPlayed() << endl;
	}
	outputFile.close();
}

VidyaList::~VidyaList()
{
}
