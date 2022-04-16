#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>


int main(){
    struct timespec t;
    int i = 1;
    t.tv_sec = 0;
    t.tv_nsec = 100;



    

    signal(SIGALRM,SIG_IGN);
    signal(SIGTERM,SIG_IGN);
    signal(SIGUSR1,SIG_IGN);
    signal(SIGUSR2,SIG_IGN);
    
    
    while(1){
        i++;
    }
    
   
}
