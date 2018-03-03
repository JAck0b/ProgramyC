#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define D 7


void write(bool tab[D][D][D][D]){
    for(int a = 1; a < D; a++){
        for(int b = 1; b < D; b++){
            for(int c = 1; c < D; c++){
                for(int d = 1; d < D; d++){
                    if(tab[a][b][c][d] == true)
                        printf("[%d][%d][%d][%d]\n", a, b, c, d);
                }
            }
        }
    }
    printf("\n");
}

bool ball(int e[4], int l[4], int black, int white){
    int amount[7] = {0, 0, 0, 0, 0, 0, 0};
    amount[l[0]] += 1;
    amount[l[1]] += 1;
    amount[l[2]] += 1;
    amount[l[3]] += 1;
    int now_black = 0;
    int now_white = 0;
    if(amount[e[0]] > 0){
        amount[e[0]] -= 1;
        now_white++;
    }
    if(amount[e[1]] > 0){
        amount[e[1]] -= 1;
        now_white++;
    }
    if(amount[e[2]] > 0){
        amount[e[2]] -= 1;
        now_white++;
    }
    if(amount[e[3]] > 0){
        amount[e[3]] -= 1;
        now_white++;
    }
    if(e[0] == l[0]){
        now_black++;
        now_white--;
    }
    if(e[1] == l[1]){
        now_black++;
        now_white--;
    }
    if(e[2] == l[2]){
        now_black++;
        now_white--;
    }
    if(e[3] == l[3]){
        now_black++;
        now_white--;
    }
    if((black == now_black) && (white == now_white)){
        return true;
    }
    return false;
}


int check(bool tab[D][D][D][D], int e[4], int black, int white){ //checking how many would be stop
    int count = 0;
    for(int a = 1; a < D; a++){
        for(int b = 1; b < D; b++){
            for(int c = 1; c < D; c++){
                for(int d = 1; d < D; d++){
                    if(tab[a][b][c][d] == true){
                        int l[4];
                        l[0] = a;
                        l[1] = b;
                        l[2] = c;
                        l[3] = d;
                        if(!ball(e, l, black, white))
                            count++;
                    }
                }
            }
        }
    }
    return count;
}

bool lookingfor(int e[4], bool option, bool tab[D][D][D][D], int black, int white){ // I'm looking for code
    if(option == false){
        for(int a = 1; a < D; a++){
            for(int b = 1; b < D; b++){
                for(int c = 1; c < D; c++){
                    for(int d = 1; d < D; d++){
                        if(tab[a][b][c][d] == true){
                            e[0] = a;
                            e[1] = b;
                            e[2] = c;
                            e[3] = d;
                            return true;
                        }
                    }
                }
            }
        }
    }
    else{ //I'm looking for the best potential code
        int tmp;
        int l[4];
        int amount = 0;
        for(int a = 1; a < D; a++){
            for(int b = 1; b < D; b++){
                for(int c = 1; c < D; c++){
                    for(int d = 1; d < D; d++){
                        if(tab[a][b][c][d] == true){
                            l[0] = a;
                            l[1] = b;
                            l[2] = c;
                            l[3] = d;
                            tmp = check(tab, l, black, white);
                            if(tmp > amount){
                                amount = tmp;
                                for(int i = 0; i < 4; i++)
                                    e[i] = l[i];
                            }
                        }
                    }
                }
            }
        }
        //printf("%d ", amount);
        return true;
    }
    return true;
}

void removing(bool tab[D][D][D][D], int e[4], int black, int white){
    for(int a = 1; a < D; a++){
        for(int b = 1; b < D; b++){
            for(int c = 1; c < D; c++){
                for(int d = 1; d < D; d++){
                    if(tab[a][b][c][d] == true){
                        int l[4];
                        l[0] = a;
                        l[1] = b;
                        l[2] = c;
                        l[3] = d;
                        if(!ball(e, l, black, white))
                            tab[a][b][c][d] = false;
                    }
                }
            }
        }
    }
}

void ultimately(bool tab[D][D][D][D], int e[4]){
    int tmp = 0;
    for(int a = 1; a < D; a++){
        for(int b = 1; b < D; b++){
            for(int c = 1; c < D; c++){
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
                        break;
                    }
                }
            }
        }
    }
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
    while(e[0] == 0){
        if(z < 5){
            z++;
            lookingfor(e, true, tab, black, white);
        }
        else{
            lookingfor(e, true, tab, black, white);
        }
        for(int i = 0; i < 4; i++)
            printf("[%d]", e[i]);
        printf("\nblack = ");
        scanf("%d", &black);
        printf("white = ");
        scanf("%d", &white);
        printf("\n");
        removing(tab, e, black, white);

        ultimately(tab, e);
    }

    for(int i = 0; i < 4; i++)
        printf("[%d]", e[i]);

    printf("\n");
    return 0;
}

