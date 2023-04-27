#include <uname.h>
#include <sys/utsname.h>
#include <stdio.h>


int _uname(int argc, char *argv[]){
    struct utsname uts;
    if (argc > 1){
        fprintf(stderr, "uname: extra operand '%s'\n", argv[1]);
        return 1;
    }

    if (uname(&uts) < 0)
        return 1;
    else {
        printf("Kernel:  %s\n", uts.sysname);
        printf("Release:  %s\n", uts.release);
        printf("Version:  %s\n", uts.version);
        printf("CPU:  %s\n", uts.machine);
    }
    return 0;
}
