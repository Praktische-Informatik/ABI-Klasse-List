#include "Person.h"

int Person::personenAnzahl = 0;

Person::Person()
{
	personenId = ++personenAnzahl;
	vorname = "Max";
	nachname = "Mustermann";
	plz = "12345";
	ort = "Musterhausen";
	vermoegen = 1234.56;
	geschlecht = 'm';
}

Person::Person(string vorn, string nachn, string plz, string ort, double vermoegen, char geschlecht)
{
	personenAnzahl = ++personenAnzahl;
	personenId = personenAnzahl;
	vorname = vorn;
	nachname = nachn;
	this->plz = plz;
	this->ort = ort;
	this->vermoegen = vermoegen;
	this->geschlecht = geschlecht;
}

Person::~Person()
{
	--personenAnzahl;
}

int Person::getPersonenAnzahl()
{
	return personenAnzahl;
}

int Person::getPersonenId()
{
	return personenId;
}

string Person::getVorname()
{
	return vorname;
}

string Person::getNachname()
{
	return nachname;
}

string Person::getPlz()
{
	return plz;
}

string Person::getOrt()
{
	return ort;
}

double Person::getVermoegen()
{
	return vermoegen;
}

char Person::getGeschlecht()
{
	return geschlecht;
}

List<Person*>& Person::getMeineFreunde()
{
	return meineFreunde;
}





