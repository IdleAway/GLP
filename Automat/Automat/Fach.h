#pragma once
#include "Angebot.h"
class Fach
{
public:

#pragma region KONSTRUKTOREN

	Fach();
	Fach(int);
	Fach(int, Angebot, int, int);
	~Fach();

#pragma endregion

#pragma region GETTER & SETTER

	void setNummer(int);
	int getNummer();
	void setAngebot(Angebot);
	Angebot getAngebot();
	void setMaxAnzahl(int);
	int getMaxAnzahl();
	void setAnzahl(int);
	int getAnzahl();

#pragma endregion

#pragma region FUNKTIONEN

	void bestuecken(Angebot);
	void auffuellen();
	bool befuellen(int);
	bool verkaufen();

#pragma endregion

private:

#pragma region VARIABLEN

	int nummer;			//Speichern der Nummer zum ansprechen des Fachs
	Angebot angebot;	//Speichern des Angebots
	int maxAnzahl;		//Speichern der maximalen Kapazität des Fachs
	int anzahl;			//Speichern der aktuellen Anzahl

#pragma endregion

#pragma region FUNKTIONEN

	int verbleibenderPlatz();

#pragma endregion
};