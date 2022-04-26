
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "memcached.h"

int daemonize(int nochdir, int noclose)
{
    int fd;

    switch (fork()) {
    case -1:
        return (-1);
    case 0:
        break;
    default:
        _exit(EXIT_SUCCESS);
    }

    if (setsid() == -1)
        return (-1);

    if (nochdir == 0) {
        if(chdir("/") != 0) {
            perror("chdir");
            return (-1);
        }
    }

    if (noclose == 0 && (fd = open("/dev/null", O_RDWR, 0)) != -1) {
        if(dup2(fd, STDIN_FILENO) < 0) {
            perror("dup2 stdin");
            goto err_cleanup;
        }
        if(dup2(fd, STDOUT_FILENO) < 0) {
            perror("dup2 stdout");
            goto err_cleanup;
        }
        if(dup2(fd, STDERR_FILENO) < 0) {
            perror("dup2 stderr");
            goto err_cleanup;
        }

        if(close(fd) < 0) {
            perror("close");
            return (-1);
        }
    }
    return (0);

    err_cleanup:
        close(fd);
        return (-1);
}
