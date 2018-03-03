//Nazwa: Zad2L0.c
//Autor: Jakub Filistyński 

#include <stdio.h>

int main(void)
{
	float c, f;
	printf("Podaj temperaturę w stopniach celcjusza.\n");
	scanf("%f", &c);
	f = 1.8 * c + 32;
	printf("Temperatura w stopniach Fagrenheita wynosi: %f.\n", f);
	return 0;
}
