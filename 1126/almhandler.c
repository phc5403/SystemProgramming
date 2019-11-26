#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void alarmHandler();

/* 알람 시그널을 처리한다 */
int main() {
    signal(SIGALRM, alarmHandler);
    alarm(5); // 알람 시간 설정

    printf("Infinite Loof\n");

    while(1) {
        sleep(1);
        printf("1 second..\n");
    }

    printf("Not execute\n");
}

void alarmHandler() {
    printf("Wake Up!\n");
    exit(0);
}

