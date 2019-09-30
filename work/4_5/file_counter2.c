#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE *fp;
	char line[100];
	char ch;
	int i;
	int kor = 0, num = 0, eng, bnk = 0, li = 0;
	int word = 0, total = 0;
	char fname[10];
	char text[300];
	
	int c;

	printf("파일 이름 입력(없을시'N'입력) >> ");
	//scanf("%s", &fname);
	fgets(fname, sizeof(fname), stdin);

	printf("aa\n");
	printf(">>>>>> %s\n", line);

	//c = getchar();
	//fflush(stdin);

	if ( getchar() == 'N') { // getchar() == 'N'
		printf("bb\n");
		printf("내용 입력 >> \n ");

		fgets(text, sizeof(text), fp);
		printf("cc\n");
		printf("%s", text);

		for(i = 0; i < strlen(text); i++) {
			ch = text[i];

			if(ch < 0)
				kor ++;
			else if(ch >= '0' && ch <= '9')
				num++;
			else if(ch >= 'A' && ch <= 'z')
				eng++;
			else if(ch == ' ' || ch == ',' || ch=='.') {
				word++;
			}
			else if(ch == '\n') {
				word++;
				li++;
			}
		}
	}
	else {
		if( (fp=fopen(fname, "r")) == NULL) {
			fprintf(stderr, "파일 열기 오류\n");
			exit(1);
		}
	

		while(!feof(fp)) {
			fgets(line, 100, fp);
			printf("%s", line);
	
			for( i = 0; i < strlen(line); i++) {
				ch = line[i];

				if(ch < 0)
					kor++;
				else if(ch >= '0' && ch <= '9')
					num++;
				else if(ch >= 'A' && ch <= 'z')
					eng++;
				else if(ch == ' ') {
					bnk++;
					word++;
				}
				else if(ch == '\n') {
					word++;
					li++;
				}
			}
		}
	}
	printf("\n");

	kor = kor / 2;
	total = kor + eng + num;

	//printf("한글 : %d\n", kor);
	//printf("영어 : %d\n", eng);
	//printf("숫자 : %d\n", num);
	//printf("공백 : %d\n", bnk);
	printf("문자 : %d\n", total);
	printf("단어 : %d\n", word);
	printf("라인 : %d\n", li);
	
	fclose(fp);
	return 0;
}

	

