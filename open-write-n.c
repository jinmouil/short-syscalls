#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <stdlib.h>
#include <limits.h>

extern int errno;

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Error: need path to be the first argument and number of bytes to write as the second\n");
        return 1;
    }

    int fd = open(argv[1], O_WRONLY);
    if(fd < 0) {
        printf("Error: open failed %d\n", fd);
        printf("Error: %s (errno=%d)\n", strerror(errno), errno);
        return 1;
    }

    long int bytesToWrite = strtol(argv[2], NULL, 10);
    if(bytesToWrite < 0 || bytesToWrite > INT_MAX) {
        printf("Error: invalid bytes to write %ld\n", bytesToWrite);
        return 1;
    }

    char * buf = malloc(bytesToWrite+1);

    // Write whatever is in the memory, don't care the content.
    int ret;
    if((ret = write(fd, buf, bytesToWrite)) < 0) {
        printf("Error: write failed %d\n", ret);
        printf("Error: %s (errno=%d)\n", strerror(errno), errno);
        return 1;
    }

    free(buf);

    return 0;
}
