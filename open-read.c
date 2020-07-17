#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

int main() {
    int fd = open("../nomount/hello", O_RDONLY);
    if(fd < 0) {
        printf("Error: open failed %d\n", fd);
        return 1;
    }

    char buf[10];
    int ret;
    if((ret = read(fd, buf, 5)) < 0) {
        printf("Error: read failed %d\n", ret);
        return 1;
    }

    printf("Read: %s\n", buf);

    return 0;
}
