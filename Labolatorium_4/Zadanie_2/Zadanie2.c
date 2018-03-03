// Copyright 2018 Jakub Filistynski
#include <stdio.h>
#include <stdbool.h>

#define D 7

bool ball(int e[4], int l[4], int black, int white) {
    int amount[8] = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 4; i++)
        amount[l[i]] += 1;
    int now_black = 0;
    int now_white = 0;
    for (int i = 0; i < 4; i++) {
        if (amount[e[i]] > 0) {
            amount[e[i]] -= 1;
                now_white++;
        }
    }
    for (int i = 0; i < 4; i++)
        if (e[i] == l[i]){
                now_black++;
                now_white--;
        }
    if ((black == now_black) && (white == now_white))
        return true;
    return false;
}


int check(bool tab[D][D][D][D], int e[4], int black, int white) {
// checking how many would be stop
    int count = 0;
    for (int a = 1; a < D; a++)
        for (int b = 1; b < D; b++)
            for (int c = 1; c < D; c++)
                for (int d = 1; d < D; d++)
                    if (tab[a][b][c][d] == true) {
                        int l[4] = {a, b, c, d};
                        if (!ball(e, l, black, white))
                            count++;
                    }
    return count;
}

bool lookingfor(int e[4], bool tab[D][D][D][D], int black, int white) {
// I'm looking for code
        for (int a = 1; a < D; a++)
            for (int b = 1; b < D; b++)
                for (int c = 1; c < D; c++)
                    for (int d = 1; d < D; d++)
                        if (tab[a][b][c][d] == true) {
                            e[0] = a;
                            e[1] = b;
                            e[2] = c;
                            e[3] = d;
                            return true;
                        }
    return false;
}

void removing(bool tab[D][D][D][D], int e[4], int black, int white){
    for(int a = 1; a < D; a++)
        for(int b = 1; b < D; b++)
            for(int c = 1; c < D; c++)
                for(int d = 1; d < D; d++)
                    if(tab[a][b][c][d] == true){
                        int l[4] ={a, b, c, d};
                        if(!ball(e, l, black, white))
                            tab[a][b][c][d] = false;
                    }




}

bool ultimately(bool tab[D][D][D][D], int e[4]){
    int tmp = 0;
    for(int a = 1; a < D; a++)
        for(int b = 1; b < D; b++)
            for(int c = 1; c < D; c++)
                for(int d = 1; d < D; d++){
                    if(tab[a][b][c][d] == true){
                        tmp++;
                        e[0] = a;
                        e[1] = b;
                        e[2] = c;
                        e[3] = d;
                    }
                    if(tmp > 1)
                    {
                        for(int i = 0; i < 4; i++)
                            e[i] = 0;
                        return true;
                    }
                }
    if(tmp == 0)
        return false;
    return true;
}


int main()
{
    bool tab[D][D][D][D];
    for(int a = 1; a < D; a++){
        for(int b = 1; b < D; b++){
            for(int c = 1; c < D; c++){
                for(int d = 1; d < D; d++){
                    tab[a][b][c][d] = true;
                }
            }
        }
    }
    int e[4] = {0,0,0,0};
    int black = 0;
    int white = 0;
    int z = 0;
    bool tmp = true;
    while(e[0] == 0){
        if(z == 0){
            e[0] = 1;
            e[1] = 1;
            e[2] = 2;
            e[3] = 2;
            z++;
        }
        else{
            lookingfor(e, tab, black, white);
            z++;
        }
        for(int i = 0; i < 4; i++)
            printf("[%d]", e[i]);
        printf("\nblack = ");
        scanf("%d", &black);
        printf("white = ");
        scanf("%d", &white);
        printf("\n");
        removing(tab, e, black, white);
        if (tab[6][4][6][3] == false)
            printf("Teraz.\n");
        tmp = ultimately(tab, e);
        if(!tmp){
            printf("You are cheating!\n");
            return 0;
        }
    }
    for(int i = 0; i < 4; i++)
        printf("[%d]", e[i]);
    printf("\nLiczba ruchów = %d\n", z);

    return 0;
}

