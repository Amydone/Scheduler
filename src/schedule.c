#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int ScheduleExist(void) {

DIR *dir;
FILE *fp;

struct dirent *dirinfo;

    if(!dir = opendir("./"))
    {
        printf("Error of open dir directory\n");

        return 1;

    }
    else

        if(!dirinfo = readdir(dir))
        {

            return 1;

        }
        else
            return 0;


}

void ScheduleShow(void) {


}

void ScheduleNone(void) {


}
