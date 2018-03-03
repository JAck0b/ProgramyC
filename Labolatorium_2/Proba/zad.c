#include <stdio.h>

void zmiana(int* n)
{
	*n = 123;
}

int main()
{
	int kuba;
	kuba = 12;
	printf("%d\n", kuba);
	zmiana(&kuba);
	printf("%d\n", kuba);
	return 0;
}
