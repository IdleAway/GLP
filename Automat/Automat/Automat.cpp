#include <iostream>
#include <sstream>
#include "Automat.h"
#include "Ausgabe.h"
#include "Fach.h"
#include "Angebot.h"


/*	Typ				|	Standart-Konstruktor
*	Parameter		|	-
*	Standartwerte	|	Ausgabe ausgabe
*
*	Beschreibung:
*		-
*/
Automat::Automat()
{
	Ausgabe * ausgabe = new Ausgabe();
}

/*	Typ				|	Standart-Destruktor
*	Parameter		|	-
*	Standartwerte	|	-
*
*	Beschreibung:
*		-
*/
Automat::~Automat()
{
}

#pragma region GETTER SETTER

void Automat::setAusgabe(Ausgabe ausgabe)
{
	this->ausgabe = ausgabe;
}

Ausgabe Automat::getAusgabe()
{
	return ausgabe;
}
void Automat::setMaxFaecher(int maxFaecher)
{
	this->maxFaecher = maxFaecher;
}

int Automat::getMaxFaecher()
{
	return maxFaecher;
}

void Automat::setListFaecher(std::vector<Fach> faecher)
{
	this->faecher = faecher;
}

std::vector<Fach> Automat::getListFaecher()
{
	return faecher;
}

void Automat::setListAngebote(std::vector<Angebot> angebote)
{
	this->angebote = angebote;
}

std::vector<Angebot> Automat::getListAngebote()
{
	return angebote;
}

void Automat::setAutomatAntwort(std::string automatAntwort)
{
	this->automatAntwort =  automatAntwort;
}

std::string Automat::getAutomatAntwort()
{
	return automatAntwort;
}

#pragma endregion

/*	Funktion		|	start()
*	Sichtbarkeit	|	PUBLIC
*	Parameter		|	-
*	Rückgabewert	|	-
*
*	Beschreibung:
*		Funktion zum "starten" des Automaten, die die
*		boolean-prüfung initialisiere() aufruft
*		Misserfolg führt zur Ausgabe einer Fehlernachricht
*		das Programm wird auf Knopfdruck verlassen
*		Erfolg führt zum Aufruf der verwalte() funktion
*/
void Automat::start()
{
	initialisiere();
	verwalte();
}

/*	Funktion		|	initialisiere()
*	Sichtbarkeit	|	PRIVATE
*	Parameter		|	-
*	Rückgabewert	|	boolean
*
*	Beschreibung:
*		-
*/
bool Automat::initialisiere()
{
	maxFaecher = 10;
	faecher;
	angebote;

	for (int i = 0; i < getMaxFaecher(); i++) {
		Fach * fach = new Fach(i + 1);
		faecher.push_back(*fach);
	}

	Angebot * angebot1 = new Angebot("GrenzRiegel",3.5,1);
	Angebot * angebot2 = new Angebot("DasIstMeins", 1.5, 2);
	Angebot * angebot3 = new Angebot("DasIstDeins", 0.75, 1);
	Angebot * angebot4 = new Angebot("Artikel13", 9.99, 1);
	Angebot * angebot5 = new Angebot("Schriftzug: Kompetenz", 0.01, 1);
	Angebot * angebot6 = new Angebot("Dieses Internet", 2, 1);
	Angebot * angebot7 = new Angebot("Mir", 2, 1);
	Angebot * angebot8 = new Angebot("gehen", 2, 1);
	Angebot * angebot9 = new Angebot("die Idee", 2, 1);
	Angebot * angebot10 = new Angebot(" 'n aus", 2, 1);
	angebote.push_back(*angebot1);
	angebote.push_back(*angebot2);
	angebote.push_back(*angebot3);
	angebote.push_back(*angebot4);
	angebote.push_back(*angebot5);
	angebote.push_back(*angebot6);
	angebote.push_back(*angebot7);
	angebote.push_back(*angebot8);
	angebote.push_back(*angebot9);
	angebote.push_back(*angebot10);

	for (int i = 0; i < faecher.size(); i++) {
		faecher[i].bestuecken(angebote[i]);
		faecher[i].auffuellen();
	}

	return true;
}

/*	Funktion		|	eingabeAbfangen()
*	Sichtbarkeit	|	-
*	Parameter		|	-
*	Rückgabewert	|	-
*
*	Beschreibung:
*		-
*/
std::string Automat::eingabeAbfangen()
{
	ausgabe.print("Ihre Eingabe: ");
	std::string ret;
	std::cin >> ret;
	return ret;
}


bool Automat::eingabeVerarbeiten(std::string str) {

	int fachNummer=0;
	std::string befehl = "";
	std::ostringstream nachricht;

	for (char c : str) {
		if (isdigit(c)) {
			fachNummer = fachNummer * 10 + (int)c-48;

		}
		else {
			befehl.push_back(c);
		}
	}

	if (fachNummer > 0 && befehl.length() > 0) {
		//Gott modus
	}else if(fachNummer ==0 && befehl == "exit"){
		return false;
	}else if (fachNummer > 0 && befehl.length() <= 0) {
		for (Fach fach : getListFaecher()) {
			if (fach.getNummer() == fachNummer) {
				if (fach.verkaufen()) {
					nachricht << fach.getAngebot().getName()<< " nun fuer dich bereit!";
				}
				else {
					nachricht << "Fach " << fachNummer  << " ist leer!";
				}
			}
		}
	}
	setAutomatAntwort(nachricht.str());
	return true;
}

/*	Funktion		|	verwalte()
*	Sichtbarkeit	|	-
*	Parameter		|	-
*	Rückgabewert	|	-
*
*	Beschreibung:
*		-
*/
void Automat::verwalte()
{
	bool running = true;
	while (running) {
		ausgabe.printFaecher(faecher);
		ausgabe.printLine(getAutomatAntwort());
		if (!eingabeVerarbeiten(eingabeAbfangen())) {
			running = false;
		}
	}
}
