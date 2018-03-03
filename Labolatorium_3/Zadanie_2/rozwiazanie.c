//rozwiazanie.c
//Jakub Filistyński

#include "file.h"
#include <math.h>

double rozwiazanie(double a, double b, double eps)
{
	double p = (a+b)/2;
	if(cos(a/2) == 0)
		return a;
	else if(cos(b/2) == 0)
		return b;
	else if(b-a <= 2*eps)
		return p;
	if(cos(p/2) * cos(a/2) <= 0)
		return rozwiazanie(a, p, eps);
	else
		return rozwiazanie(p, b, eps);
}

