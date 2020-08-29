#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define FILENAME "input.txt"
#define SIZE 256
 
int main(void) 
{
    char buf[SIZE] = { 0 }, *text = NULL;
    FILE* file = fopen(FILENAME, "rt");
    size_t i = 0; 
 
    text = (char*)calloc(1, sizeof(char));
 
    while (fgets(buf, SIZE, file) != NULL)
    {
        if (i % 2 == 0) 
            text = (char*)realloc(text, SIZE * (i + 2));
        strcat(text, buf);
        ++i; 
    }
 
    printf("%s", text);
    
    fclose(file); 
    free(text);  
    return 0;
}

