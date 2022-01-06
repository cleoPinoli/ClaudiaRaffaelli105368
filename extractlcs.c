#include "extractlcs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256  /* As the standard ASCII size (256) */
#define MAX 50010




/**
 * returns the first element of a given array whose value is lower than a certain value.
 * @param arr the given array.
 * @param end the 'limit' of the array or sub-array, being this a recursive solution.
 * @param X our certain value
 * @return the pointer to the element which is the lower bound
 */
int get_lower_bound(int* arr, int end, int x) {
    for (int i = 0; i < end; i++) {
        if (arr[i] >= x) {
            return i;
        }
    }
    return end;
}

/**
 * Simple function that does what the math expression 'min(a, b)' does
 * @param a sequence a
 * @param b sequence b
 * @return the length of the shortest sequence of chars.
 */
 int get_minsize (char *a, char *b) {
     int sizea = strlen(a);
     int sizeb = strlen(b);

     if (sizea < sizeb) {
         return sizea;
     } else {
         return sizeb;
     }
 }

/**
 * TODO describe the choice of using such matrix instead of other ds's
 * Contemplating the worst case scenario, this matrix has size rows, which is the size of sequence_b.
 *
 * @param rows = size_b. The number of rows the matrix is going to have.
 * Note: it's not going to be necessarily fully populated (better yet, it most likely won't!).
 * @param seq a sequence of characters
 * @return
 */
 int* populate_matrix (int** adj, int rows, char* seq) {
    int* occurrences = malloc(rows*sizeof(int));
    memset(occurrences, 0, rows*sizeof(int));
    for (int i=0; i<rows; i++) {
        //printf ("Value at index %d : %d ", i, occurrences[i]);
    }
    printf(" %d\n", occurrences[0]);
    for (int i=0; i < strlen(seq); i++) {
                occurrences[seq[i]]++;
    }
    for (int i=0; i<rows; i++) {
       // printf ("\nValue at index %d : %d ", i, occurrences[i]);
    }

    for (int n=0; n<rows; n++) {
        adj[n] = malloc(sizeof(int)*occurrences[n]);
    }
    for (int i=0;i< strlen(seq); i++) {
       // printf("%d\t", adj[seq[i]][0]);
    }

    int* it_arrays = malloc(sizeof(int)*rows);
    memset(it_arrays, 0, rows*sizeof(int));
    for (int j = 0; j < strlen(seq); j++) {
        adj[seq[j]][it_arrays[seq[j]]] = j;
        it_arrays[seq[j]]++;
    }
    free(it_arrays);

    return occurrences;
 }

/**
 * computes the LCS using the Hunt-Szymanski algorithm.
 * TODO add notation and look like a smartass lol
 * @param sequence_a the sequence A to compare.
 * @param sequence_b the sequence B to compare.
 *
 * @return
 * */

LCS_params compute_lcs (char *sequence_a, char *sequence_b) {
    printf("Sequence B: %s", sequence_b);
    int a_size = strlen(sequence_a); /* A/N I had a variable b_size declared here as strlen(sequence_b) but it was never used eventually */

    int **adj = malloc(BUFFER_SIZE * sizeof(int *));             // uppercase ascii = 65~90

    /* this I believe to be ADJ as in ADJ-acency matrix */
    int *occurrences = populate_matrix(adj, BUFFER_SIZE, sequence_b);

    int i, j, lcs_size = 0;
    int ar[get_minsize(sequence_a, sequence_b)];

    ar[lcs_size++] = -1;
    /* this is the infamous rev */
    for (i = 0; i < a_size; i++) {
        for (j = occurrences[sequence_a[i]] - 1; j >= 0; j--) {
            int x = adj[sequence_a[i]][j];

            if (x > ar[lcs_size - 1]) {
                ar[lcs_size++] = x;
            } else {
                ar[get_lower_bound(ar, lcs_size, x)] = x;
            }
        }
    }

    printf("The computed LCS is as follows: \n");

    char output[lcs_size];
    for(i = 1 ; i < lcs_size; i++) {
        printf(" %c ;", sequence_b[ar[i]]);
        output[i-1] = sequence_b[ar[i]];
    }


    /*for(int y = 1 ; y < lcs_size; y++) {
        output[y] = sequence_b[ar[y]];
    } */
    printf(" This is happening in lcs file: %s \n\n\n", output);
    LCS_params result = {lcs_size-1, output};
    return result;
}


