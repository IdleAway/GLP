#include <stdio.h>

int main() {
	int a = 3;
	int b = 5;
	
	int kleinste = (a>b) ? b : a;
	
	printf("%d",kleinste);
	
	return 0;
}