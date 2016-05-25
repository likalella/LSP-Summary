// sigsuspend()

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

static void int_func(int);
void print_mask(const char *str);

int main(void){
    sigset_t newmask, oldmask, waitmask;

    print_mask("program start: ");

    if(signal(SIGINT, int_func) == SIG_ERR){
        printf("signal(SIGINT) error");
        exit(1);
    }
    sigemptyset(&waitmask);
    sigaddset(&waitmask, SIGUSR1);
    sigemptyset(&newmask);
    sigaddset(&newmask, SIGINT);

    if(sigprocmask(SIG_BLOCK, &newmask, &oldmask) < 0){
        printf("SIG_BLOCK() error");
        exit(1);
    }

    print_mask("in critical region: ");
    if(sigsuspend(&waitmask) != -1){
        printf("sigsuspend() error");
        exit(1);
    }

    print_mask("after return from sigsuspend: ");
    if(sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0){
        printf("SIG_SETMASK() error");
        exit(1);
    }

    print_mask("program exit: ");

    exit(0);
}

static void int_func(int signum){
    print_mask("\nin int_func: ");
}

void print_mask(const char *str){
    sigset_t sigset;
    int errnum;

    errnum = errno;
    if(sigprocmask(0, NULL, &sigset) < 0){
        printf("sigprocmask() error");
        exit(1);
    }

    printf("%s", str);
    if(sigismember(&sigset, SIGINT))
        printf("SIGINT ");
    if(sigismember(&sigset, SIGQUIT))
        printf("SIGQUIT ");
    if(sigismember(&sigset, SIGUSR1))
        printf("SIGUSR1 ");
    if(sigismember(&sigset, SIGALRM))
        printf("SIGALRM ");
    printf("\n");
    errno = errnum;
}
