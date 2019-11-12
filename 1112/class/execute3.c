#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int child, pid, status;

    pid = fork();
    if( pid == 0) { // 자식 프로세스
        execvp(argv[1], &argv[1]);
        fprintf(stderr, "%s : Run Impossible\n", argv[1]);
    } 
    else { // 부모 프로세스
        child = wait(&status);
        printf("[%d] Child Process %d End\n", getpid(), pid);
        printf("\t End Code %d \n", status >> 8);
    }
}

