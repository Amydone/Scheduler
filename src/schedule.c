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
char path[] = "./";
char *f_ext = NULL;
int i = 0;
int file_count = 0;

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

        if((f_len = strlen(fname)) < SUBJ_NAME_LEN)
        {
            if((f_ext = GetFileExtension(fname, f_len)) != NULL)
            {
                if(!strcmp(f_ext, EXTENSION))
                {
                    p_subjects->s_name[i] = malloc(SUBJ_NAME_LEN * sizeof(char));

                    strcpy(p_subjects->s_name[i], dirinfo->d_name);

                    file_count++;

                    i++;

                    if(file_count != MAX_SUBJECTS)
                        continue;
                    else
                        SubjectsOverflow();
                        break;

               }
        
            }

        }

    }

    if(i)
    {
        p_subjects->s_name[i] = malloc(SUBJ_NAME_LEN * sizeof(char));

        p_subjects->s_name[i] = NULL;

        return p_subjects;
    
    }
    else
    {
 
        free(p_subjects);

        p_subjects = NULL;

        return p_subjects;
    }

}

void SubjectsShow(struct subject *p) {

    printf("Your subjects:\n");

    for(int i = 0; (struct subject*)p->s_name[i] != NULL; i++)
    {
        printf("[%d]--- %s\n", i+1, p->s_name[i]);

    }

}

void SubjectsNone(void) {

    printf("Subjects are empty\n");

}

void SubjectsOverflow(void) {

    printf("Reached maximum amount of subjects %d\n", MAX_SUBJECTS);

}

struct subject* SubjectsFree(struct subject *p) {

    for(int i = 0; (struct subject*)p->s_name[i] != NULL; i++)
    {
        free(p->s_name[i]);

        p->s_name[i] = NULL;

    }

    free(p);

    p = NULL;

    return p;
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
