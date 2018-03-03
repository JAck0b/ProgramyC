//Zadanie1.c
//Jakub Filistyński 

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool match(char* wzorzec, char* lancuch)
{
	int dlz = strlen(wzorzec);
	int dll = strlen(lancuch);
	bool gwiazdka = false;
	bool zapytanie = false;
	
	for(int i = 0; i < dlz; i++){ //można wypróbować case
		if(wzorzec[i] == '?')
			zapytanie = true;
		else if(wzorzec[i] == '*')
			gwiazdka = true;
		if(gwiazdka == true && zapytanie == true)
			break;
	}
	if(zapytanie == true && gwiazdka == false){ //przypadek gdy są same znaki zapytania i symbole
		if(dlz == dll){
			bool spr[dll];
			for(int i = 0; i < dll; i++){//zerowanie sprawdzającej tablicy
				spr[i] = false;
			}
			for(int i = 0; i< dll; i++){
				if(wzorzec[i] == lancuch[i] || wzorzec[i] == '?'){ //sprawdzanie zgodności
					spr[i] = true;
				}
				else
					return false;
			}
			for(int i = 0; i < dll; i++){ //sprawdzanie, czy wszystkie litery wystąpiły
				if(spr[i] == false)
					return false;
			}
			return true;
		}
		else
			return false;
	}
	if(zapytanie == false && gwiazdka == false){
		if(dlz == dll){
			bool spr = true;
			for(int i = 0; i < dll; i++){
				spr = spr && wzorzec[i] == lancuch[i];
			}
			if(spr == true)
				return true;
			else return false;
		}
		else
			return false;
	}
	return false;
}
			
			
			

int main()
{
	int dl;
	printf("Podaj dlugość łańcucha znaków.\n");
	scanf("%d", &dl);
	char lancuch[dl+1];
	scanf("%s", lancuch);
	int dlw;
	printf("Podaj dlugość wzorca znaków.\n");
	scanf("%d", &dlw);
	char wzorzec[dlw+1];
	scanf("%s", wzorzec);
	bool spr = match(wzorzec, lancuch);
	if(spr)
		printf("Jest ok.\n");
	else
		printf("Nie jest ok.\n");
	return 0;
}
