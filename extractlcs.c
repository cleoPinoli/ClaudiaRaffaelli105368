#include "extractlcs.h"
#include <fcntl.h> /* file control options */
#include <stdio.h>

void my_fread () {
    int my_fd;
    my_fd = fopen("test.txt", O_RDONLY);
    if (my_fd < 0) {
        perror("Error: ");
    } else {
        printf("File has been opened! Great news, innit?");
    }
}