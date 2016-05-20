// sigpromask()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void){
    sigset_t sigset;
    int ndx;
    
    sigemptyset(&sigset);
    sigaddset(&sigset, SIGINT);
    sigpromask(SIG_BLOCK, &sigset, NULL);

    // start important task
    for(ndx = 3; 0 < ndx; ndx--){
        printf("count %d\n", ndx);
        sleep(1);
    }
    // stop important task

    printf("Unblocked about Ctrl-C.\n");
    sigpromask(SIG_UNBLOCK, &sigset, NULL);
    printf("If you press Ctrl-C key while count execute, This sentence don't be printed. \n");

    while(1);

    return 0;
}
