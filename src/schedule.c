#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "../headers/subjects.h"

struct subject* SubjectsExist(void) {

DIR *dir;
struct dirent *dirinfo;
char fname[256];
size_t f_len;
int f_count = 1;

char path[] = "./";
char *f_ext;
int i = 0;

struct subject *p_subjects;

    if(!(dir = opendir(path)))
    {
        printf("Error of open dir directory\n");

        return 0;

    }
    else

    p_subjects = malloc(sizeof(struct subject));

    while(dirinfo = readdir(dir))
    {

        strcpy(fname, dirinfo->d_name);

        if(f_len = strlen(fname))
        {
            if((f_ext = GetFileExtension(fname, f_len)) != NULL)
            {
                if(!strcmp(f_ext, EXTENSION))
                {

                    p_subjects->s_name[i] = malloc(SUBJ_LENGTH * f_count * sizeof(char*)); 

                    strcpy(p_subjects->s_name[i], dirinfo->d_name);

                    f_count++;

                    i++;

               }
        
            }

        }

    } 
    

    return p_subjects;


}

/* TODO 
 * Unexpected behaviour after calling this function,
 * program just close, may error in streams
 */

void SubjectsShow(struct subject *p) {

    printf("Your subjects:\n");

    for(int i = 0; p != NULL; i++)
    {
        printf("%d %s\n", i, p->s_name[i]);

    }
    
}

void SubjectsNone(void) {

    printf("Subjects are empty\n");

}

char *GetFileExtension(char *fname, size_t len) {

char f_ext[EXT_SIZE];
char *extension;

int j = EXT_SIZE-1;

    for(len; j >= 0; len--, j--)
    {
            
        f_ext[j] = fname[len];

    }

    f_ext[EXT_SIZE] = '\0';

    extension = f_ext;

    return extension;

}
