#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* 자식 프로세스를 생성하여 echo 명령어를 실행한다. */
int main() {
    printf("Parent Process Start\n");

    if(fork() == 0) {
        //execl("/bin/echo", "echo", "hello", NULL);
        execl("/bin/", "echo", "bye", NULL); // 이 코드는 stderr를 유발함.
        fprintf(stderr, "First false");
        exit(1);
    }

    printf("Parent Process End\n");
}


