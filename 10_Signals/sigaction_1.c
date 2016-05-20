// sigaction()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo){
    printf("ocuur SIGINT SIGNAL\n");
    printf("reset SIGINT to SIG_DFL\n");
    sigaction(SIGINT, &act_old, NULL);
}

int main(void){
    act_new.sa_handler = sigint_handler;
    sigemptyset(&act_new.sa_mask);

    sigaction(SIGINT, &act_new, &act_old);
    while(1){
        printf("process running...\n");
        sleep(1);
    }
}
