// Signal Set?
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(void){
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);

    switch(sigismember(&set, SIGINT)){
        case 1: printf("SIGINT is Included.\n");
                break;
        case 0: printf("SIGINT is not Included.\n");
                break;
        default: fprintf(stderr, "fail to call sigismember()\n");
    }

    switch(sigismember(&set, SIGSYS)){
        case 1: printf("SIGSYS is Included.\n");
                break;
        case 0: printf("SIGSYS is not Included.\n");
                break;
        default: fprintf(stderr, "fail to call sigismember()\n");
    }

    return 0;
}
