// kill 함수
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]){
    if(argc < 2)
        fprintf(stderr, "usage: ./a.out [Process ID]\n");
    else
        kill(atoi(argv[1]), SIGKILL);

    return 0;
}
