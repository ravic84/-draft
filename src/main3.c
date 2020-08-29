#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SIZE 256
 
int main(void) 
{
   // char * message = "Hello world! An apple a day keeps the doctor away";
    char buf[SIZE] = { 0 }, *text = NULL;
    FILE* in = fopen("input.txt", "rt");
    size_t i = 0; 
 
    text = (char*)calloc(1, sizeof(char));
 
    while (fgets(buf, SIZE, in) != NULL)
    {
        if (i % 2 == 0) 
            text = (char*)realloc(text, SIZE * (i + 2));
        strcat(text, buf);
        ++i; 
    }
    FILE* out = fopen("output.txt", "w");
		fputs(text, out);
		
    printf("%s", text);
    fclose(in); 
    fclose(out); 
    free(text);  
    return 0;
}

