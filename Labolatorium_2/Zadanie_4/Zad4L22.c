//Nazwa: Zad4L22.c
//Autor: Jakub Filistyński

#include <stdio.h>
#include <stdbool.h>
#include <math.h>


int main(void)
{
	bool sito[100001]; //tworzenie sita
	for(int i = 2; i <= 100000; i++)
		sito[i] = true;
	sito[0] = false;
	sito[1] = false;
	int pomoc = (int)sqrt(100000); //obliczanie limitu
	int licznik = 0;
	for(int i = 2; i <= pomoc; i++)
		if(sito[i]) // wyszukiwanie liczb pierwszych i usuwanie ich wielokrotności
			for(int j = i+i; j <= 100000; j += i)
				sito[j] = false;
	for(int i = 2; i <= 100000; i++){ //liczenie liczb pierwszych
		if(sito[i])
			licznik++;
		printf("%d; %lf\n", i, (licznik*log((double)i))/i);
	}
	return 0;
}
