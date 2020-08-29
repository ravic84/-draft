#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    typedef char TWord[30];
    static const char CFileName[] = "input.txt";
 
    FILE* f = fopen(CFileName, "r");
    TWord buff;
    TWord* array;
    size_t count;
    size_t i;
 
    if (f == NULL)
    {
        perror(CFileName);
        system("read -p 'Press Enter to continue...' var");
        return EXIT_FAILURE;
    }
 
    for (count = 0; fgets(buff, sizeof(TWord), f) != NULL; ++count) { ; }
 
    array = (TWord*) malloc(sizeof(TWord) * count);
 
    rewind(f);
 
    for (i = 0; fgets(array[i], sizeof(TWord), f) != NULL; ++i) { ; }
 
    fclose(f);
 
    for (i = 0; i < count; ++i)
    {
        printf("%s", array[i]);
    }
    printf("\n");
 
    free(array);
 
    system("read -p 'Press Enter to continue...' var");
 
    return EXIT_SUCCESS;
}
