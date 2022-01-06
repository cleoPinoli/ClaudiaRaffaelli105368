#include "extractlcs.h"
#include <stdlib.h>
#include <string.h>

#define ASCII_SET_SIZE 256
#define MAX 50010


/**
 * Returns the first element of a given array whose value is lower than a certain value.
 * @param arr the given array.
 * @param end the 'limit' of the array or sub-array, being this a recursive solution.
 * @param X our certain value
 * @return the index of the element which is the lower bound
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
 * Simple function equivalent to 'min(a, b)'
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
 * Populates the adjacency matrix for the LCS.
 * Note that this matrix is designed similarly to a Python dictionary, a set of sets;
 * each of the nested sets 'n' will contain the position of all the character_n's in a string (hence occurrences).
 * E.g.: the input string 'mama' will result in index 'a' (=97 if I remember correctly) = {1,3} and 'm' = {0,2}.
 * Each of the nested sets is pre-allocated by finding the relative occurrences first then using their sizes to
 * establish how big they must be.
 * This should save us a lot of time and, much more relevantly, space.
 *
 * @param rows The number of rows the matrix is going to have.
 * @param seq a sequence of characters
 * @return mparams a set of adjacency_matrix + the occurrences
 */
 matrix_params* populate_matrix (int rows, char* seq) {

    int **adj = malloc(ASCII_SET_SIZE * sizeof(int *));
    int* occurrences = (int*)malloc(rows*sizeof(int));
    matrix_params* mparams = malloc(sizeof(matrix_params));

    mparams->adj = adj;
    mparams->occurrences = occurrences;

    memset(occurrences, 0, rows*sizeof(int));

    for (int i=0; i < strlen(seq); i++) {
        occurrences[seq[i]]++;
    }

    for (int n=0; n<rows; n++) {
        adj[n] = malloc(sizeof(int)*occurrences[n]);
    }

    int* it_arrays = malloc(sizeof(int)*rows);
    memset(it_arrays, 0, rows*sizeof(int));
    for (int j = 0; j < strlen(seq); j++) {
        adj[seq[j]][it_arrays[seq[j]]] = j;
        it_arrays[seq[j]]++;
    }

    free(it_arrays);
    return mparams;
 }

/**
 * Computes the LCS using the Hunt-Szymanski algorithm.
 * As cited in the Wikipedia page, the H-S algorithm should run in O((n+k)log(n)) where
 * n is the length of the biggest string and k the number of matches between the two.
 * This instead of O(n x m).
 * Understanding the theory behind the Hunt-Szymanski a. was the true trial by fire.
 * @param sequence_a the sequence A to compare.
 * @param sequence_b the sequence B to compare.
 *
 * @return the result of the computation (string + its size)
 * */

LCS_params* compute_lcs (char *sequence_a, char *sequence_b) {

    int a_size = strlen(sequence_a); /* A/N: I had a variable b_size declared here as strlen(sequence_b) but it was never used eventually */

    matrix_params* m_params = populate_matrix(ASCII_SET_SIZE, sequence_b);
    int** adj = m_params->adj;
    int* occurrences = m_params->occurrences;
    int i, j, lcs_size = 0;
    int ar[get_minsize(sequence_a, sequence_b)];

    ar[lcs_size++] = -1;

    /* this is the infamous reverse matrix */
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

    char* output = (char*)malloc(lcs_size*sizeof(char));
    for(i = 1 ; i < lcs_size; i++) {
        output[i-1] = sequence_b[ar[i]];
    }
    LCS_params* result = malloc (sizeof(LCS_params));
    result->lcs_size = lcs_size-1;
    result->lcs_output = output;
    free(m_params->adj);
    free(m_params->occurrences);
    free(m_params);
    return result;
}