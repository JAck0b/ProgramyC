//proba.c
//Jakub Filistyński

#include <stdio.h>
#include <stdbool.h>

void drukowanie(int a1, int a2, int a3, int a4, int *czarne, int *biale)
{
    printf("[%d][%d][%d][%d]\n", a1, a2, a3, a4);
    printf("Czarne: ");
    scanf("%d", czarne);
    printf("Białe: ");
    scanf("%d", biale);
}

void blokowanie(bool miejsca[6][4], int gdzie, int wolne)
{
    for(int i = 0; i < 6; i++)
        miejsca[i][gdzie-1] = false;
    miejsca[wolne-1][gdzie-1] = true;

}

int przesuwanie(bool miejsca[6][4], int kod[], int obecna_pozycja, int kto)
{
    int j;
    for(int i = 0; i < 4; i++)
    {

        if(miejsca[kto-1][i] == true && kod[i] != kto)
        {
            j = i;
            int pomoc;
            pomoc = kod[obecna_pozycja-1];
            kod[obecna_pozycja-1] = kod[i];
            kod[i] = pomoc;
            break;
        }
    }
    return j+1;
}


void pojedyncza(bool miejsca[6][4],int pierwszy, int drugi, int czarne, int biale, int pozycja_pierwszego)
{

    if((czarne == 2 || czarne == 3 || czarne == 4) && biale == 0) //gdy są same czarne
    {
        blokowanie(miejsca, pozycja_pierwszego, pierwszy);
    }
    else if(czarne == 1 && biale == 1)
    {
        miejsca[pierwszy-1][pozycja_pierwszego-1] = false;
        miejsca[drugi-1][pozycja_pierwszego-1] = false;
    }
    else if(czarne == 0 && biale == 2)
    {
        blokowanie(miejsca, pozycja_pierwszego, drugi);
    }
    else if(czarne == 2 && biale == 1)
    {
        miejsca[pierwszy-1][pozycja_pierwszego-1] = false;
        miejsca[drugi-1][pozycja_pierwszego-1] = false;
    }
    else if((czarne == 1 || czarne == 2) && biale == 2)
    {
        blokowanie(miejsca, pozycja_pierwszego, drugi);
    }
}

void dwa_do_jednego(bool miejsca[6][4], int pierwszy, int drugi, int czarne, int biale,int pozycja1, int pozycja2, int kod[], int poprzednia_pozycja)
{
    pozycja1 = przesuwanie(miejsca, kod, pozycja1, pierwszy);
    drukowanie(kod[0], kod[1], kod[2], kod[3], &czarne, &biale);
    if(czarne == 3 && biale == 0)
    {
        blokowanie(miejsca, pozycja1, pierwszy);
        blokowanie(miejsca, pozycja2, pierwszy);
        miejsca[pierwszy-1][poprzednia_pozycja-1] = false;
        miejsca[drugi-1][poprzednia_pozycja-1] = false;
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1&& i != poprzednia_pozycja-1)
                blokowanie(miejsca, i+1, drugi);
        }
    }
    else if(czarne == 2 && biale == 1)
    {
        blokowanie(miejsca, pozycja1, pierwszy);
        blokowanie(miejsca, poprzednia_pozycja, pierwszy);
        miejsca[drugi-1][pozycja2-1] = false;
        miejsca[pierwszy-1][pozycja2-1] = false;
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1 && i != poprzednia_pozycja-1)
                blokowanie(miejsca, i+1, drugi);
        }
    }
    else if(czarne == 1 && biale == 2)
    {
        blokowanie(miejsca, pozycja1, drugi);
        miejsca[drugi-1][poprzednia_pozycja-1] = false;
        miejsca[pierwszy-1][poprzednia_pozycja-1] = false;
        blokowanie(miejsca, pozycja2, pierwszy);
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1 && i != poprzednia_pozycja-1)
                blokowanie(miejsca, i+1, pierwszy);
        }
    }
    else if(czarne == 0 &&  biale == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1)
                blokowanie(miejsca, i+1, pierwszy);
        }
        blokowanie(miejsca, pozycja1, drugi);
        miejsca[pierwszy-1][pozycja2-1] = false;
        miejsca[drugi-1][pozycja2-1] = false;
    }
}

void jeden_do_dwoch(bool miejsca[6][4], int pierwszy, int drugi, int czarne, int biale,int pozycja1, int pozycja2, int kod[], int poprzednia_pozycja)
{
    pozycja1 = przesuwanie(miejsca, kod, pozycja1, pierwszy);
    drukowanie(kod[0], kod[1], kod[2], kod[3], &czarne, &biale);
    if(czarne == 3 && biale == 0)
    {
        blokowanie(miejsca, pozycja1, pierwszy);
        blokowanie(miejsca, pozycja2, pierwszy);
        blokowanie(miejsca, poprzednia_pozycja, drugi);
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1 && i != poprzednia_pozycja-1)
            {
                miejsca[pierwszy-1][i] = false;
                miejsca[drugi-1][i] = false;
            }
        }
    }
    else if(czarne == 2 && biale == 1)
    {
        miejsca[drugi-1][pozycja1-1] = false;
        miejsca[pierwszy-1][pozycja1-1] = false;
        blokowanie(miejsca, poprzednia_pozycja, drugi);
        blokowanie(miejsca, pozycja2, pierwszy);
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1 && i != poprzednia_pozycja-1)
            {
                blokowanie(miejsca, i+1, pierwszy);
            }
        }
    }
    else if(czarne == 1 && biale == 2)
    {
        blokowanie(miejsca, pozycja1, pierwszy);
        blokowanie(miejsca, poprzednia_pozycja, pierwszy);
        blokowanie(miejsca, pozycja2, drugi);
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1 && i != poprzednia_pozycja-1)
            {
                miejsca[pierwszy-1][i] = false;
                miejsca[drugi-1][i] = false;
            }
        }
    }
    else if(czarne == 0 && biale == 3)
    {
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1)
                blokowanie(miejsca, i+1, pierwszy);
        }
        blokowanie(miejsca, pozycja2, drugi);
        miejsca[pierwszy-1][pozycja1-1] = false;
        miejsca[drugi-1][pozycja1-1] = false;
    }
}

