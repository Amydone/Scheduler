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
 *      struct time;
 *      struct subject *next;
 *  }
 */

struct subject {
    char *s_name[SUBJ_NAME_LEN];
    struct s_time *p_time;
};

struct s_time {
    char data[11];
    char hours[8];
};


struct subject* SubjectsExist(void);
struct subject* SubjectsCreate(struct subject *p);
struct subject* SubjectsFree(struct subject *p);

void SubjectsShow(struct subject *p);
void SubjectsNone(void);
void SubjectsOverflow(void);

char *GetFileExtension(char *fname, size_t len);

#endif
