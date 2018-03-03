//Nazwa: Zad2L1.c
//Autor: Jakub Filistyński

#include <stdio.h>
#include <math.h>

int main(void)
{
	float a, b, c, delta;
	printf("Podaj współczynniki funkcji.\n");
	printf("a = ");
	scanf("%f", &a);
	printf("b = ");
	scanf("%f", &b);
	printf("c = ");
	scanf("%f", &c);
	delta = b*b - 4*a*c;
	if(delta < 0)
		printf("Nie ma w zbiorze liczb rzeczywistych rozwiązania tego równania.\n");
	else if(delta == 0)
		printf("Rozwiązaniem tego równania jest liczba: %f.\n", ((-b)/2*a));
	else
		printf("Rozwiązaniami tego równania są: %lf oraz %lf.\n", ((-b)+sqrt(delta))/(2*a), ((-b)-sqrt(delta))/(2*a));
	return 0;
}
	
