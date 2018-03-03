//phi.c
//Jakub Filistyński

#include "file.h"
#include <stdbool.h>

int phi(long int n)
{
	int j = 2;
	bool pierwsze[n];
	for(int i = 2; i < n; i++)
		pierwsze[i] = true;
	pierwsze[0] = false;
	pierwsze[1] = true;
	int pomoc;
	//wyszukiwanie liczb względnie pierwszych z 'n' za pomoca zmodyfikowanego sita
	while(j <= n/2){
		if(pierwsze[j] && n%j == 0){
			pomoc = j;
			while(pomoc < n){
				pierwsze[pomoc] = false;
				pomoc += j;
			}
		}
		j++;
	}
	//zliczanie liczb wzglednie pierwszych z'n'
	j = 0;
	for(int i = 0; i < n; i++)
		if(pierwsze[i])
			j++;
	return j;
}
			
		
		
