#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef void (*ErrFunc)(unsigned long);

void fatalError(unsigned long err) {
    printf("Error fatal! - err = %d\n", err);
    //Esto es una mala práctica
    exit(-1);
}

void noFatalError(unsigned long err){
    printf("Algo está mal pero se puede solucionar - err = %d\n", err);
}

void printMessage(char* file, unsigned long err) {
    ErrFunc fErrFunc;
    char buf[512];
    if(err == 5) {
        //acceso denegado
        fErrFunc = fatalError;
    } else {
        fErrFunc = noFatalError;
    }

    snprintf(buf, sizeof(buf)-1, "No se puede encontrar %s", file);

    //mostrar lo que hay en el bufer
    printf("%s", buf);
    //just in case your compiler changes things on you
    printf("\nDirección de fErrFunc is %p\n", &fErrFunc);

    //Solución!
    fprintf(stdout, "%s", buf);

    printf("\nLlamando ErrFunc %p\n", fErrFunc);
    fErrFunc(err);
}

void goalFunction(void) {
    printf("Hemos sido hackeados!\n");
}

int main(int argc, char* argv[]) {
    FILE* pFile;

    printf("Dirección de goalFunction is %p\n", goalFunction);

    //Abrir el archivo existente
    pFile = fopen(argv[1], "r");

    if(pFile == NULL) {
        printMessage(argv[1], errno);
    } else {
        printf("Abierto %s\n", argv[1]);
        fclose(pFile);
    }
    return 0;
}