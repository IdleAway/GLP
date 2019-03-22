#include <stdio.h>
#include <math.h>

int main(){
	
	int anzahlZweiBeiner = 3;
	int zweiBeiner =2;
	int anzahlVierBeiner = 4;
	int vierBeiner =4;
	
	int beine = 90;
	
	for(int i=1;i<15;i++){
		int beine = 90-i*(anzahlZweiBeiner*zweiBeiner);
		printf("Beine : %d ",beine);
		if((beine % (anzahlVierBeiner*vierBeiner))==0){
			printf("TRUE bei i:%d rest: %d\n",i,beine % (anzahlVierBeiner*vierBeiner));
			
			int zweiBeinerBeine = i*(anzahlZweiBeiner*zweiBeiner)/3;
			
			int huehner = zweiBeinerBeine/2;
			int gaense = zweiBeinerBeine;
			
			int vierBeinerBeine = (90 -i*(anzahlZweiBeiner*zweiBeiner))/4;
			
			int schafe=vierBeinerBeine/4;
			int kanikel=schafe*3;
			
			printf("huehner %d\n",huehner);
			printf("gaense %d\n",gaense);
			printf("kanikel %d\n",kanikel);
			printf("schafe %d\n",schafe);
		}
	}
	return 0;
}