/*Addition im array*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int berechneToInt(char[],int);
int isValid(char[],int);
int getLength(char[]);


int main(){
	
	int ergebnis = 0;
	char aufgabe[50];
	int length=0;
	
	system("CLS");
	puts("Aufgabe in einer Zeile angeben! OHNE LEERZEICHEN!");
	fgets(aufgabe,50,stdin);
	fflush(stdin);
	
	
	length=getLength(aufgabe);
	if(isValid(aufgabe,length)){
		ergebnis = berechneToInt(aufgabe,length);
	}
	printf("Das Ergebnis ist %d\n",ergebnis);
	system("PAUSE");
}

/* int getLength(char array[])
	benötigt ein arrayTyp Char
	und liefert die länge des arrays
	zurück
*/
int getLength(char array[]){
	int ret =0;
	for(int i=0;array[i]!='\0';i++){
		ret++;
	}
	return ret;
}

/*	int isValid(char array[],int length)
	benötigt übergabewerte char Array und
	die länge des übergebenen Arrays.
	Überprüft ob im array Zeichen vorhanden
	sind, die wir nicht wollen.
	
	Ist das array frei von unerwünschten zeichen
	wird valid nicht geändert
	Sollte ein Zeichen gefunden werden, dass
	wir nicht haben wollen wird valid auf 0
	gesetzt
	
	valid wird zurückgegeben
*/
int isValid(char array[],int length){
	int valid = 1;
	for(int i=0;i<length;i++){
		//printf("Testing %c",array[i]);
		if(isalpha(array[i])){
			//printf(" not valid\n");
			valid =  0;
		}else{
			//printf(" valid\n");
		}
	}
	return valid;
}

/*	int createRightArgument bzw createLeftArgument (char array[],int end)
	erwartet array des typs char und die stelle wo es aufhören soll.
	
	berechnet das linke bzw rechte argument der formel (links und rechts vom operator)
	
	und gibt die zahl zurück
*/
int createRightArgument(char array[],int start,int end){
	int ret=0;
	for(int i=start+1;i<end-1;i++){ //+1 weil eine stelle nach operator, -1 da letzte stelle '\n'
		ret=(ret*10)+(array[i]-48);
	}
	return ret;
}
int createLeftArgument(char array[],int start,int end){
	int ret=0;
		for(int i=start;i<end;i++){
		ret=(ret*10)+(array[i]-48);
	}
	return ret;
}



/*	int berechneToInt(char array[],int length)
	benötigt übergabewerte char Array und die
	länge des übergebenen arrays.
	
*/
int berechneToInt(char array[],int length){
	int ret = 0;
	int posOperator=0;

	//Operator pos rausfinden
	for(int i=0;i<length;i++){
		//printf("Teste %c\n",array[i]);
		if(array[i]=='+'||array[i]=='-'){
			posOperator = i;
			//printf("Operator %c at %d\n",array[i],i);
		}
	}
	
	int leftArgument=createLeftArgument(array,0,posOperator);
	int rightArgument=createRightArgument(array,posOperator,length);
	
	printf("%d und %d ",leftArgument,rightArgument);
	
	if(array[posOperator]=='+'){
		ret= leftArgument+rightArgument;
	}else if(array[posOperator]=='-'){
		ret = leftArgument-rightArgument;
	}
	
	return ret;
}

