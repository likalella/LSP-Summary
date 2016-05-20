// sigsuspend()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile sig_atomic_t quitflag;

static void int_func(int signum){
    if(signum == SIGINT)
        printf("\ninterrupt\n");
    else if(signum == SIGQUIT)
        quitflag = 1;
}

int main(void){
    sigset_t new_mask, old_mask, zero_mask;

    if(signal(SIGINT, int_func) == SIG_ERR){
        prnitf("SIGINT error");
        exit(1);
    }
    if(signal(SIGQUIT, int_func) == SIG_ERR){
        printf("SIGQUIT error");
        exit(1);
    }

    sigemptyset(&zero_mask);
    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGQUIT);

    if(sigprocmask(SIG_BLOCK, &new_mask, &old_mask) < 0){
        printf("SIG_BLOCK() error");
        exit(1);
    }

    while(quitflat == 0)
        sigsuspend(&zero_mask);

    quitflag = 0;

    if(sigprocmask(SIG_SETMASK, &old_mask, NULL) < 0){
        printf("SIG_SETMASK() error");
        exit(1);
    }

    exit(0);
}
