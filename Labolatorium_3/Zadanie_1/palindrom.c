//palindrom.c
//Jakub Filistyński

#include <stdbool.h>
#include "file.h"
#include <string.h>
#include <stdio.h>

bool palindrom(char napis[])
{
	int dl = strlen(napis);
	bool spr = true;
	for(int i = 0; i < dl/2; i++){
		if(napis[i] != napis[dl-1-i]){
			spr = false;
			break;
		}
	}
	return spr;
}
