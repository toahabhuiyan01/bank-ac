#ifndef TIME__H
#define TIME__H
#include "ah.h"

class time_
{
    public:
        time_t t=time(NULL);
        struct tm *p = localtime(&t);
};

#endif // TIME__H
