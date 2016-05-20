// signal 함수

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// SIGINT용 처리기
static void signal_handler(int signo){
    if(signo == SIGINT)
        printf("caught SIGINT\n");
    else if(signo == SIGTERM)
        printf("caught SIGTERM\n");
    else{
        // 여기서 절대 들어오지 않음.
        fprintf(stderr, "unexpected signal\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}

int main(void){
    // signal_handler를 SIGINT 시그널 처리기로 등록
    if(signal(SIGINT, signal_handler) == SIG_ERR){
        fprintf(stderr, "cannot handle SIGINT\n");
        exit(EXIT_FAILURE);
    }
    // signal_handler를 SIGTERM 시그널 처리기로 등록
    if(signal(SIGTERM, signal_handler) == SIG_ERR){
        fprintf(stderr, "cannot handle SIGTERM\n");
        exit(EXIT_FAILURE);
    }
    // SIGPROF 동작을 기본 값으로 설정
    if(signal(SIGPROF, SIG_DFL) == SIG_ERR){
        fprintf(stderr, "cannot reset SIGPROF\n");
        exit(EXIT_FAILURE);
    }
    // SIGHUP 무시
    if(siganl(SIGHUP, SIG_IGN) == SIG_ERR){
        fprintf(stderr, "cannot ignore SIGHUP\n");
        exit(EXIT_FAILURE);
    }

    for(;;)
        pause();
    exit(0);
}
