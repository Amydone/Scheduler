#ifndef SUBJECTS_H
#define SUBJECTS_H

#define SUBJ_NAME_LEN 30
#define EXTENSION ".sch"
#define EXT_SIZE 5
#define MAX_SUBJECTS 20

/*  may will be better to use linked list or smt like that
 *
 *  struct subject {
 *      char s_name[30];
 *      struct subject *next;
 *  }
 */

struct subject {
    char *s_name[SUBJ_NAME_LEN];
};

struct subject* SubjectsExist(void);
void SubjectsShow(struct subject *p);
void SubjectsNone(void);
void SubjectsOverflow(void);
struct subject* SubjectsFree(struct subject *p);
char *GetFileExtension(char *fname, size_t len);

#endif
