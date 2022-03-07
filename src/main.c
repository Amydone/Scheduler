#include <stdio.h>
#include "../headers/subjects.h"
#include "../headers/login.h"

int main(void) {

struct subject *subjects;

    if(subjects = SubjectsExist())
    {
        SubjectsShow(subjects);
        Entrance();

    }
    else
        SubjectsNone();
        Entrance();


    return 0;

}
