#include <sstream>
#include <iostream>
#include "Ausgabe.h"

Ausgabe::Ausgabe()
{
}

Ausgabe::~Ausgabe()
{
}

void Ausgabe::printFaecher(std::vector<Fach> liste) 
{
	int maximaleReihen = 15;
	int momentaneReihen = 0;

	system("cls");
	for (Fach fach : liste) {
		printFach(fach);
		momentaneReihen++;
	}
	for (int i = momentaneReihen;i < maximaleReihen; i++) {
		printLeereLinie();
	}
}

void Ausgabe::print(std::string str)
{
	std::cout << str;
}

void Ausgabe::printLine(std::string str)
{
	std::cout << str << std::endl;
}

void Ausgabe::printLeereLinie()
{
	std::cout << " " << std::endl;
}

void Ausgabe::printFach(Fach fach)
{
	std::string name = fach.getAngebot().getName();
	int tabSpace = 8;
	
	std::string space = "\t";
	for (int i = name.length() / tabSpace; i < 2; i++) {
		space = space + "\t";
	}

	int nummer = fach.getNummer();
	double preis = fach.getAngebot().getPreis();
	int anzahl = fach.getAnzahl();
	int maxAnzahl = fach.getMaxAnzahl()/fach.getAngebot().getBelegtPlatz();

	std::ostringstream ausgabe;
	ausgabe << nummer<< "\t"<<name << space << preis << "\t" << anzahl << "/" << maxAnzahl;
	std::cout << ausgabe.str() <<std::endl;
}