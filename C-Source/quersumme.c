//Programm zum errechnen der Quersumme einer Zahl

//PSEUDOCODE//
/*
PROGRAMM_START

	function crossSum(int number):int
		int ret = 0
		while(number != 0) 
			DO
			ret = ret + number % 10
			number = number/10
		END_WHILE
		return ret
	end_function quersumme

	function getInput():int
		clear(output)
		print("Type a number :")
		input = read()
		return input
	end_function  getInput()
	
	function generateOutput(int number):void
		print(number)
		system.pause
	end_function
	
	
	main
		generateOutput(crossSum(getInput()))
	end_main
	
END_PROGRAMM
*/

#include <stdio.h>
#include <stdlib.h>

/*	int crossSum(int number)
*		erwartet int wert als übergabe
*		verarbeitet den wert in eine Quersumme
*		gibt die Quersumme zurück
*/
int crossSum(int number){
	int ret = 0;
	while(number!=0){
		ret=ret + number % 10;
		number = number/10;
	}
	return ret;
}

/*	int getInput()
*		Erstellt für den Nutzer eine Ausgabe
*		um eine Eingabe zu bekommen
*		gibt die Eingabe zurück
*/
int getInput(){
	system("cls");
	printf("Type a number: ");
	int input;
	scanf("%d",&input);
	fflush(stdin);
	return input;
}

/*	void generateOutput
*		erwartet int wert als übergabe
*		gibt entsprechenden wert in der ausgabe aus
*		hält das programm an
*/
void generateOutput(int number){
	printf("CrossSum = %d\n",number);
	system("pause");
}

/*	int main
*		Ausgangsfunktion
*		mit funktions aufruf
*/
int main(){
	generateOutput(crossSum(getInput()));
}
