/*	Pseudocode BoxÜbung

	PROGRAMM_START
	
		box boxen[3]
			
		zeitschrift {
			titel
			erscheinungsjahr
			nummer
		}
		
		box {
			farbe
			curZeitschriften
			zeitschriften[5]
		}
		
		zeitschrift createZeitschrift(){
			print("Zeitschrift erstellen")
			print("Titel: ")
			titel = input()
			print("Erscheinungsjahr: ")
			erscheinungsjahr = input()
			print("Nummer: ")
			nummer = input()
			zeitschrift ret = {titel,erscheinungsjahr,nummer}
			
			return ret
		}
		
		void putZeitschriftInBox(Zeitschrift zIn,box bIn){
			if(bIn.curZeitschriften<bIn.zeitschriften.length){
				bIn.zeitschriften[curZeitschriften]=zIn;
				bIn.curZeitschriften++
			}else{
				print(box.farbe+" Box ist voll")
			}
		}
		
		void lookInBox(){
			print("In welche Box willst du schauen?")
			for(i=0;i<3;i++){
				print("Box "i+1)
			}
			print("auswahl: ")
			auswahl = input()
			for(i=0;i<3;i++){
				if((input-1)==i){
					print("Box "+i+1+" "boxen[i].farbe," Paltz"+curZeitschriften/boxen[i].zeitschriften.length)
					for(j=0j<curZeitschriften;j++){
						print(box[i].zeitschriften[j])
					}
				}
			}
		}
		
		box box1 = {gelb,1,{{"Extrem Angeln im Weltall",333,1}}}
		box box2 = {gruen,1,{{"Die Katze der Moderne",20059,2}}}
		box box3 = {schwarz,1,{{"Lagunenhandel",1953,3}}}
		
		boxen[0]=box1
		boxen[1]=box2
		boxen[2]=box3
		
		
		main loop{
			running = true
			
			while (running){
				print('MENÜ')
				print('0 Exit')
				print('1 Zeitschrift erstellen')
				print('2 Box anzeigen')
				print('auswahl: ')
				input = eingabe()
				
				switch (input){
					
					case 1: 
						zeitschrift neu = createZeitschrift();
						print("box waehlen:")
						for(i=0;i<3;i++){
							print(i+1," ",box[i].farbe," box")
						}
						print('auswahl: ')
						nummerbox = eingabe()
						box target;
						for(i=0;i<3;i++){
							if((nummerbox-1)==i)
								target = boxen[i]
						}
						putZeitschriftInBox(neu,target)
						
					break;
					
					case 2:
						lookInBox()
					break;
					
					case 0:
						running = false;
					break;
					
					default:
						print("Osilayer 8 fehler....");
					break;
				}
				
			}
		}
		
	END_PROGRAMM
	*/
	
/*Imports von 	stdio.h für eingabe/ausgabe
				string.h für string manilpualtion
				stblib.h zur interaktion mit dem cmd
*/	
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
			
/*STRUKTuR Zeitschrift
	string titel[] mit maximal 50 zeichen
	intger erscheinungsjahr
	int nummer fortlaufend für eine reihe
*/	
typedef struct {
	char titel[50];
	int erscheinungsjahr;
	int nummer;
}zeitschrift;
		
/*STRUKTUR Box
	string farbe[] mit maximal 10 zeichen
	int curZeitschriften zum speichern der momentan enthaltenden zeitschriften
	int maxZeitschriften maximal zu speichernde zeitschriften
	array zeitschriften[] zum speichern der zeitschriften structs
*/
typedef struct {
	char farbe[10];
	int curZeitschriften;
	int maxZeitschriften;
	zeitschrift zeitschriften[5];
}box;


/*Function zeitschrift createZeitschrift()

	fragt den benutzer nach im struct 
	vorhandenen variablen um eine zeitschrift zu erstellen
	diese wird zurückgegeben
	*/		
