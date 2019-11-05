#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// 명령어 인자로 준 시간만큼 지연 시키기
int main(int argc, char* argv[])
{
    printf("Hello\n");
	sleep(atof(argv[1]));
	printf("Bye\n");

	printf("%f초 만큼 지연 시킴.\n", atof(argv[1]));
}

