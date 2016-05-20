// sigpending()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void){
    sigset_t sigset;
    sigset_t pendingset;
    int ndx = 0;

    // Blocked all Siganl
    sigfillset(&sigset);
    sigprocmask(SIG_SETMASK, &sigset, NULL);

    while(1){
        printf("count: %d\n", ndx++);
        sleep(1); 
        if(0 == sigpending(&pendingset)){
            if(sigismember(&pendingset, SIGINT)){
                printf("Waiting, SIGINT is blocked, terminate infinite loop.\n");
                break;
            }
        }
    }
    
    exit(0);
}
