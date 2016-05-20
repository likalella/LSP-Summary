// sigsuspend()

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void){
    int i;
    sigset_t sigset;
    sigset_t oldset;

    // blocked SIGINT(Cntl-C)
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGINT);
    sigprocmask(SIG_BLOCK, &sigset, &oldset);

    // restored, waiting siganl
    sigsuspend(&oldset);
    // sigprocmask(SIG_SETMASK, &oldset, NULL);
    // pause();

    return 0;
}
