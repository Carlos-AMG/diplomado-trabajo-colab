#include "uname.h"
#include "uptime.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    argc--;
    argv++;

    int status;
    if (strcmp(argv[0], "uptime") == 0) {
        status = uptime_main(argc, argv);
    } else if (strcmp(argv[0], "uname") == 0) {
        status = _uname(argc, argv);
    }
    return status;
}