zeitschrift createZeitschrift(){
	
	system("cls");
	
	const int MAX = 50;
	char titel[MAX];
	int erscheinungsjahr;
	int nummer;
	
	puts("Zeitschrift erstellen");
	printf("Titel: ");
	fgets(titel,MAX,stdin);
	fflush(stdin);
	printf("Erscheinungsjahr: ");
	scanf("%d",&erscheinungsjahr);
	fflush(stdin);
	printf("Nummer: ");
	scanf("%d",&nummer);
	fflush(stdin);
	
	zeitschrift ret;
	strcpy(ret.titel,titel);
	ret.erscheinungsjahr=erscheinungsjahr;
	ret.nummer=nummer;
			
	return ret;
}


/*Function box putZeitschriftInBox(zeitschrift, box)

	erfordert als parameter die zu speichernde zeitschrift
	und die dazugehörige box
	
	prüft anhand der box ob noch eine zeitschrift aufgenommen werden kann
	und gibt dem Benutzer auskunft ob es geklappt hat oder nicht
	
	wenn eine zeitschrift einer box hinzugefügt wurde erhöht sich 
	curZeitschriften in box
	
	box wird zurückgegeben
	
*/	
box putZeitschriftInBox(zeitschrift zIn,box bIn){
	if(bIn.curZeitschriften<bIn.maxZeitschriften){
		bIn.zeitschriften[bIn.curZeitschriften]=zIn;
		printf("Neu %s\n",bIn.zeitschriften[bIn.curZeitschriften].titel);
		bIn.curZeitschriften++;
	}else{
		printf("Box mit farbe %s ist voll\n",bIn.farbe);
		system("pause");
	}
	return bIn;
}

/*Function printZeitschrift erwartet ein struct Zeitschrift zur ausgabe
*/
void printZeitschrift(zeitschrift zIn){
	printf("\n%s %d %d",zIn.titel,zIn.erscheinungsjahr,zIn.nummer);
}

/*Function lookInBox erwartet das array in dem alle boxen gespeichert sind

	der benutzer wird gefragt welche box er sich anschauen möchte
	diese wird ausgegeben
	und für jede vorhandene zeitschrift die funktion printZeitschrift aufgerufen
*/
void lookInBox(box boxen[]){
	
	system("cls");
	int input;
	
	puts("In welche Box willst du schauen?");
	for(int i=0;i<3;i++){
		printf("Box %d\n",i+1);
	}
	printf("Auswahl: ");
	scanf("%d",&input);
	fflush(stdin);
	system("cls");
	for(int i=0;i<3;i++){
		if((input-1)==i){
			printf("Box %d mit farbe %s | %d/%d",(i+1),boxen[i].farbe,boxen[i].curZeitschriften,boxen[i].maxZeitschriften);
			for(int j=0;j<boxen[i].curZeitschriften;j++){
				printZeitschrift(boxen[i].zeitschriften[j]);
			}
			puts(" ");
		}
	}
	system("pause");
}

int main(){
	
	int running = 1;
	box box1 = {"gelb",1,5,{{"Extrem Angeln im Weltall",333,1}}};
	box box2 = {"gruen",1,5,{{"Die Katze der Moderne",20059,2}}};
	box box3 = {"schwarz",1,5,{{"Lagunenhandel",1953,3}}};

	box boxen[3];
	boxen[0]=box1;
	boxen[1]=box2;
	boxen[2]=box3;

	while (running){
		
		system("cls");
		
		puts("Menu");
		puts("0 Exit");
		puts("1 Zeitschrift erstellen");
		puts("2 Box anzeigen");
		printf("auswahl: ");
		int input;
		scanf("%d",&input);
		fflush(stdin);
		
		switch (input){
			
			case 1: 
			
				system("cls");
				
				printf("box waehlen:");
				for(int i=0;i<3;i++){
					printf("\nBox %d %s ",(i+1),boxen[i].farbe);
				}
				printf("\nAuswahl: ");
				int nummerBox;
				scanf("%d",&nummerBox);
				fflush(stdin);
				for(int i=0;i<3;i++){
					if((nummerBox-1)==i){
						boxen[i]= putZeitschriftInBox(createZeitschrift(),boxen[i]);
					}
				}
				break;
			
			case 2:
				lookInBox(boxen);
			break;
			
			case 0:
				running = 0;
			break;
			
			default:
				puts("Osi-Layer 8 fehler....");
				system("pause");
			break;
		}
	}
}