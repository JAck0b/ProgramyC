//rozwiazanie2.c
//Jakub Filistyński

#include "file.h"
#include <math.h>

double rozwiazanie2(double a, double b, double eps)
{
	double p;
	while((b-a) > eps){
		p = (a+b)/2;
		if(f(a) == 0)
			return a;
		else if(f(b) == 0)
			return b;
		if(f(a) * f(p) <= 0)
			b = p;
		else
			a = p;
	}
	return a;
}
