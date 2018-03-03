//main.c
//Jakub Filistyński

#include <stdio.h>
#include "file.h"
#include <math.h>

int main(void)
{
	double a = 2, b = 4, eps;
	for(int i = -1; i >= -8; i--){
		eps = pow(10,i);	
		printf("Epsilon = %.9lf - rozwiazanie = %.9lf\n",eps, rozwiazanie2(a, b, eps));
	}	
	return 0;
}
