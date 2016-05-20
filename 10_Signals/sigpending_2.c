// sigpending()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void quit_func(int);

int main(void){
    sigset_t new_mask, old_mask, pend_mask;

    if(signal(SIGQUIT, quit_func) == SIG_ERR){
        fprintf(stderr, "cannot catch SIGQUIT\n");
        exit(1);
    }

    sigemptyset(&new_mask);
    sigaddset(&new_mask, SIGQUIT);
    if(sigprocmask(SIG_BLOCK, &new_mask, &old_mask) < 0){
        fprintf(stderr, "SIG_BLOCK() error\n");
        exit(1);
    }

    sleep(3);

    if(sigpending(&pend_mask) < 0){
        fprintf(stderr, "sigpending() error\n");
        exit(1);
    }
    if(sigismember(&pend_mask, SIGQUIT))
        printf("\nSIGQUIT pending\n");

    if(sigprocmask(SIG_SETMASK, &old_mask, NULL) < 0){
        fprintf(stderr, "SIG_SETMASK() error\n");
        exit(1);
    }
    printf("SIGQUIT unblocked\n");

    sleep(3);
    exit(0);
}

static void quit_func(int signum){
    printf("caught SIGQUIT\n");
    if(signal(SIGQUIT, SIG_DFL) == SIG_ERR){
        fprintf(stderr, "cannot reset SIGQUIT\n");
        exit(1);
    }
}
