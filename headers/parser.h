#ifndef PARSER_H
#define PARSER_H

/* Will design unique format of file
 */

int ParseFileFormat(char *fname);
int SetFileFormat(char *fname);
void *SaveToFile(char *subject_name, struct subject *p); 
void *ReadFile(struct subject *p);

#endif
