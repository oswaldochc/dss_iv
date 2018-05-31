
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <errno.h>
#define free_s(p) free_safer((void**)&(p))

void improperDeclaration() {
    int* ptr1, ptr2;
    printf("Declaración Incorrecta\n%s\n", "int* ptr1, ptr2;");
}
void improperDeclarationSol() {
    int *ptr1, *ptr2;
    printf("Declaración Correcta\n%s\n", "int *ptr1, *ptr2;");
}

void initialization() {
    int *pi;
    printf("%d\n",*pi);
}

void initializationSol() {
    int *pi = malloc(sizeof(int));
    *pi = 12;
    printf("%d\n",*pi);
}

void initializationNullSol() {
    int *pi = malloc(sizeof(int));
    if(pi == NULL) {
        printf("%s\n", "Error al asignar Memoria");
    } else {
        *pi = 12;
        printf("%d\n",*pi);
    }
}

void accesingMemoryOutsideBound() {
    char firstName[8] = "1234567";
    char middleName[8] = "1234567";
    char lastName[8] = "1234567";

    middleName[-2] = 'X';
    middleName[0] = 'X';
    middleName[10] = 'X';

    printf("%p  %s\n",firstName,firstName);
    printf("%p  %s\n",middleName,middleName);
    printf("%p  %s\n",lastName,lastName);
}

void replace(char buffer[], char replacement) {
    size_t count = 0;
    while(*buffer != '\0') {
        *buffer = replacement;
        buffer++;
    }
}

void replaceSol(char buffer[], char replacement, size_t size) {
    size_t count = 0;
    while(*buffer != '\0' && count++<size) {
        *buffer = replacement;
        buffer++;
    }
}

void arraySize() {
    char name[6];
    strcpy(name,"Oswaldo");
    replace(name,'+');
    printf("%s\n", name);
}

void arraySizeSol() {
    char name[6];
    strcpy(name,"Oswaldo");
    replaceSol(name,'+',sizeof(name));
    printf("%s\n", name);
}

void doubleFreeOne() {
    int *pi = (int*) malloc(sizeof(int));
    *pi = 5;
    free(pi);
    free(pi);
    printf("%s\n", "Memoria Liberada");
}

void doubleFreeTwo() {
    int *p1 = (int*) malloc(sizeof(int));
    int *p2 = p1;
    free(p1);
    free(p2);
}

void doubleFreeOneSol() {
    int *pi = (int*) malloc(sizeof(int));
    *pi = 5;
    printf("Antes: pi %p\n",pi);
    free(pi);
    printf("Despues free: pi %p\n",pi);
    pi = NULL;
    printf("Despues null: pi %p\n",pi);
    free(pi);
    printf("%s\n", "Memoria Liberada");
}

void free_safer(void **pp) {
    if (pp != NULL && *pp != NULL) {
        free(*pp);
        *pp = NULL;
    }
}

void doubleFreeOneSolTwo() {
    int *pi = (int*) malloc(sizeof(int));
    *pi = 5;
    printf("Antes free_s: %p\n",pi);
    free_s(pi);
    printf("Después free_s: %p\n",pi);
    free_s(pi);
    printf("%s\n", "Memoria Liberada utilizando free_s");
}

int addTwoNumbers(int a, int b) {
    return a + b;
}
int safeAdd(int a, int b){
    if ((a > 0 && b > INT_MAX - a) || (a < 0 && b < INT_MIN - a)) {
        fprintf(stderr, "Integer overflow: %d\n", errno);
        fprintf(stderr, "Integer overflow: %s\n", strerror( errno ));
        exit(1);
    }
    return a + b;
}
void addTwoNumbersMain() {
    printf("\n%d + 1 = %d\n", INT_MAX, addTwoNumbers(INT_MAX, 1));
}

void addTwoNumbersMainSol() {
    printf("\n%d + 1 = %d\n", INT_MAX, safeAdd(INT_MAX, 1));
}

void main(int argc, char *argv[]){
    int n, opcion;
    do {
        printf( "\n   1. Subterfugios con punteros", 163 );
        printf( "\n   2. Subterfugios con punteros Solución \n\tControlar el desbordamiento", 163 );
        printf( "\n   3. Declaración Incorrecta del puntero", 163 );
        printf( "\n   4. Declaración Incorrecta Solución", 163 );
        printf( "\n   5. Inicialización del Puntero", 163 );
        printf( "\n   6. Inicialización del Puntero Solución", 163 );
        printf( "\n   7. Inicialización del Puntero Solución Verificar NULL", 163 );
        printf( "\n   8. Acceder a la memoria fuera de los límites de una matriz", 163 );
        printf( "\n   9. Tamaño de una matriz \n\tLa aplicación se detendrá por el buffer \n\toverflow del strcpy", 163 );
        printf( "\n   10. Tamaño de una matriz Solución \n\tLa aplicación se detendrá por el buffer \n\toverflow del strcpy\n\tLa solución se centra en la función de reemplazo", 163 );
        printf( "\n   11. Liberar Memoria 1\n\tResulta una Exepción en tiempo de ejecución", 163 );
        printf( "\n   12. Liberar Memoria 2\n\tResulta una Exepción en tiempo de ejecución", 163 );
        printf( "\n   13. Liberar Memoria 1 Solución", 163 );
        printf( "\n   14. Liberar Memoria 1 Solución \n\tUtiliza la función free personalizada", 163 );
        printf( "\n   15. Overflow de Enteros", 163 );
        printf( "\n   16. Overflow de Enteros Solución \n\t Se controla el overflow con una Excepción", 163 );
        printf( "\n   17. Cadena de Formato \n\tMuestra información de la pila", 163 );
        printf( "\n   18. Cadena de Formato Solución\n\t", 163 );
        printf( "\n   0. Salir.",163);

        do {
            printf( "\n   Introduzca opción (0-18): ", 162 );
            scanf( "%d", &opcion );
        } while ( opcion < 0 || opcion > 18 );

        switch (opcion){
            case 1: system("./pointer.exe Cadena1 Cadena2");break;
            case 2: system("./pointersol.exe Cadena1 Cadena2");break;
            case 3: improperDeclaration();break;
            case 4: improperDeclarationSol();break;
            case 5: initialization();break;
            case 6: initializationSol();break;
            case 7: initializationNullSol();break;
            case 8: accesingMemoryOutsideBound();break;
            case 9: arraySize();break;
            case 10: arraySizeSol();break;
            case 11: doubleFreeOne();break;
            case 12: doubleFreeTwo();break;
            case 13: doubleFreeOneSol();break;
            case 14: doubleFreeOneSolTwo();break;
            case 15: addTwoNumbersMain();break;
            case 16: addTwoNumbersMainSol();break;
            case 17: system("./formatstring.exe %x%x%x%x%x%x%x%x%x%x%x%x%x%x");break;
            case 18: system("./formatstringsol.exe %x%x%x%x%x%x%x%x%x%x%x%x%x%x");break;
            case 0: break;
            default: printf("\n   Opción no válida!\n"); break;
        }
    } while ( opcion != 0 );
    exit(0);
}