// alarm 함수
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int counter = 0;

void sigint_handler(int signo){
    printf("alarm %d\n", counter++);
    alarm(1);
}

int main(void){
    signal(SIGALRM, sigint_handler);
    alarm(1);
    while(1);
}
