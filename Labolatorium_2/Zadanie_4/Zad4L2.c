//Nazwa: Zad4L2.c
//Autor: Jakub Filistyński

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool pierwsza(int n)
{
	for(int i = 2; i <= sqrt(n); i++){
		if(n%i == 0)
			return false;
	}
	return true;
}

void ilosc(int n, int* licznik)
{
		if(pierwsza(n))
			(*licznik)++;
}

int main(void)
{
	int licznik = 0;
	for(int i = 2; i <= 100000; i++){
		ilosc(i, &licznik);
		printf("%d; %lf\n", i, (licznik*log((double)i))/i);
	}
	return 0;
}
