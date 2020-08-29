#include "stdio.h"
#include "locale.h"

int main () {
setlocale(LC_ALL, "Russian");
int k, j, i=0, tmp=1;
char str[]="A roza upala na lapu Azora";

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
printf("Строка палиндром? - ");
if (tmp == i) {
printf ("YES");
} else printf ("NO");
return (0);
}
