#include <stdio.h>
#include "../headers/subjects.h"
#include "../headers/login.h"

int main(void) {

int flag;

    if(!(flag = SubjectsExist()))
    {
        SubjectsShow();
        Entrance();

    }
    else
        SubjectsNone();
        Entrance();


    return 0;

}
