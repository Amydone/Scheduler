#ifndef SUBJECTS_H
#define SUBJECTS_H

#define SUBJNAME_CHAR_SIZE 30
#define EXTENSION ".sch"
#define EXTENSION_INT_SIZE 4
#define MAX_SUBJECTS 20

#define DATE_CHAR_SIZE 11
#define HOURS_CHAR_SIZE 8

/*  may will be better to use linked list or smt like that
 *
 *  struct subject {
 *      char s_name[30];
 *      struct time;
 *      struct subject *next;
 *  }
 */

struct subject {
    //char *s_name[SUBJNAME_CHAR_SIZE];
    //struct s_time *p_time;
    char s_name[SUBJNAME_CHAR_SIZE];
    struct s_time {
        char date[DATE_CHAR_SIZE];
        short hrs;
        short min;
        short sec;
        //[HOURS_CHAR_SIZE];
    };

    struct subject *next;
};


struct subject *SubjectExist(void);
struct subject *SubjectCreate(struct subject *p);
struct subject *SubjectOpen(void);
struct subject *SubjectEdit(void);
struct subject *SubjectDelete(void);
struct subject *SubjectFree(struct subject *p);


void SubjectsShow(struct subject *p);
void SubjectsNone(void);
void SubjectsOverflow(void);

char *GetFileExtension(char *fname, size_t len);

#endif
