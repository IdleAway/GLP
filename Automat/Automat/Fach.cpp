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
*	Rückgabewert	|	int
*
*	Beschreibung:
*		Errechnet anhand von getMaxAnzahl() und getAnzahl()
*		den noch verfügbaren Platz in dem Fach und gibt
*		diesen als int-Wert zurück
*/
int Fach::verbleibenderPlatz()
{
	return getMaxAnzahl()/getAngebot().getBelegtPlatz() - getAnzahl();
}

/*	Funktion		|	bestuecken(Angebot angebot)
*	Sichtbarkeit	|	PUBLIC
*	Parameter		|	-
*	Rückgabewert	|	-
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
*	Rückgabewert	|	-
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
*	Rückgabewert	|	boolean
*
*	Beschreibung:
*		Anhand von verbleibenderPlatz() wird geprüft ob
*		noch genug Platz ist um die übergebene anzahl im
*		Fach unterzubringen.
*		Misserfolg der Prüfung führt zur maximalen Befüllung
*		des Fachs und es wird FALSE zurück gegeben
*		Erfolg der Prüfung führt zur Befüllung mit übergebener
*		Anzahl und es wird TRUE zurück gegeben.
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
*	Rückgabewert	|	boolean
*
*	Beschreibung:
*		Prüft anhand von verbleibenderPlatz() und getMaxAnzahl()
*		ob NICHT genau so viel freier Platz wie verfügbarer Platz
*		vorhanden ist.
*		Erfolg der Prüfung führt zum Abzug eines belegten Platzes
*		und die funktion wird mit TRUE verlassen.
*		Misserfolg führt zum verlassen der Funktion mit FALSE
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