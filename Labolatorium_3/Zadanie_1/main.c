//main.c
//Jakub Filistyński

#include <stdio.h>
#include <stdbool.h>
#include "file.h"

int main(void)
{
	int n;
	printf("Podaj ile bedzie miał napis.\n");
	scanf("%d", &n);
	if(n > 0){
		char napis[n+1];
		scanf("%s", napis);
		if(palindrom(napis))
			printf("Tak.\n");
		else
			printf("Nie.\n");
	}
	else
		printf("Tak.\n");
	return 0;
}
