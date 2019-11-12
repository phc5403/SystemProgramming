#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // 교재에는 없는 wait()사용을 위한 헤더

/* 부모 프로세스가 자식 프로세스를 생성하고 끝나기를 기다린다. */
int main() {
    int pid, child, status;

    printf("[%d] Parent Process Start \n", getpid());

    pid = fork();
    if(pid == 0) {
        printf("[%d] Child Process Start \n", getpid());
        exit(1);
    }

    child = wait(&status); // 자식 프로세스가 끝나기를 기다린다.
    printf("[%d] Child Process %d End\n", getpid(), child);
    printf("\t End Code %d\n", status >> 8);
}

