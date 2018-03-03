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

void zerowa1(bool miejsca[6][4], int pierwszy, int drugi, int czarne, int biale, int pozycja1)
{
    //printf("pozycja = %d\n", pozycja1);
    if(czarne == 1 && biale == 0)
    {
        blokowanie(miejsca, pozycja1, pierwszy);
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1)
                miejsca[pierwszy-1][i] = false;
        }
    }
    else if(czarne == 0 && biale == 1)
    {
        miejsca[pierwszy-1][pozycja1-1] = false;
        miejsca[drugi-1][pozycja1-1] = false;
    }
}
 void zerowa2(bool miejsca[6][4], int pierwszy, int drugi, int czarne, int biale, int pozycja1, int pozycja2)
 {
    if(czarne == 2 && biale == 0)
    {
        blokowanie(miejsca, pozycja1, pierwszy);
        blokowanie(miejsca, pozycja2, pierwszy);
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1)
            {
                miejsca[pierwszy-1][i] = false;
                miejsca[drugi-1][i] = false;
            }
        }
    }
    if(czarne == 0 && biale == 2)
    {
        miejsca[pierwszy-1][pozycja1-1] = false;
        miejsca[pierwszy-1][pozycja2-1] = false;
        miejsca[drugi-1][pozycja1-1] = false;
        miejsca[drugi-1][pozycja2-1] = false;
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1 && i != pozycja2-1)
                blokowanie(miejsca, i+1, pierwszy);
        }
    }
 }

 void zerowa3(bool miejsca[6][4], int pierwszy, int drugi, int czarne, int biale, int pozycja1)
 {
    if(czarne == 3 && biale == 0)
    {
        miejsca[drugi-1][pozycja1-1] = false;
        for(int i = 0; i < 4; i++)
        {
            if(i != pozycja1-1)
                blokowanie(miejsca, i+1, pierwszy);
        }
    }
    else if(czarne == 2 && biale == 1)
    {
        blokowanie(miejsca, pozycja1, pierwszy);
    }
 }

void sprawdzenie(bool miejsca[6][4], int kod[4], int ilosc[6], int czarne, int biale, int pierwszy, int drugi)
{
    for(int i = 0; i < 4; i++)
        kod[i] = pierwszy;
    drukowanie(kod[0], kod[1], kod[2], kod[3], &czarne, &biale);
    ilosc[pierwszy-1] = biale + czarne;
    if(ilosc[pierwszy-1] == 4)
    {
        blokowanie(miejsca, 1, pierwszy);
        blokowanie(miejsca, 2, pierwszy);
        blokowanie(miejsca, 3, pierwszy);
        blokowanie(miejsca, 4, pierwszy);

    }
    if(ilosc[pierwszy-1] == 0)
    {
        for(int i = 0; i < 4; i++)
            miejsca[pierwszy-1][i] = false;
    }
    //
    for(int i = 0; i < 4; i++)
    {
        kod[i] = drugi;
    }
    int pomoc = 0;
    int gdzie[3] = {0, 0, 0};
    int dodatkowy = 0;
    for(int i = 0; i < ilosc[pierwszy-1]; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(miejsca[pierwszy-1][j] == true && kod[j] != pierwszy)
            {
                //printf("jetem\n");
                kod[j] = pierwszy;
                gdzie[pomoc] = j+1;
                pomoc++;
                break;
            }
        }
    }
    for(int i = 0; i < 4; i++)
    {
        if(i != gdzie[0]-1 && i != gdzie[1]-1 && i != gdzie[2]-1)
            dodatkowy = i+1;
    }
    drukowanie(kod[0], kod[1], kod[2], kod[3], &czarne, &biale);
    ilosc[drugi-1] = biale + czarne - ilosc[pierwszy-1];
    if(ilosc[drugi-1] == 4)
    {
        blokowanie(miejsca, 1, drugi);
        blokowanie(miejsca, 2, drugi);
        blokowanie(miejsca, 3, drugi);
        blokowanie(miejsca, 4, drugi);
    }
    else if(ilosc[pierwszy-1] == 1 && (ilosc[drugi-1] == 1 || ilosc[drugi-1] == 2 || ilosc[drugi-1] == 3))
        pojedyncza(miejsca, pierwszy, drugi, czarne, biale, gdzie[0]);
    else if(ilosc[pierwszy-1] == 3 && ilosc[drugi-1] == 1)
        pojedyncza(miejsca, drugi, pierwszy, czarne, biale, dodatkowy);
    else if(ilosc[pierwszy-1] == 2 && (ilosc[drugi-1] == 1 || ilosc[drugi-1] == 2))
        podwojna(miejsca, pierwszy, drugi, czarne, biale, gdzie[0], gdzie[1], kod);
    else if(ilosc[pierwszy-1] == 1 && ilosc[drugi-1] == 0)
        zerowa1(miejsca, pierwszy, drugi, czarne, biale, gdzie[0]);
    else if(ilosc[pierwszy-1] == 2 && ilosc[drugi-1] == 0)
        zerowa2(miejsca, pierwszy, drugi, czarne, biale, gdzie[0], gdzie[1]);
    else if(ilosc[pierwszy-1] == 3 && ilosc[drugi-1] == 0)
        zerowa3(miejsca, pierwszy, drugi, czarne, biale, dodatkowy);
    if(ilosc[drugi-1] == 0)
    {
        for(int i = 0; i < 4; i++)
            miejsca[drugi-1][i] = false;
    }
}

