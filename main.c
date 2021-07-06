#include "ADT-imdb/imdbADT.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define CANT_QUERYS 3
#define BUFFER_SIZE 128 

typedef enum {ARGC = 1, INV_FILE} errors;

// Aborta el programa con el valor que recibe
// enviando un mensaje a la salida de error
void errNout(const char * errMsg, int exitCode);

// Cierra los archivos que recibe
void closeFiles(FILE ** files, size_t fileCount);

// Permite el procesamiento de los datos de Imdb
int main(int cantArg, char * args[]) {
    if (cantArg != 2)
        errNout("Cantidad invalida de parametros", ARGC);

    errno = 0;
    FILE * data = fopen(args[1], "r");
    FILE * query1 = fopen("query1.csv", "w+");
    FILE * query2 = fopen("query2.csv", "w+");
    FILE * query3 = fopen("query3.csv", "w+");
    FILE * files[] = {data, query1, query2, query3};
    size_t fileCount = CANT_QUERYS + cantArg - 1;
    if (errno == ENOENT) {
        closeFiles(files, fileCount);
        errNout("Hubo un error al abrir un archivo", INV_FILE);
    }

    // todo usar los archivos

    closeFiles(files, fileCount);
    return 0;
}

void errNout(const char * errMsg, int exitCode) {
    fprintf(stderr, "%s\n", errMsg);
    exit(exitCode);
}

void closeFiles(FILE * files[], size_t fileCount) {
    for(size_t i = 0; i < fileCount; i++)
        if(files[i] != NULL) 
            fclose(files[i]);
    return;
}
