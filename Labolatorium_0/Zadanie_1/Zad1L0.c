//Nazwa: Zad1L0.c
//Autor: Jakub Filistyński

#include <stdio.h>

int main(void)
{
	printf("Podaj dwie liczby rzeczywiste. Druga musi być różna od zera.\n");
	float a, b;
	scanf("%f %f", &a, &b);
	printf("Suma liczb a i b wynosi: %f.\n", a+b);
	printf("Różnica liczb a i b wynosi: %f.\n", a-b);
	printf("Iloczyn liczb a i b wynosi: %f.\n", a*b);
	printf("Iloraz liczb a i b wynosi: %f.\n", a/b);
	return 0;
}
