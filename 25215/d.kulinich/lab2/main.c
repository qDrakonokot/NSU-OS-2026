#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <time.h>

extern char *tzname[];

int main(void) {

    time_t now;
    struct tm *sp;

    if (setenv("TZ", "PST8PDT", 1) != 0) {
        perror("Error with setting TZ");
        return 1;
    }

    tzset();

    if (time(&now) == (time_t)-1) {
        perror("Error in time");
        return 1;
    }

    printf("%s", ctime( &now ) );

    sp = localtime(&now);
    printf(
        "%d/%d/%02d %d:%02d %s\n",
        sp->tm_mon + 1, 
        sp->tm_mday,
        sp->tm_year + 1900, 
        sp->tm_hour,
        sp->tm_min, 
        tzname[sp->tm_isdst]
    );

    return 0;
}