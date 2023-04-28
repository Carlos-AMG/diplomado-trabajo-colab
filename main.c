#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
# include <error.h>

#include "uptime.h"

struct buildcmd {
	const char *namecmd;
    int parameters;
	int (*fncmd)(int, char **);
};

static int uptimecmd(int argc, char **argv)  { return uptime_main(argc, argv); }

/*Enum with the commands*/
enum allcmd{
    UPTIME_CMD,
    TOTAL_CMD
};

/*struct with the commands*/
static const struct buildcmd listcmd[TOTAL_CMD] = {
    {"_uptime"   , 0 , uptimecmd },
};


int main (int argc, char **argv)
{
    char *cmd;
    int idx=1,idx_list,idx_lc,cmd_status;

    cmd = argv[idx];

    /* Check if command is in lowercase */
    for(idx_lc = 1; idx_lc < strlen(cmd); idx_lc++)
    {
        if(islower(cmd[idx_lc]) == 0)
        {
            error(EXIT_FAILURE, 1,"command %s not found.",cmd);
        }
    }

    idx_list = 0;
    /* Check if the command is in the list and has the correct format */
    while(idx_list < TOTAL_CMD)
    {
        if(strcmp(cmd,listcmd[idx_list].namecmd) == 0)
        {
            cmd_status = listcmd[idx_list].fncmd(argc,argv);
            break;
        }
        idx_list ++;
    }
    
    /* Command not found */
    if(idx_list >= TOTAL_CMD){
        error(EXIT_FAILURE, 1,"command %s not found.",cmd);
    }

    return 0;
}
