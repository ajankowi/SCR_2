#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void sigalrm_hand(int syg){
    printf("sygnal alrm - program konczy dzialanie\n");
exit(1);
}

void sigusr1_hand(int syg){
    printf("sygnal usr1\n");
}

void sigusr2_hand(int sig){
    for(int i = 0; i < 1000; i++)
    printf("sygnal usr2 i = 1000\n");
    
}
void sigterm_hand(int syg){
    //printf("sygnal term \n");
}

int main(){
    struct timespec t;
    int i = 1;
    t.tv_sec = 0;
    t.tv_nsec = 100;

    signal(SIGALRM,sigalrm_hand);
    signal(SIGTERM,sigterm_hand);
    signal(SIGUSR1,sigusr1_hand);
    signal(SIGUSR2,sigusr2_hand);
    
    
    while(1){
        nanosleep(&t,0);
        i++;
    }
    return 0;
}
