#include <stdio.h>
#include <stdlib.h>
 
int palindrom(const char *s)
{
    const char *end = s;
    while (*end) end++; // ищем конец строки (нулевой байт)
    end--; // отступаем назад на один байт (от нулевого)
 
    for (; s < end; s++, end--) {
        if (*s != *end)
            return 0;
    }
 
    return 1;
}
 
int main()
{
    char *s = malloc(100);
 
    if (!s) {
        puts("Не удалось выделить 100 байт? Серьёзно?");
        return 1;
    }
 
    printf("Enter string: ");
    gets(s);
 
    if (palindrom(s))
        puts("Pal");
    else
        puts("Not pal");
 
    free(s);
}
