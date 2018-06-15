#include <fcntl.h>
#include <utmp.h>
#include <zconf.h>
#include <memory.h>
#include <time.h>

//
// Created by ryan on 6/14/18.
//
int logout_tty(char *line) {
    int fd;
    struct utmp rec;
    int len = sizeof(struct utmp);
    int retval = -1;
    if (( fd = open(UTMP_FILE, O_RDWR))) {
        return -1;
    }

    while ( read(fd, &rec, len) == len ) {
        if ( strncmp(rec.ut_line, line, sizeof(rec.ut_line)) == 0 ) {
            rec.ut_type = DEAD_PROCESS;
            if ( time(&rec.ut_time) != -1 ) {
                if ( lseek(fd, -len, SEEK_CUR) != -1 ) {
                    if ( write(fd, &rec, len) == len ) {
                        retval = 0;
                    }
                }
            }
            break;
        }
    }
    if ( close(fd) == -1 ) {
        retval = -1;
    }
    return retval;
}
