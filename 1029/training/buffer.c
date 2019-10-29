#include <stdio.h>

int main(int argc, char *argv[]) {
	int total = 0, cnt = 0 ;
	char ch;
	int i=0, k=0;

	printf("전체 반복 횟수 입력 : ");
	scanf("%d", &total);
	getchar();

	while(i < total) {
		printf("\n문자와 출력 횟수 입력 : ");
		scanf(" %c %d", &ch, &cnt);

		printf("\t당신은 %c와 %d를 입력했습니다.", ch, cnt);

		for(k=0; k < cnt; k++)
			printf("%c", ch);
		i++;
	}
	
	printf("\n");
	return 0;
}



	
