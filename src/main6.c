#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "locale.h"
#define N 256
int main() {
    setlocale(LC_ALL, "Russian");
    char str[N];
    int i, f;
    i = 0;
    while ((str[i] = getchar()) != '\n')
        if (str[i] != ' ') i +=1;
    str[i] = '\0';
    printf("%s\n",str);
 
    f = 1;
    for (i=0; i < strlen(str); i++)
        if (str[i] != str[strlen(str)-1-i]) {
            printf("No\n");
            f = 0;
            break;
        }
    if (f == 1) printf("Yes\n");
}