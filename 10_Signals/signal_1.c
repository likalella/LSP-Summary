// signal 함수
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void user_func(int);

int main(void){
    if(signal(SIGUSR1, user_func) == SIG_ERR){
        fprintf(stderr, "cannot catch SIGUSR1");
        exit(1);
    }
    if(signal(SIGUSR2, user_func) == SIG_ERR){
        fprintf(stderr, "cannot catch SIGUSR2");
        exit(1);
    }

    for(;;)
        pause();
}

static void user_func(int signum){
    if(signum == SIGUSR1)
        printf("got a SIGUSR1\n");
    else if(signum == SIGUSR2)
        printf("got a SIGUSR2\n");
    else{
        printf("got a signal %d\n", signum);
        exit(1);
    }
}
