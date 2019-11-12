#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* 부모 프로세스가 자식 프로세스를 생성하고 끝나기를 기다린다. */
int main() {
    int pid1, pid2, child, status;

    printf("[%d] Parent Process Start \n", getpid());
    
    pid1 = fork();
    if(pid1 == 0) {
        printf("[%d] Child Process[1] Start\n", getpid());
        sleep(1);
        printf("[%d] Child Process[1] End\n", getpid());
        exit(1);
    }

    pid2 = fork();
    if(pid2 == 0) {
        printf("[%d] Child Process[2] Start\n", getpid());
        sleep(2);
        printf("[%d] Child Process[2] End\n", getpid());
        exit(2);
    }

    // 자식 프로세스[1]의 종료를 기다린다.
    child = waitpid(pid1, &status, 0); // pid2도 해볼것
    printf("[%d] Child Process[1] %d End\n", getpid(), child);
    printf("\tEnd Code %d\n", status >> 8);
}

