#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#define BUFFER_SIZE 3

void customFunction(const char *str) {
    printf("Función personalizada: %s\n", str);
}

int main(int argc, char **argv) {
    static char buff[BUFFER_SIZE];
    static void (*functPtr)(const char *str);
    functPtr = &customFunction;
    if(strlen(argv[1]) < BUFFER_SIZE){
        strcpy(buff, argv[1]);
        functPtr(argv[2]);
    } else {
        printf("\nError: El primer parámetro no debe contener más de %d caracteres\n", BUFFER_SIZE-1);
        return 0;
    }
    return 0;
}