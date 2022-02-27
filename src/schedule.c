#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "../headers/subjects.h"

int SubjectsExist(void) {

DIR *dir;
FILE *fp;

struct dirent *dirinfo;

char f_ext[EXT_SIZE];
int f_len;


    if(!(dir = opendir("./")))
    {
        printf("Error of open dir directory\n");

        return 1;

    }
    else

        do
        {

            f_len = strlen(dirinfo->d_name);

            int j = EXT_SIZE-1;

            for(int i = f_len; i > 0 || j > 0; i--, j--)
            {
            
                f_ext[j] = dirinfo->d_name[i];

            }

            f_ext[EXT_SIZE] = '\0';

        
        }
        while(dirinfo = readdir(dir));

        struct subject *p_subjects = malloc(sizeof(struct subject)); 
        
        printf("%s\n", f_ext);

        getchar();
        
    return 0;


}

void SubjectsShow(void) {

    struct subject *sub;

    printf("Your subjects:\n%s\n", sub->s_name);

    getchar();

}

void SubjectsNone(void) {

    printf("Subjects are empty\n");

}
