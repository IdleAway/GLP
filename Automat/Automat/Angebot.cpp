#include "Angebot.h"

#pragma region KONSTRUKTOREN

/*	Typ				|	Standart-Konstruktor
*	Parameter		|	-
*	Standartwerte	|	-
*
*	Beschreibung:
*		-
*/
Angebot::Angebot()
{
}

/*	Typ				|	Voller-Konstruktor
*	Parameter		|	string name
*					|	double preis
*					|	int belegtPlatz
*	Standartwerte	|	-
*
*	Beschreibung:
*		-
*/
Angebot::Angebot(std::string name,double preis,int belegtPlatz)
{
	setName(name);
	setPreis(preis);
	setBelegtPlatz(belegtPlatz);
}

/*	Typ				|	Standart-Dekonstruktor
*	Parameter		|	-
*	Standartwerte	|	-
*
*	Beschreibung:
*		-
*/
Angebot::~Angebot()
{
}

#pragma endregion

#pragma region GETTER SETTER

std::string Angebot::getName()
{
	return name;
}

void Angebot::setName(std::string name)
{
	this->name = name;
}

double Angebot::getPreis()
{
	return preis;
}

void Angebot::setPreis(double preis)
{
	this->preis = preis;
}

int Angebot::getBelegtPlatz()
{
	return belegtPlatz;
}

void Angebot::setBelegtPlatz(int platz)
{
	this->belegtPlatz = platz;
}

#pragma endregion