void redukcja(bool miejsca[6][4], int ostateczny[4], int ilosc[6], int sprawdzany)
{
    int licznik = 0;
    for(int i = 0; i < 4; i++)
        if(ostateczny[i] == sprawdzany)
            licznik++;
    if(licznik == ilosc[sprawdzany-1])
    {
        for(int i = 0; i < 4; i++)
        {
            if(ostateczny[i] != sprawdzany)
                miejsca[sprawdzany-1][i] = false;
        }
    }
}

void pewny(int ostateczny[4], bool miejsca[6][4])
{
    int zapamietuje;
    for(int i = 0; i < 4; i++)
    {
        if(ostateczny[i] == 0)
        {
            int licznik = 0;
            for(int j = 0; j < 6; j++)
            {
                if(miejsca[j][i] == true)
                {
                    licznik++;
                    zapamietuje = j+1;
                }
            }
            if(licznik == 1)
                ostateczny[i] = zapamietuje;
        }
    }
}

int main()
{
    bool miejsca[6][4];
    int ilosc[6] = {0, 0, 0, 0, 0, 0};
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 4; j++)
            miejsca[i][j] = true;
    int kod[4];
    int czarne, biale;
    int ostateczny[4] = {0, 0, 0, 0};
    int kandydaci[4][2];

    for(int i = 0; i < 6; i+=2)
    {
        sprawdzenie(miejsca, kod, ilosc, czarne, biale, i+1, i+2);
        if(ilosc[i] < 0 || ilosc[i+1] < 0)
        {
            printf("Oszukujesz!!!\n");
            return 0;
        }
        redukcja(miejsca, ostateczny, ilosc, i+1);
        redukcja(miejsca, ostateczny, ilosc, i+2);
        pewny(ostateczny, miejsca);
    }
    int spr = 0;
    for(int i = 0; i < 6; i++)
        spr = spr + ilosc[i];
    if(spr != 4)
        printf("Oszukujesz!!!\n");
    for(int j = 0; j < 4; j++)
    {
        int pierwszy, drugi;
        for(int i = 0; i < 6; i++)
        {
            if(i != ostateczny[0]-1 && i != ostateczny[1]-1 && i != ostateczny[2]-1 && i != ostateczny[3]-1 && ilosc[i] != 0)
                pierwszy = i+1;
        }
        for(int i = 0; i < 6; i++)
        {
            if(i != ostateczny[0]-1 && i != ostateczny[1]-1 && i != ostateczny[2]-1 && i != ostateczny[3]-1 && ilosc[i] != 0 && i != pierwszy-1)
                drugi = i+1;
        }

    }

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 4; j++)
            printf("%d", miejsca[i][j]);
        printf("\n");
    }
    printf("\n");
    for(int i = 0; i < 6; i++)
        printf("%d ", ilosc[i]);
    printf("\n");
    for(int i = 0; i < 4; i++)
        printf("%d ", ostateczny[i]);
    return 0;
}
