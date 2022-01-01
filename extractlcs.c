#include "extractlcs.h"
#include <fcntl.h> /* file control options */
#include <stdio.h>
#include <unistd.h> /* for testing purposes */
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define BUFFER_SIZE 256  //does this need to be adjusted?
#define MAX 50010 //honestly though what is this??

int get_size (int fd) {
    lseek(fd, 0L, SEEK_END);
    int sz = lseek (fd, 0, SEEK_CUR);
    lseek(fd, 0L, SEEK_SET);
    //printf("\nFilesize = %d", sz);
    return sz;
}

void write_to_file (char* fn, char* content) {
    int fd;
    fd = creat(fn, 0664);
    if (fd == 1) { /*why 1? */
        perror("Error: ");
    } else {
        ssize_t nr;
        nr = write(fd, content, strlen(content));
        if (nr == -1) { perror("Error: "); }
        else {
            //printf("\nWritten successfully");}
        }
        close(fd); /* I think this goes here*/
    }
}

/**
 * Reads
 * yeah it does read
 * @param path
 * @return
 */
char* read_from_file (char *path) {
    int my_fd = 0;
    my_fd = open(path, O_RDONLY); /* being a syscall, open has a different default path than fopen */
    if (my_fd < 0) {
        perror(path);
        exit(1); /* check this */
    } else {
        //printf("File has been opened! Great news, innit?\n");
        int size = get_size(my_fd);
        char* buf = malloc((size+1)*sizeof(char)); /* TODO needs a free()*/
        read(my_fd, buf, size);
        //printf("\nReading happened successfully");
        buf[size] = '\0';
        printf("%s", buf);
        return buf;
    }
}



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

int get_array_length(){return 0;} /* maybe it needs implementation, maybe it doesn't */


/**
 * Simple function that does what the math expression 'min(a, b)' does
 * @param a sequence a
 * @param b sequence b
 * @return the length of the shortest sequence of chars.
 */
 int get_minsize (char *a, char *b) {
     int sizea = strlen(a); //TODO do this elsewhere lol
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
 * //TODO update
 * @param seq a sequence of characters
 * @return
 */
 int* populate_matrix (int** adj, int rows, char* seq) {          //lowercase ascii = 97~122
    int* occurrences = malloc(rows*sizeof(int)); //check initialization
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
 * NOTES: len(sequence_a) > len(sequence_b). TODO perhaps its the contrary?
 *
 * @param sequence_a the sequence A to compare.
 * @param sequence_b the sequence B to compare.
 *
 * @return lcs_size the size of the LCS
 * */

int compute_lcs (char *sequence_a, char *sequence_b){ //where len(b) < len(a) (? apparently it's irrelevant)
    printf("Sequence B: %s", sequence_b);
    int a_size = strlen(sequence_a), b_size = strlen(sequence_b);

    int** adj = malloc(BUFFER_SIZE*sizeof(int*));             // uppercase ascii = 65~90

    /* this I believe to be ADJ as in ADJ-acency matrix */
    int* occurrences = populate_matrix(adj, BUFFER_SIZE, sequence_b);

    int i, j, lcs_size = 0;
    int ar[get_minsize(sequence_a, sequence_b)];

    ar[lcs_size++] = -1;
    /* this is the infamous rev */
    for (i = 0; i < a_size; i++) {
        for (j = occurrences[sequence_a[i]] - 1; j >= 0; j--) {
            int x = adj[sequence_a[i]][j];

            if (x > ar[lcs_size - 1]) {
                ar[lcs_size++] = x;
            }
            else {      /*TODO review pointer arithmetics */
                ar[get_lower_bound(ar, lcs_size, x)] = x;
            }
        }
    }
/*    for(i = 0; i < BUFFER_SIZE; i++){
        assert(sizeof(adj[0])!=0);
        int arrlength = sizeof(adj[i])/sizeof(adj[0]);

        for (j=0; j < arrlength; j++)
        {
            printf("row %d, col %d: %d ", i, j, adj[i][j]);
        }
        printf("\n");
    }*/
/*    *//* this is useless lol *//*
    for (i = 1 ; i < lcs_size; i++) {
        printf("%c ", sequence_b[ar[i]]);
    }*/

    for(i = 1 ; i < lcs_size; i++) {
        printf(" > %c :", sequence_b[ar[i]]);
    }
    return lcs_size - 1;
}
