// raise 함수
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sigint_handler1(int signo){
    printf("SIGINT SIGNAL occur\n");
}

void sigint_handler2(int signo){
    printf("SIGUSR1 SIGNAL occur\n");
}

int main(void){
    signal(SIGINT, sigint_handler1);
    signal(SIGUSR1, sigint_handler2);

    raise(SIGINT);
    raise(SIGUSR1);

    printf("main return\n");

    return 0;
}
