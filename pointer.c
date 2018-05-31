#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
void customFunction(const char *str) {
    printf("Función personalizada: %s\n", str);
}
int main(int argc, char *argv[]) {
    static char buff[1];
    static void (*functPtr)(const char *str);
    functPtr = &customFunction;
    strcpy(buff, argv[1]);
    functPtr(argv[2]);
    return 0;
}