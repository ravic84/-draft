#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "locale.h"

#define FILENAME "input.txt"
#define SIZE 256

int main () {

//setlocale(LC_ALL, "Russian");
int k, j, y, i=0, tmp=1;
//char str[]="A roza upala na lapu Azora";
char str[SIZE] = { 0 }, *text = NULL;
    FILE* file = fopen(FILENAME, "rt");
    size_t g = 0; 
 
    text = (char*)calloc(1, sizeof(char));
    while (fgets(str, SIZE, file) != NULL)
    {
        if (g % 2 == 0) 
            text = (char*)realloc(text, SIZE * (g + 2));
        strcat(text, str);
        ++i; 
    }
for(int y = 0; y < SIZE; y = y + 1)
    printf("%c",str[y]);
while (str[i] != 0){
i++;
}
//удаляем пробелы и переводим в один регистр.
for (k = 0; k < i; k++) {
if (str[k] == 32) {
for (j = k; j < i; j++){
str[j] = str[j+1];
}
i--; /*отнимаем от длинны строки каждый пробел т.к. мы его удалили*/
}
if (((str[k] > 64)&&(str[k] < 91))||((str[k] > 191)&&(str[k] < 223))) {
str[k]+=32;
}

}
///////////////////////////////////////
//сравниваем первый и последний символ.
for (k = 0, j = i-1; k < j; k++, j--) {
if (str[k] == str[j]) {
tmp+=2;
}
}
printf("Строка палиндром?\n");
//printf("%s", text);

if (tmp == i) {
printf ("-YES\n");
} else printf ("-NO\n");
for(int i = 0; i < 256; i = i + 1)
    printf("%c",str[i]);
//fclose(file); 
//free(text);  
return (0);
}
