#include <stdio.h>
#include <stdlib.h>


int testeMich(int zahl);
int aufAlles(int zahl);
void printZahl(int zahl);


int main() {
	int zahl;
	for (int i = 1; i < 5000; i++) {
		if(testeMich(i)!=-1){
			zahl = i;
			break;
		}
	}
	printZahl(zahl);
	system("PAUSE");
}

int testeMich(int zahl) {
	if (aufAlles(zahl) == 0) {
		return zahl;
	}else{
		return -1;
	}
}

int aufAlles(int zahl) {
	printf("Testlauf auf %d\n",zahl);
	for (int i = 1; i < 11; i++) {
		if (zahl % i) {
			return 1;
		}
	}
	return 0;
}

void printZahl(int zahl) {
	printf("%d\n", zahl);
}