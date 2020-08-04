#include <stdio.h>
#include <stdlib.h>

int main() {
    typedef struct time
    {
        int hour;
        int min;
        int sec;
    }time;
    
    long int toSeconds(time *t); 
    time *fromSec(long int s); 

    time *readTime();
    void showTime(time *t);
    time *addSec(time *t, long int sec);
    time *decSec(time *t, long int sec);
    time *timeDiff(time *t1, time *t2);

    return 0;
}   