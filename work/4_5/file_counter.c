#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp;

	int letter = 0; // 문자
	int word = 0;   // 단어
	int line = 0;   // 줄 
	int state = 0;  // 상태
	char a[10];     // 입력할 파일명
	char ch;        // 글자

	
	printf("파일 이름 : ");
	gets(a);

	
	if( (fp = fopen(a, "rt")) == NULL)
	{
		fprintf(stderr, "파일 열기 오류\n");
		exit(1);
	}
	

	/*
	fp = fopen("test.txt", "rt");
	if (fp == NULL) {
		printf("파일 열기 오류\n");
		return 1;
	}
	*/
	

	printf("파일의 내용 출력..\n");
	
	while(1) {
		fscanf(fp, "%c", &ch);
		printf("%c", ch);

		if(ch >= 'A' && ch <= 'z') {
			letter++;
			if(state == 0) {
				state = 1;
			}
		}
		else {
			if(state == 1) {
				if(ch == '(') {
					state = 2;
				}
				else if(ch == ' ' || ch == ',' || ch == '.') {
					state = 0;
					word++;
				}
			}
			else if(state == 2) {
				if(ch == ')') {
					word++;
					state = 0;
				}
			}
		}

		if (ch == '\n') {
			line++;
		}
		
		if(feof(fp) != 0)
		{
			break;
		}

	}
	fclose(fp);

	//line++;
	line = line - 1;
	
	printf("\n\n 글자 >> %d, 단어 : %d개, 라인 : %d줄 \n\n", letter, word, line);

	return 0;
}




