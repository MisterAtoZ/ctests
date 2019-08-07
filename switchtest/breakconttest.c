#include <stdio.h>
#include <time.h>

int main(void) {
        struct timespec tim;
        tim.tv_sec = 0;
        tim.tv_nsec = 50000000L;
        int i = 0;
        while(i<20) {
                i++;
                if(i==13) {
                    //break; //Stops if i==13
                    continue; /*continues with the next iteration. i+.+. NEEDS to be before the statement now to avoid infinite loop*/
                }
                printf("%d\n", i);
                nanosleep(&tim, NULL);
        }
        return 0;
}
