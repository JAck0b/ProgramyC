//Nazwa: Zad5L2.c
//Autor: Jakub Filistyński

#include <stdio.h>
#include <stdbool.h>

bool NWD(int a, int b)
{
	int q = a%b;
	while(q != 0){
		a = b;
		b = q;
		q = a%b;
	}
	if(b == 1)
		return true;
	return false;
}

void spr(int n, int *licznik) //liczby ile jest par liczb względnie pierwszych
{
	(*licznik)++;
	for(int i = 2; i < n; i++){
		if(NWD(i, n))
			(*licznik)++;
	}
}

int main(void)
{
	int licznik = 0;
	for(int i = 1; i <= 1000; i++){ //sprawdzanie wszystkich liczb
		if(i != 1)
			spr(i, &licznik);
		printf("%d; %lf\n", i, (double)(2*(double)licznik+1)/(i*i));
	}
	return 0;
}
