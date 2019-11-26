#include <stdio.h>
#include <unistd.h>

/* 알람 시그널을 보여주는 프로그램 */
int main() {
    alarm(5);
    printf("Infinite Loof\n");
    
    while(1) {
        sleep(1);
        printf("1 second...\n");
    }

    printf("Not execute\n");
}

