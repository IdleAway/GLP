#pragma once
#include <string>

class Angebot
{
public:

#pragma region KONSTURKTOREN

	Angebot();
	Angebot(std::string,double,int);
	~Angebot();

#pragma endregion

#pragma region GETTER SETTER

	std::string getName();
	void setName(std::string);
	double getPreis();
	void setPreis(double);
	int getBelegtPlatz();
	void setBelegtPlatz(int);

#pragma endregion
	
private:

#pragma region VARIABLEN

	std::string name;		//Speichern des Namens
	double preis;		//Speichern des Preis
	int belegtPlatz;	//Speichern der belegten Fächer

#pragma endregion
};

