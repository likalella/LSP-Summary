//tcgetpgrop()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <signal.h>
#include <termios.h>

#define STDIN_NUBER 0

static void sig_hup(int signum){
    printf("SIG_HUP received, pid = %d\n", getpid());
}

static void print_ids(char *name){
    printf("[%s] : pid = %d, ppid = %d, pgrp = %d, tpgrp = %d\n", name, getpid(), getppid(), getpgrp(), tcgetpgrp(STDIN_NUMBER));
    fflush(stdout);
}

int main(void){
    char c;
    pid_t pid;

    print_ids("parent");
    if((pid = fork()) < 0){
        printf("fork failed\n");
        exit(1);
    }else if(pid > 0){
        sleep(3);
        exit(0);
    }else{
        print_ids("child");
        signal(SIGHUP, sig_hup);
        kill(getpid(), SIGTSTP);
        print_ids("child");
        if(read(STDIN_NUMBER, &c, 1) != 1)
            printf("read failed, errno = %d\n", errno);
        exit(0);
    }
}
