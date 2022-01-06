#include <stdio.h>
#include "extractlcs.h"
#include "io_mgmt.h"
#include <stdlib.h>
#include <string.h>


int main (int argc, char *argv[]) {

    char *file_a = NULL;
    char *file_b = NULL;
    char *file_out = NULL;
    if(argc != 4) { /* checks the number of params */
        printf("Invalid number of parameters, THREE (3) are expected and inserted as follows:\n\n\t1) The first file's path;"
               "\n\t2) The second file's path;\n\t3) The output file;\n\nNote that the file path can be either relative or absolute;\n"
               "As of the output file, if unexisting, will be created anew. \n");
        exit(EXIT_FAILURE);
    }

        file_a = argv[1];
        file_b = argv[2];
        file_out = argv[3];

    char* file1 = read_from_file(file_a);
    char* file2 = read_from_file(file_b);

    LCS_params* lcs = compute_lcs(file1, file2);
    printf("\nLCS computed: %s\n", lcs->lcs_output);
    printf("\nLCS length is: %d. Thank you for flying with Raffaelli Airlines. \n", lcs->lcs_size);

    write_to_file(file_out, lcs->lcs_output);
    free(lcs->lcs_output);
    free(lcs);
    free(file1);
    free(file2); /* v important */
    return 0;
}


