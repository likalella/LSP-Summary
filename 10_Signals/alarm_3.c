// alarm 함수
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <setjmp.h>

#define LINE_MAX 2048

static void alarm_func(int);
static jmp_buf jump_alarm;

int main(void){
    int n;
    char line[LINE_MAX];

    if(signal(SIGALRM, alarm_func) == SIG_ERR){
        fprintf(stderr, "SIGALRM error");
        exit(1);
    }

    if(setjmp(jump_alarm) != 0){
        fprintf(stderr, "read() timeout\n");
        exit(1);
    }

    alarm(5);
    if((n = read(STDIN_FILENO, line, LINE_MAX)) < 0)
        fprintf(stderr, "read() error");
    alarm(0); 

    write(STDOUT_FILENO, line, n);
    exit(0);
}

static void alarm_func(int signum){
    longjmp(jump_alarm, 1);
}
