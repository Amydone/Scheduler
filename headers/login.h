#ifndef LOGIN_H
#define LOGIN_H

#define VERSION "0.1"

#define INPUTBUFF_INT_SIZE 50

void Welcome(unsigned width);
void ScreenClear(void);

char *GetFormatInput(char *buffer);

int Entrance(void);
int GetScreenSize(void);

#endif
