//main.c
//Jakub Filistyński

#include <stdio.h>
#include "agents.h"

int main(void)
{
	//int x, y;
	//printf("Podaj współżędną x oraz y dla Boba.\n");
	//scanf("%d %d", &x, &y);
	struct agent Bob = newagent(0, 0);
	//printf("Podaj współżędną x oraz y dla Alice.\n");
	//scanf("%d %d", &x, &y);
	struct agent Alice = newagent(3, 3);
	north(&Bob);
	south(&Alice);
	west(&Alice);
	north(&Bob);
	east(&Bob);
	south(&Alice);
	printf("Dystant pomiędzy Alice i Bobem = %lf\n", distance(Alice, Bob));
	return 0;
}
