#include "extractlcs.h"
#include <fcntl.h> /* file control options */
#include <stdio.h>
#include <unistd.h> /* for testing purposes */
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 256  //vediamo poi se aggiustare questa
#define MAX 50010 //COS'E' MAX E CHE CE NE FACCIAMO AAAA
int get_size (int fd) {
    lseek(fd, 0L, SEEK_END);
    int sz = lseek (fd, 0, SEEK_CUR);
    lseek(fd, 0L, SEEK_SET);
    printf("\nFilesize = %d", sz);
    return sz;
}

void write_to_file (char* fn, char* content) {
    int fd;
    fd = creat(fn, 0664);
    if (fd==1) { /*why 1? */
        perror( "Error: ");
    } else {
        ssize_t nr;
        nr = write(fd, content, strlen(content));
        if (nr==-1) { perror("Error: ");} else {
        printf("Written successfully");}
    }
    close(fd); /* i think this goes here*/
}


/**
 * Reads
 * @param path
 * @return
 */
char* read_from_file (char *path) {
    int my_fd;
    my_fd = open(path, O_RDONLY); /* being a syscall, open has a different default path than fopen */
    if (my_fd < 0) {
        perror(path);
        exit(1); /* check this */
    } else {
        printf("File has been opened! Great news, innit?\n");
        int size = get_size(my_fd);
        char* buf = malloc(size*sizeof(char)); /* TODO needs a free()*/
        read(my_fd, buf, size);
        printf("\nReading happened successfully");
        return buf;
    }
}



/**
 * returns the first element of a given array whose value is lower than a certain value.
 * @param arr the given array.
 * @param low, high the edges of the array or sub-array, being this a recursive solution.
 * @param X our certain value
 * @return the
 */int* get_lower_bound(int *begin, int *end, int X) {
    // Base Case
    /*if (begin > end) {
        return begin;
    }*/
    /* Find the middle index */
    //int mid = begin + (end - begin) / 2;

    /* If arr[mid] is >= X, search in left sub-array */
    /*if (arr[mid] >= X) {
        return get_lower_bound(arr, begin,mid - 1, X);
    }*/

    /* If arr[mid] is < X, search in right sub-array */
    //return get_lower_bound(arr, mid + 1,end, X);
    return 0;
}

int compute_array_length( char *arr) {
     return 1;
 }
/**
 * computes the LCS using the Hunt-Szymanski algorithm.
 *
 * @param sequence_a the sequence A to compare.
 * @param sequence_b the sequence B to compare.
 *
 * @return lcs_size the size of the LCS
 * */
int compute_lcs (char *sequence_a, char *sequence_b){
    int adj[BUFFER_SIZE][BUFFER_SIZE]; // TODO resize with malloc and everything
    int i, j, l = 0;
    int a_size = strlen(sequence_a), b_size = strlen(sequence_b);
    int ar[MAX];

    /*for (i = 0; i < b_size; i++) {
        adj[sequence_b[b_size-i]];
        } TODO fill the matrix 256xb_size*/

        ar[l++] = -1;
        for (i = 0; i < a_size; i++){
            for (j = compute_array_length(adj[sequence_a[i]]) - 1; j >= 0; j--) { //TODO this is to be redefined asap
                int x = adj[sequence_a[i]][j]; //why are we giving two indexes to an array which has 1 dimension only?
                if (x > ar[l - 1]) ar[l++] = x;
                else ar[get_lower_bound(ar, ar+l, x) - ar] = x;
            }
        }
        return l - 1;
}
