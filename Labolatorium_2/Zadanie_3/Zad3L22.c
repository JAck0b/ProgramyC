//Nazwa: Zad3L22.c
//Autor: Jakub Filistyński

#include <stdio.h>

int NWD(unsigned long long int a,unsigned long long int b)
{
	int pomoc = a%b;
	while(pomoc != 0){
		a = b;
		b = pomoc;
		pomoc = a%b;
	}
	return b;
}

int main(void)
{
	unsigned long long int M = 1, L = 1;
	int n = 2;
	int pom;
	while(L/M <= 10){
		L = L*n+M;
		M = M*n;
		pom = NWD(L, M);
		L = L/pom;
		M = M/pom;
		printf("%llu/%llu\n.", L, M);
		n++;
	}
	printf("Szukana liczba to %d\n.", n-1);
	return 0;
}
