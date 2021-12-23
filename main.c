#include <stdio.h>
#include "extractlcs.h"
#include <assert.h>
#include <stdlib.h>
/* stdlib contains declaration of malloc and free, will implement elsewhere */






int main (int argc, char *argv[]) { /* TODO check of course if the type and # of parameters are correct */
    char *file_a = NULL;
    char *file_b = NULL;
    char *file_out = NULL;
    if(argc != 4) {
        printf("Invalid number of parameters: THREE (3) expected. *TODO HELP* \n"); /* TODO adjust this */
        exit(EXIT_FAILURE);
    }
    else {
        file_a = argv[1]; //TODO elsewhere, check if the file exists
        file_b = argv[2]; // might need a malloc for the params
        file_out = argv[3];

    }


    char* file1 = read_from_file(file_a); /* TODO read from terminal */
    char* file2 = read_from_file(file_b);

    free(file1);
    free(file2); /* v important */
    write_to_file(file_out, "TEST");
    printf("\nHello world!");
    return 0;
}
