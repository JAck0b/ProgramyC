//Nazwa: Zad3L2.c
//Autor: Jakub Filistyński

#include <stdio.h>

int main(void)
{
	int n = 0;
	float wynik = 0;
	while(wynik <= 10){
		n++;
		wynik = wynik + (float)1/(n);
	}
	printf("Najmniejszą taką liczbą jest %d.\n", n);
	return 0;
}
		
