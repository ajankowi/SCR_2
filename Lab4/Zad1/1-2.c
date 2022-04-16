#include <stdio.h>
#include <time.h>

int main(){
    

    struct timespec t;
    t.tv_sec = 0;
    t.tv_nsec = 100;
    
    int i = 0;

    while(1){
        ++i;
        nanosleep(&t,0);
    }

    return 0;
}
