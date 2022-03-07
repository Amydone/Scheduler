#ifndef SUBJECTS_H
#define SUBJECTS_H

#define SUBJ_LENGTH 30
#define EXTENSION ".sch"
#define EXT_SIZE 5
#define MAX_SUBJECTS 20

struct subject {
    char *s_name[MAX_SUBJECTS];
};

struct subject* SubjectsExist(void);
void SubjectsShow(struct subject *p);
void SubjectsNone(void);
char *GetFileExtension(char *fname, size_t len);

#endif
