//Nazwa: Zad4L1.c
//Autor: Jakub Filistyński

#include <stdio.h>

int main(void)
{
	int n;
	printf("Wpisz liczbę naturanlną.\n");
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++){
		for(int j = 0; j < n-i-1; j++)
			printf(" ");
		for(int k = 0; k < 2*i+1; k++)
			printf("*");
		printf("\n");
	}
	return 0;
}
