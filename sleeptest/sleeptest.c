#include <stdio.h>
#include <unistd.h>
#include<time.h>
/*
struct timespec {
        time_t tv_sec;  //seconds
        long tv_nsec;   //nanoseconds
};*/

int main(void) {
    struct timespec tim;
    tim.tv_sec = 2;
    tim.tv_nsec = 500000000L;
    
     int i = 0;
     while(i < 20) {
         printf("%d\n", i);
         i++;
         //sleep(1); //wait 1 second. needs #include <unistd.h>
         //usleep(200000); //wait 200000 microseconds. needs #include <unistd.h>
         nanosleep(&tim, NULL); /*wait in nanoseconds. needs #include<time.h> and special struct*/
     }
    return 0;
}
