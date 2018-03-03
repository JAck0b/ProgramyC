//Nazwa: Zad2L2.c
//Autor: Jakub Filistyński

#include <stdio.h>
#include <assert.h>

int main(void)
{
	int n;
	printf("Podaj ile będzie liczb.\n");
	scanf("%d", &n);
	assert(n>0);
	printf("Podaj kolejne liczby rzeczywiste.\n");
	int srednia = 0;
	float pomoc;
	for(int i = 0; i < n; i++){
		scanf("%f", &pomoc);
		srednia += pomoc;
	}
	printf("Średnia wynosi: %f.\n", srednia/(float)n);
	return 0;
}
