#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
	Person* p1 = new Person("Anton", "Achenbach", "11111", "Aachen", 111.11, 'm');
	Person* p2 = new Person("Beate", "Bach", "22222", "Bremen", 222.22, 'w');
	Person* p3 = new Person("Cesar", "Clausen", "33333", "Celle", 333.33, 'd');

	p1->getMeineFreunde().add(p2);
	p1->getMeineFreunde().add(p3);
	cout << p1->getMeineFreunde().size() << endl;

	for (int i = 0; i < p1->getMeineFreunde().size(); i++) {
		cout << p1->getMeineFreunde().get(i)->getPersonenId() << " "
			<< p1->getMeineFreunde().get(i)->getVorname() << " "
			<< p1->getMeineFreunde().get(i)->getNachname() << " "
			<< p1->getMeineFreunde().get(i)->getPlz() << " "
			<< p1->getMeineFreunde().get(i)->getOrt() << " "
			<< p1->getMeineFreunde().get(i)->getVermoegen() << " "
			<< p1->getMeineFreunde().get(i)->getGeschlecht() << endl;
	}

	cout << "Ist p2 in meineFreunde enthalten? " << p1->getMeineFreunde().contains(p2) << endl;
	cout << "Ist p1 in meineFreunde enthalten? " << p1->getMeineFreunde().contains(p1) << endl;

	cout << "Anzahl Objekte in der Liste: " << p1->getMeineFreunde().size() << endl;
	cout << "Entfernt das Objekt am Index 0 und gibt es zurueck. " << p1->getMeineFreunde().remove(0)->getVorname() << endl;
	cout << "Entfernt das Objekt p3 und gibt true zurueck, wenn ... " << p1->getMeineFreunde().remove(p3) << endl;
	cout << "Anzahl Objekte in der Liste: " << p1->getMeineFreunde().size() << endl;
}
