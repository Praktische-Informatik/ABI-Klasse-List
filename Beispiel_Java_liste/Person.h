#pragma once
#include <string>
#include "List.h" // Java-List statt C++ <list>
#include <iostream>

using namespace std;

class Person
{
private:
	static int personenAnzahl;
	int personenId;
	string vorname;
	string nachname;
	string plz;
	string ort;
	double vermoegen; // in Euro und Euro-Cent
	char geschlecht; // w/m/d
	List<Person*> meineFreunde;
	
public:
	Person();
	Person(string vorn, string nachn, string plz, string ort, double vermoegen, char geschlecht);
	~Person();

	static int getPersonenAnzahl();
	int getPersonenId();
	string getVorname();
	string getNachname();
	string getPlz();
	string getOrt();
	double getVermoegen();
	char getGeschlecht();
	List<Person*>& getMeineFreunde();
};

