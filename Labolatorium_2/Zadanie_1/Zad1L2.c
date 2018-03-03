//Nazwa: Zad1L2.c
//Autor: Jakub Filistyński

#include <stdio.h>
#include <assert.h>

int main(void)
{
	int zl, gr;
	printf("Podaj liczbę złotych i liczbę groszy.\n Liczba groszy powinna być mniejsza niż 100.\n");
	printf("Liczba złotych = ");
	scanf("%d", &zl);
	printf("Liczba groszy = ");
	scanf("%d", &gr);
	assert(gr < 100);
	int kasa[8] = {1, 2, 5, 10, 20, 50, 100, 200}; //tablica z pieniędzmi
	int ilosc[8]; // tablica przechowywująca ilość pieniędzy
	for(int i = 0; i < 8; i++) 
		ilosc[i] = 0;
	int pomoc = 0;
	for(int i = 7; i >= 0; i--){ //ustalanie ile złotówek
		pomoc = zl/kasa[i];
		zl = zl - kasa[i]*pomoc;
		ilosc[i] = pomoc;
	}
	printf("Złotówki.\n");
	for(int i = 7; i >= 0; i--)
		printf("%d - %d\n", kasa[i], ilosc[i]);
	for(int i = 5; i >= 0; i--){ //ustalanie ile groszy
		pomoc = gr/kasa[i];
		gr = gr - kasa[i]*pomoc;
		ilosc[i] = pomoc;
	}
	printf("Grosze.\n");
	for(int i = 5; i >= 0; i--)
		printf("%d - %d\n", kasa[i], ilosc[i]);
	return 0;
}
