//Nazwa: Zad3L1
//Autor: Jakub Filistyński

#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	printf("Podaj liczbe.\n");
	int n;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		for(j = 0; j < 2*n; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