void dwa_do_dwoch(bool miejsca[6][4], int pierwszy, int drugi, int czarne, int biale,int pozycja1, int pozycja2, int kod[], int poprzednia_pozycja)
{
    for(int i = 0; i < 4; i++) //szukanie czwartego miejsca
    {
        if(i != pozycja1-1 && i != pozycja2-1 && i != poprzednia_pozycja-1)
        {
            poprzednia_pozycja = pozycja1;
            pozycja1 = i+1;
        }
    }
    int pomoc; //zamiana miejsc
    pomoc = kod[poprzednia_pozycja-1];
    kod[poprzednia_pozycja-1] = kod[pozycja1-1];
    kod[pozycja1-1] = pomoc;
    drukowanie(kod[0], kod[1], kod[2], kod[3], &czarne, &biale); //drukowanie i sprawdzenie który z przypadków teraz występuje
    if(czarne == 4)
    {
        blokowanie(miejsca, pozycja1, pierwszy);
        blokowanie(miejsca, pozycja2, pierwszy);
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1)
                blokowanie(miejsca, i+1, drugi);
        }
    }
    else if(czarne == 0)
    {
        blokowanie(miejsca, pozycja1, drugi);
        blokowanie(miejsca, pozycja2, drugi);
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1)
                blokowanie(miejsca, i+1, pierwszy);
        }
    }
}
void podwojna(bool miejsca[6][4], int pierwszy, int drugi, int czarne, int biale, int pozycja1, int pozycja2, int kod[])
{
    int poprzednia_pozycja = pozycja1;
    if((czarne == 3 || czarne == 4) && biale == 0) //gdy kolor pierwszy jest ustawiony odpowiednio bez względu na przypadek
    {
        blokowanie(miejsca, pozycja1, pierwszy);
        blokowanie(miejsca, pozycja2, pierwszy);
    }
    else if(czarne == 2 && biale == 1) //gdy stosunek czarnych do białych to 2 do 1
    {
        dwa_do_jednego(miejsca, pierwszy, drugi, czarne, biale, pozycja1, pozycja2, kod, poprzednia_pozycja);
    }
    else if(czarne == 1 && biale == 2) //gdy stosunek czarnyc do białych to 1 do 2
    {
        jeden_do_dwoch(miejsca, pierwszy, drugi, czarne, biale, pozycja1, pozycja2, kod, poprzednia_pozycja);
    }
    else if(czarne == 0 && biale == 3) //gdy wszystkie kolory sa na złych pozycjach
    {
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1)
                blokowanie(miejsca, i+1, pierwszy);
        }
    }
    //gdy stosunek jest 2 do 2 i mamy 4 kule
    else if(czarne == 2 && biale == 2)
    {
        pozycja1 = przesuwanie(miejsca, kod, pozycja1, pierwszy);
        drukowanie(kod[0], kod[1], kod[2], kod[3], &czarne, &biale);
        if(czarne == 4)
        {
            blokowanie(miejsca, pozycja1, pierwszy);
            blokowanie(miejsca, pozycja2, pierwszy);
            for(int i = 0; i < 4; i++)
            {
                if(i != pozycja1-1 && i != pozycja2-1)
                    blokowanie(miejsca, i+1, drugi);
            }
        }
        else if(czarne == 0)
        {
            blokowanie(miejsca, pozycja1, drugi);
            blokowanie(miejsca, pozycja2, drugi);
            for(int i = 0; i < 4; i++)
            {
                if(i != pozycja1-1 && i != pozycja2-1)
                    blokowanie(miejsca, i+1, pierwszy);
            }
        }
        else if(czarne == 2 && biale == 2) //gdy nie udało się jeszcze rozwiązać
        {
            dwa_do_dwoch(miejsca, pierwszy, drugi, czarne, biale, pozycja1, pozycja2, kod, poprzednia_pozycja);
        }

    }
    else if(czarne == 0 && biale == 4)// gdy wszystkie kolory sa na złych pozycjach
    {
        blokowanie(miejsca, pozycja1, drugi);
        blokowanie(miejsca, pozycja2, drugi);
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1)
                blokowanie(miejsca, i+1, pierwszy);
        }
    }
}

int main()
{
    bool miejsca[6][4];
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 4; j++)
            miejsca[i][j] = true;
    int kod[4] = {1, 2, 2, 1};
    //for(int i = 0; i < 4; i++)
    //    kod[4] = -1;
    int czarne, biale;
    czarne = 2;
    biale = 1;
    podwojna(miejsca, 1, 2, czarne, biale, 1, 4, kod);
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 4; j++)
            printf("%d", miejsca[i][j]);
        printf("\n");
    }
    return 0;
}