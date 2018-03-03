// Copyright 2018 Jakub Filistyński
// Match.c

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 101

bool match(char* p, char* m) {
    // p = pattern, m = match
    int l = strlen(p) + 1;
    if ((*m) == (*p) || (*p) == '?') {
        if ((*p) == '\0')
            return true;
		if ((*m) == '\0' && (*p) == '?')
			return false;
        return match(p+1, m+1);
    }
    if ((*p) == '*')
        for(int i = 0; i < l; i++)
            if (match(p+1, m+i) == true)
                return true;
    return false;
}

int main () {
    char p[MAX];
    char m[MAX];
    printf("Enter pattern. (max 100 chars)\n");
    scanf("%s", p);
    printf("Enter match. (max 100 chars)\n");
    scanf("%s", m);
    if (match(p, m) == true)
        printf("Yes.\n");
    else
        printf("No.\n");
    return 0;
}
