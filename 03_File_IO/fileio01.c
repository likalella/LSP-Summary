// lseek ()
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void){
    // STDIN_FILENO : 0 (standard input)
    if(lseek(STDIN_FILENO, 0, SEEK_SET) == -1)
        fprintf(stderr, "lseek error\n");
    else
        printf("lseek ok\n");

    return 0;
}
