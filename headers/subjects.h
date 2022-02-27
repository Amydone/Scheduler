#ifndef SUBJECTS_H
#define SUBJECTS_H

#define MAX_SUBJ 20
#define EXTENSION ".sch"
#define EXT_SIZE 4

struct subject {
    char s_name *[MAX_SUBJ];
    struct subject *next;
};

int SubjectsExist(void);
void SubjectsShow(void);
void SubjectsNone(void);

#endif
