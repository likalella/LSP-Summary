// signal 함수 필수예제
#include <stdio.h>
#include <signal.h>

void (*old_fun)(int);

void sigint_handler(int signo){
    printf("SIGINT SIGNAL 발생\n");
    printf("SIGINT를 SIG_DFL로 재설정 함.\n");
    signal(SIGINT, old_fun);    // or signal(SIGINT, SIG_DFL);
}

int main(void){
    old_fun = signal(SIGINT, sigint_handler);
    while(1){
        printf("process running....\n");
        sleep(1);
    }
}
