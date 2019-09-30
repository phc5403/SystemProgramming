#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int main(void) {
	FILE *fp1;
	FILE *fp2;

	char a[SIZE];
	char b[SIZE];
	char f1[SIZE];
	char f2[SIZE];
	int bytes = 0;
	int line_count = 0;

	printf("첫번째 파일 이름 : ");
	gets(a);
	printf("두번째 파일 이름 : ");
	gets(b);

	if( (fp1 = fopen(a, "r")) == NULL)
	{
		fprintf(stderr, "파일1 열기 오류\n");
		exit(1);
	}

	if( (fp2 = fopen(b, "r")) == NULL)
	{
		fprintf(stderr, "파일2 열기 오류\n");
		exit(1);
	}

	while(1)
	{
		fgets(f1, sizeof(f1), fp1);
		fgets(f2, sizeof(f2), fp2);
		line_count++;
		
		if(strcmp(f1, f2) != 0)
		{
			printf("파일1의 내용 >> %s \n", f1);
			printf("파일2의 내용 >> %s \n", f2);
			printf("파일1 FP >> %ld\n", ftell(fp1));
			printf("파일2 FP >> %ld\n", ftell(fp2));
			printf("처음으로 달라지는 Line >> %d\n", line_count);
			break;
		}

		if(feof(fp1) != 0)
		{
			printf("두 파일이 서로 일치합니다. \n");
			break;
		}
	}

	return 0;
}


