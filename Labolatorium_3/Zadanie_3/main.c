//main.c
//Jakub Filistyński

#include "file.h"
#include <stdio.h>

int main(void)
{
	long int n;
	printf("Podaj liczbe naturalną.\n");
	scanf("%ld", &n);
	printf("Wartośc fukncji = %d\n", phi(n));
	return 0;
}
