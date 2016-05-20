// sigsetjmp()

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>
#include <time.h>
#include <errno.h>

static void usr1_func(int), alarm_func(int);
static sigjmp_buf jmpbuf;
static volatile sig_atomic_t canjump;

void pr_mask(const char *str){
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
        printf("SIGALRM");

    printf("\n");
    errno = errnum;
}

int main(void){
    if(signal(SIGUSR1, usr1_func) == SIG_ERR){
        printf("SIGUSR1 error");
        exit(1);
    }
    if(signal(SIGALRM, alarm_func) == SIG_ERR){
        printf("SIGALRM error");
        exit(1);
    }
    pr_mask("starting main: ");

    if(sigsetjmp(jmpbuf, 1)){
        pr_mask("ending main: ");
        exit(0);
    }
    canjump = 1;

    for(;;)
        pause();
}

static void usr1_func(int signum){
    time_t starttime;

    if(canjump == 0)
        return;

    pr_mask("starting usr1_func: ");
    alarm(3);
    starttime = time(NULL);
    for(;;)
        if(time(NULL) > starttime + 5)
            break;

    pr_mask("ending usr1_func: ");

    canjump = 0;
    siglongjmp(jmpbuf, 1);
}

static void alarm_func(int signum){
    pr_mask("in alarm_func: ");
}
