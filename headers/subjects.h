#ifndef SUBJECTS_H
#define SUBJECTS_H

#define SUBJ_LENGTH 256
#define EXTENSION ".sch"
#define EXT_SIZE 5
#define MAX_SUBJECTS 20

struct subject {
    char s_name [SUBJ_LENGTH];
};

int SubjectsExist(void);
void SubjectsShow(void);
void SubjectsNone(void);
char *GetFileExtension(char *fname, size_t len);

#endif
