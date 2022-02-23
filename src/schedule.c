#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

int SubjectsExist(void) {

DIR *dir;
FILE *fp;

struct dirent *dirinfo;

    if(!(dir = opendir("./")))
    {
        printf("Error of open dir directory\n");

        return 1;

    }
    else

//TODO
        while(dirinfo = readdir(dir))
        {
            if(strncmp(dirinfo->d_name, 
            printf("%s\n", dirinfo->d_name);

            getchar();
            //return 0;

        }
        
            return 1;


}

void SubjectsShow(void) {

    printf("Your subjects:");

}

void SubjectsNone(void) {


}
