#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* 세 개의 자식 프로세스를 생성하여 각각 다른 명령어를 실행한다. */
int main() {
    printf("Parent Process Start\n");

    if(fork() == 0) {
        execl("/bin/echo", "echo", "hello", NULL); // "echo"를 변경해보기(인자 둘다)
        fprintf(stderr, "First false");
        exit(1);
    }

    if(fork() ==0) {
        execl("/bin/date", "date", NULL);
        fprintf(stderr, "Second false");
        exit(2);
    }

    if(fork() == 0) {
        execl("/bin/ls", "ls", "-l", NULL);
        fprintf(stderr, "Third false");
        exit(3);
    }

    printf("Parent Process End\n");
}

