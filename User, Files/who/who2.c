//
// Created by ryan on 6/11/18.
//
#include <stdio.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

/* #define SHOWHOST */
void showtime(long);
void show_info(struct utmp *utbufp);

int main() {
    /*
     * utmp is the data structure stored in umpt.h. It stores info about users logged into the machine.
     */
    struct utmp current_record; /* read info into this struct*/
    int utmpfd; /* file descriptor to read from */
    int reclen = sizeof(current_record);

    if ( (utmpfd = open (UTMP_FILE, O_RDONLY)) == -1) { /* if fail to open UTMP_FILE (defined in utmp.h) */
        perror( UTMP_FILE );
        _exit(1);
    }
    while ( read(utmpfd, &current_record, reclen) == reclen ) { /* read size reclen data from utmpfd to current_record */
        show_info(&current_record);
    }
    close(utmpfd);  /* close file descriptor utmpfd */
    return 0;
}

void show_info(struct utmp *utbufp) {
    if (utbufp->ut_type != USER_PROCESS)
        return;
    printf("%-8.8s",utbufp->ut_user);
    printf(" ");
    printf("%-8.8s",utbufp->ut_line);
    printf(" ");
    showtime(utbufp->ut_time);
#ifdef SHOWHOST
    if (utbufp->ut_host[0] != '\0')
        printf(" (%s)",utbufp->ut_host);
#endif
    printf("\n");
}

void showtime( long timeval ){
    char *cp;
    cp = ctime(&timeval);
    printf("%12.12s",cp+4);
}