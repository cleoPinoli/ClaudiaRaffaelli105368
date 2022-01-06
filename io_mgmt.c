#include <fcntl.h> /* file control options */
#include <unistd.h> /* for testing purposes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "io_mgmt.h"

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
        close(my_fd);
        return buf;
    }
}
