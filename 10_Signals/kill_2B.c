//kill()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        fprintf(stderr, "Usage: ./a.out [pid]\n"); 
    }else{
        kill(atoi(argv[1]), SIGKILL); 
    }
}
