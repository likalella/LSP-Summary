// kill 함수
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    do{
        printf("\n[process running...]");
        sleep(5);
    }while(1);

    return 0;
}
