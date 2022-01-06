#include <fcntl.h> /* file control options */
#include <unistd.h> /* for testing purposes */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "io_mgmt.h"
/**
 * Returns a given file's size in bytes.
 * @param fd the given file's descriptor
 * @return the size (bytes)
 */
int get_size (int fd) {
    lseek(fd, 0L, SEEK_END);
    int sz = lseek (fd, 0, SEEK_CUR);
    lseek(fd, 0L, SEEK_SET);
    return sz;
}

/**
 * Writes content to file.
 * If not existing, it creates a new one.
 * @param fn the output file name
 * @param content the content to be written
 */
void write_to_file (char* fn, char* content) {
    int fd;
    fd = creat(fn, 0664);
    if (fd == 1) {
        perror("Error: ");
    } else {
        ssize_t nr;
        nr = write(fd, content, strlen(content));
        if (nr == -1) { perror("Error: "); }
        else {
        }
        close(fd);
    }
}

/**
 * Reading function.
 * Note that, under a Windows environment, newline characters are treated differently
 * so, if ran under Windows, this might (if not will) give you trouble.
 * Reading "hello[newline]world[newline]from[newline]Text[newline]One" while in Win env.
 * will result in a received string circa like "helloworldfromTextOnetOne": my guess is
 * that newline characters are counted but not read, so the missing 4 chars will contain the last
 * 4 bytes read ("t-O-n-e").
 *
 * @param path the file path
 * @return the file contents as characters
 */
char* read_from_file (char *path) {
    int my_fd = 0;
    my_fd = open(path, O_RDONLY); /* being a syscall, open has a different default path than fopen */
    if (my_fd < 0) {
        perror(path);
        exit(1);
    } else {
        int size = get_size(my_fd);
        char* buf = malloc((size+1)*sizeof(char));
        read(my_fd, buf, size);
        buf[size] = '\0';
        close(my_fd);
        return buf;
    }
}
