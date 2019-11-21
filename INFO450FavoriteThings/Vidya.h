#pragma once
#include <iostream>
#include <string>
using namespace std;

class Vidya
{
private:
	string genre;
	double price;
	string publisher;
	int hoursPlayed;
public:
	string name;
	string system;
	Vidya();
	Vidya(string n, string g, double p, string s, string pu, int hP);
	~Vidya();
	void getVidyaInput();
	void showVidya();
	string getName();
	string getGenre();
	double getPrice();
	string getSystem();
	string getPublisher();
	int getHoursPlayed();
	void setName(string n);
	void setGenre(string g);
	void setPrice(double p);
	void setSystem(string s);
	void setPublisher(string pu);
	void setHoursPlayed(int hP);
	friend ostream& operator<<(ostream &output, Vidya &i);
	friend bool operator==(const Vidya& lhs, const Vidya& rhs);
};

