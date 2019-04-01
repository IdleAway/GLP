#include "Fach.h"

#pragma region KONSTRUKTOREN

/*	Typ				|	Standart-Konstruktor
*	Parameter		|	-
*	Standartwerte	|	-
*
*	Beschreibung:
*		-
*/
Fach::Fach()
{
}

/*	Typ				|	Viertel-Konstruktor
*	Parameter		|	int nummer
*	Standartwerte	|	int maxAnzahl = 25
*					|	intt anzahl = 0
*
*	Beschreibung:
*		-
*/
Fach::Fach(int nummer)
{
	setNummer(nummer);
	setMaxAnzahl(25);
	setAnzahl(0);
}

/*	Typ				|	Voller-Konstruktor
*	Parameter		|	int nummer
*					|	Angebot angebot
*					|	int maxAnzahl
*					|	int anzahl
*	Standartwerte	|	-
*
*	Beschreibung:
*		-
*/
Fach::Fach(int nummer, Angebot angebot, int maxAnzahl, int anzahl)
{
	setNummer(nummer);
	setAngebot(angebot);
	setMaxAnzahl(maxAnzahl);
	setAnzahl(anzahl);
}

/*	Typ				|	Standart-Dekonstruktor
*	Parameter		|	-
*	Standartwerte	|	-
*
*	Beschreibung:
*		-
*/
Fach::~Fach()
{
}

#pragma endregion

#pragma region GETTER SETTER

void Fach::setNummer(int nummer)
{
	this->nummer = nummer;
}

int Fach::getNummer() 
{
	return nummer;
}

void Fach::setAngebot(Angebot angebot)
{
	this->angebot = angebot;
}

Angebot Fach::getAngebot() 
{
	return angebot;
}

void Fach::setMaxAnzahl(int maxAnzahl) 
{

	this->maxAnzahl = maxAnzahl;
}

int Fach::getMaxAnzahl() 
{
	return maxAnzahl;
}

void Fach::setAnzahl(int anzahl) 
{
	this->anzahl = anzahl;
}
int Fach::getAnzahl() 
{
	return anzahl;
}

#pragma endregion

#pragma region FUNKTIONEN

/*	Funktion		|	verbleibenderPlatz()
*	Sichtbarkeit	|	PRIVATE
*	Parameter		|	-
*	R�ckgabewert	|	int
*
*	Beschreibung:
*		Errechnet anhand von getMaxAnzahl() und getAnzahl()
*		den noch verf�gbaren Platz in dem Fach und gibt
*		diesen als int-Wert zur�ck
*/
int Fach::verbleibenderPlatz()
{
	return getMaxAnzahl()/getAngebot().getBelegtPlatz() - getAnzahl();
}

/*	Funktion		|	bestuecken(Angebot angebot)
*	Sichtbarkeit	|	PUBLIC
*	Parameter		|	-
*	R�ckgabewert	|	-
*
*	Beschreibung:
*		-
*/
void Fach::bestuecken(Angebot angebot)
{
	setAngebot(angebot);
}

/*	Funktion		|	auffuellen()
*	Sichtbarkeit	|	PUBLIC 
*	Parameter		|	-
*	R�ckgabewert	|	-
*
*	Beschreibung:
*		-
*/
void Fach::auffuellen()
{
	setAnzahl(getMaxAnzahl()/ getAngebot().getBelegtPlatz());
}


/*	Funktion		|	befuellen(anzahl)
*	Sichtbarkeit	|	PUBLIC
*	Parameter		|	int anzahl
*	R�ckgabewert	|	boolean
*
*	Beschreibung:
*		Anhand von verbleibenderPlatz() wird gepr�ft ob
*		noch genug Platz ist um die �bergebene anzahl im
*		Fach unterzubringen.
*		Misserfolg der Pr�fung f�hrt zur maximalen Bef�llung
*		des Fachs und es wird FALSE zur�ck gegeben
*		Erfolg der Pr�fung f�hrt zur Bef�llung mit �bergebener
*		Anzahl und es wird TRUE zur�ck gegeben.
*/
bool Fach::befuellen(int anzahl)
{
	if (verbleibenderPlatz() < anzahl) {
		setAnzahl(getMaxAnzahl()/getAngebot().getBelegtPlatz());
		return false;
	}
	else {
		setAnzahl(getAnzahl() + anzahl);
		return true;
	}
}

/*	Funktion		|	verkaufen()
*	Sichtbarkeit	|	PUBLIC
*	Parameter		|	-
*	R�ckgabewert	|	boolean
*
*	Beschreibung:
*		Pr�ft anhand von verbleibenderPlatz() und getMaxAnzahl()
*		ob NICHT genau so viel freier Platz wie verf�gbarer Platz
*		vorhanden ist.
*		Erfolg der Pr�fung f�hrt zum Abzug eines belegten Platzes
*		und die funktion wird mit TRUE verlassen.
*		Misserfolg f�hrt zum verlassen der Funktion mit FALSE
*/
bool Fach::verkaufen()
{
	if (getAnzahl()>1) {
		int anzahl = getAnzahl() - 1;
		setAnzahl(anzahl);
		return true;
	}
	return false;
}

#pragma endregion