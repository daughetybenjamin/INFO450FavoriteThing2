#include "Vidya.h"


Vidya::Vidya()
{
	name = "";
	genre = "";
	price = 0;
	system = "";
	publisher = "";
	hoursPlayed = 0;
}

Vidya::Vidya(string n, string g, double p, string s, string pu, int hP)
{
	name = n;
	genre = g;
	price = p;
	system = s;
	publisher = pu;
	hoursPlayed = hP;
}

Vidya::~Vidya()
{
}

void Vidya::getVidyaInput()
{
	cout << "Type the game's name here: ";
	getline(cin, name);
	cout << "Type the game's genre here: ";
	getline(cin, genre);
	cout << "Type the game's price here: ";
	cin >> price;
	cin.ignore();
	cout << "Type the system the game is published on here: ";
	getline(cin, system);
	cout << "Type the game's publisher here: ";
	getline(cin, publisher);
	cout << "Type the amount of hours played as an integer here: ";
	cin >> hoursPlayed;
}

void Vidya::showVidya()
{
	cout << "Name: " << name << " | ";
	cout << "Genre: " << genre << " | ";
	cout << "Price: $" << price << endl;
	cout << "System: " << system << " | ";
	cout << "Publisher: " << publisher << " | ";
	cout << "Hours played: " << hoursPlayed << endl << endl;
}

string Vidya::getName()
{
	return name;
}
string Vidya::getGenre()
{
	return genre;
}
double Vidya::getPrice()
{
	return price;
}
string Vidya::getSystem()
{
	return system;
}
string Vidya::getPublisher()
{
	return publisher;
}
int Vidya::getHoursPlayed()
{
	return hoursPlayed;
}
void Vidya::setName(string n)
{
	name = n;
}
void Vidya::setGenre(string g)
{
	genre = g;
}
void Vidya::setPrice(double p)
{
	price = p;
}
void Vidya::setSystem(string s)
{
	system = s;
}
void Vidya::setPublisher(string pu)
{
	publisher = pu;
}
void Vidya::setHoursPlayed(int hP)
{
	hoursPlayed = hP;
}
ostream& operator<<(ostream &output, Vidya &i)
{
	output << "Game: " << i.name << " | Genre: " << i.genre << " | Price: $" << i.price << endl;
	output << "Publisher: " << i.publisher << " | System: " << i.system << " | Hours Played: " << i.hoursPlayed << endl;
	return output;
}
bool operator==(const Vidya& lhs, const Vidya& rhs)
{
	return lhs.name == rhs.name && lhs.system == rhs.system;
}