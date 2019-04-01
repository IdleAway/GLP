#pragma once
#include <string>
#include <vector>
#include "Fach.h"
#include "Angebot.h"
#include "Ausgabe.h"

class Automat
{
public:
	Automat();
	~Automat();

	void start();


private:
	Ausgabe ausgabe;
	int maxFaecher;
	std::vector<Fach> faecher;
	std::vector<Angebot> angebote;
	std::string automatAntwort;

	void setAusgabe(Ausgabe);
	Ausgabe getAusgabe();
	void setMaxFaecher(int);
	int getMaxFaecher();
	void setListFaecher(std::vector<Fach>);
	std::vector<Fach> getListFaecher();
	void setListAngebote(std::vector<Angebot>);
	std::vector<Angebot> getListAngebote();
	void setAutomatAntwort(std::string);
	std::string getAutomatAntwort();

	
	bool initialisiere();
	std::string eingabeAbfangen();
	bool eingabeVerarbeiten(std::string);
	void verwalte();
};

