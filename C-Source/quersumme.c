//Programm zum errechnen der Quersumme einer Zahl

//PSEUDOCODE//
/*
PROGRAMM_START

	function (int) crossSum(int number)
		int ret = 0
		while(zahl != 0) 
			DO
			ret = ret + number % 10
			number = number/2
		END_WHILE
		return ret
	end_function (int) quersumme

	function (int) getInput()
		clear(output)
		print("Type a number :")
		input = read()
		return input
	end_function (int) getInput()
	
	function (void) generateOutput(int number)
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
		int debug = number % 10;
		ret=ret + debug;
		printf("%d| +%d = %d\n",number,debug,ret);
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
	printf("input was %d\n",input);
	return input;
}

/*	void generateOutput
*		erwartet int wert als übergabe
*		gibt entsprechenden wert in der ausgabe aus
*		hält das programm an
*/
void generateOutput(int number){
	printf("Cross sum = %d\n",number);
	system("pause");
}

/*	int main
*		Ausgangsfunktion
*		mit funktions aufruf
*/
int main(){
	generateOutput(crossSum(getInput()));
}