//puase(), alarm()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void myalarm(){
    printf("alarm...!!!\n");
}

int main(){
    printf("Alarm Setting\n");
    signal(SIGALRM, myalarm);
    alarm(2);
    while(1){
        printf("done\n");
        pause();
        alarm(2);
    }
}
