#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <error.h>
#include <linux/unistd.h>
#include <linux/kernel.h> 
#include <sys/sysinfo.h>
#include <time.h>
#include "uptime.h"

int uptime_main(int argc UNUSED_PARAM, char **argv UNUSED_PARAM)
{
    unsigned updays, uphours, upminutes, upseconds;
    struct sysinfo info;
    time_t current_secs;
    struct tm *current_time;

    time(&current_secs);
    int s_error = sysinfo(&info);

    if(s_error != 0)
    {
        error(EXIT_FAILURE, 1,"uptime: no system availability");
    }
    else
    {
        current_secs -= info.uptime;
        current_time = localtime(&current_secs);

        printf("%04u-%02u-%02u %02u:%02u:%02u\n",
			current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday,
			current_time->tm_hour, current_time->tm_min, current_time->tm_sec
		);

        updays = (unsigned) info.uptime / (unsigned)(60*60*24);
        printf("%u day%s, ", updays, (updays != 1) ? "s" : "");

        upminutes = (unsigned) info.uptime / (unsigned)60;
        uphours = (upminutes / (unsigned)60) % (unsigned)24;
        upminutes %= 60;
        upseconds = info.uptime - ((updays * ((unsigned)(60*60*24))) + (uphours * ((unsigned)(60*60))) + (upminutes * 60));
        printf("%2u:%02u:%02u\n", uphours, upminutes,upseconds);
    }

    return 0;
}