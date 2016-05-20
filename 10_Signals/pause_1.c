// pause()
// 간단하지만 불완전한 sleep
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void sig_alrm(int signo){
    
}

unsigned int sleep1(unsigned int nsecs){
    if(signal(SIGALRM, sig_alrm) == SIG_ERR)
        return(nsecs);
    alarm(nsecs);       // start the timer
    pause();            // next caught signal wakes us up
    return(alarm(0));   // turn off timer, return unslept time
}
