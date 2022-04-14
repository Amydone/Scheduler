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
int file_count = 0;

struct subject *p_subjects;

    if(!(dir = opendir(path)))
    {
        fprintf(stderr, "Error while open directory\n");

        return 0;

    }
    else
    
    p_subjects = malloc(sizeof(struct subject));
   
    while(dirinfo = readdir(dir))
    {
        strcpy(fname, dirinfo->d_name);

        if((f_len = strlen(fname)) < SUBJNAME_CHAR_SIZE)
        {
            if((f_ext = GetFileExtension(fname, f_len)))
            {
                if(!strcmp(f_ext, EXTENSION))
                {
                    p_subjects->s_name[file_count] = malloc(SUBJNAME_CHAR_SIZE * sizeof(char));

                    strcpy(p_subjects->s_name[file_count], dirinfo->d_name);

                    file_count++;

                    if(file_count != MAX_SUBJECTS)
                        continue;
                    else
                        SubjectsOverflow();
                        break;

               }
        
            }

        }

    }

    if(file_count)
    {
        p_subjects->s_name[file_count] = malloc(SUBJNAME_CHAR_SIZE * sizeof(char));

        p_subjects->s_name[file_count] = NULL;

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

char *extension = malloc(EXTENSION_INT_SIZE+1 * sizeof(char));

int j = EXTENSION_INT_SIZE;

    for(int i = len; i > 0; i--)
    {
        extension[j] = fname[i];
        j--;
    }

    *(extension + EXTENSION_INT_SIZE+1) = '\0';

    return extension;

}

struct subject* SubjectsCreate(struct subject *p) {


    return p;

}
