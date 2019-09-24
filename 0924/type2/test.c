#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	struct stat buf;
	stat("test1.txt", &buf);
	printf("st_mode = %o\n", buf.st_mode);

	return 0;
}


