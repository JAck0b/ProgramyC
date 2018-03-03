//Nazwa: Zad6L2.c
//Autor: Jakub Filistyński

#include <stdio.h>
#include <math.h>

int spr(int n) // sumowanie dzielników
{
	int suma = 1;
	int limit = (int)sqrt(n);
	for(int i = 2; i <= limit; i++)
		if(n%i == 0){
			suma += i;
			suma += n/i;
		}
	return suma;
}


int main(void)
{
	int tab[999];
	int pomoc;
	for(int i = 2; i <= 1000; i++){ //liczenie sumy dzielników oraz szukanie liczb doskonałychc
		pomoc = spr(i);
		if(pomoc == i)
			printf("%d jest liczbą doskonałą.\n", i);
		tab[i-2] = pomoc;
	}
	for(int i = 0; i < 999; i++){ //szukanie liczb zaprzyjaźnionych
		if(i+2 == tab[tab[i]-2])
			printf("(%d, %d) to liczby zaprzyjaźnione.\n", i+2, tab[i]);
	}
	return 0;
}
