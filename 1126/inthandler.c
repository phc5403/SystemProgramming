#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void intHandler();

/* 인터럽트 시그널을 처리한다 */
int main() {
    signal(SIGINT, intHandler);
    
    while(1) { // loof는 멈춰있다. Ctrl+C로 인터럽트 시그널 전달해줘야함
        pause();
    }

    printf("Not execute\n");
}

void intHandler(int signo) {
    printf("Interrupt signal process\n");
    printf("Signal Number : %d \n", signo);
    exit(0);
}



