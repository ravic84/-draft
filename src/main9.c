#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>

const unsigned int MAX_LENGTH = 1 * 1024 * 1024;  // Не выделять больше мегабайта памяти
const unsigned int CHUNK_SIZE = 1024;             // Выделять блоками по килобайту

char* new() {
    unsigned int str_len = CHUNK_SIZE;
    char *str_ptr = malloc(CHUNK_SIZE);           // Выделяем первый килобайтный блок

    if (str_ptr == NULL)
        err(EXIT_FAILURE, "Не удалось выделить память!\n");

    int c;
    unsigned int i;
    for (i = 0, c = EOF; (c = getchar()) != '\n' && c != EOF; i++) {
        str_ptr[i] = c;

        if (i == MAX_LENGTH) {
            free(str_ptr);
            err(EXIT_FAILURE, "Слишком много входных данных!\n");
        }

        if (i == str_len) {                       // Блок заполнен
            str_len = i + CHUNK_SIZE;
            str_ptr = realloc(str_ptr, str_len);  // Расширяем блок на ещё один килобайт
        }
    }
    str_ptr[i] = '\0';                            // Признак конца строки

    return str_ptr;
}

void delete(char* ptr) {
    free(ptr);
}

void swap_chars(char* s) {
    char c;
    unsigned int i;
    for (i = 0; i < strlen(s) - 1; i += 2) {
        c = s[i];
        s[i] = s[i+1];
        s[i + 1] = c;
    }
}

int main(int argc, char* argv[]) {
    char* buf = new();
    printf("%s\n", buf);
    swap_chars(buf);
    printf("%s\n", buf);
    delete(buf);

    return EXIT_SUCCESS;
}
