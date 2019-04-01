#pragma once
#include <string>
#include <vector>
#include "Fach.h"
#include "Angebot.h"

class Ausgabe
{
public:
	Ausgabe();
	~Ausgabe();

	void printFaecher(std::vector<Fach>);
	void print(std::string);
	void printLine(std::string);


private:
	void printLeereLinie();
	void printFach(Fach fach);
};

