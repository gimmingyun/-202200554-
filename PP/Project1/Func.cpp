#include "Func.h"

/*
[평가항목 3] : 배열 사용
*/
struct Covid x[229]; // 날짜별_감염자 수
char inp[20]; // 명령어

/*
[평가항목 6] : 포인터 활용 
*/
void (*F[3])(void) = { exitt, print1,print2 };
const char* word1[] = { "/exit","/print1","/print2" };
const char* word2[] = { "0","1","2"};

/*
[평가항목 7] : 파일 입출력
*/
/*
[평가항목 4] : 포인터 사용
*/
void File()
{
	char Line[300], * str;
	FILE* fp = NULL;

	if (fopen_s(&fp, "Data.csv", "rt") == 0)
	{
		int i = 0;
		while (fgets(Line, sizeof(Line), fp) != NULL)
		{
			str = Line; 				
			strcpy_s(x[i].data, str); 
			i++;
		}
		fclose(fp);
	}
}

void Menu() // 메인 매뉴
{
	printf("경기도 포천시 Covid-19 일일 감염자 수\n");
	printf("0 또는 /exit : 프로그램 종료\n");
	printf("1 또는 /print1 : 감염자 오름차순 출력\n");
	printf("2 또는 /print2 : 감염자 내림차순 출력\n");
	printf(": ");
	scanf_s("%s",inp, sizeof(inp));
	Commend(inp);
}

void Commend(char com[])
{
	if (strcmp(com, word1[0]) == 0 || strcmp(com, word2[0]) == 0)
	{
		F[0]();
	}
	else if (strcmp(com, word1[1]) == 0 || strcmp(com, word2[1]) == 0)
	{
		F[1]();
	}
	else if (strcmp(com, word1[2]) == 0 || strcmp(com, word2[2]) == 0)
	{
		F[2]();
	}
	else
	{
		printf(" 잘못된 입력값입니다.\n\n");
	}
}

void print1() 
{
	int i;
	printf("---------------------------------------\n");
	printf("포천시 확진자 수 오름차순 출력\n");
	printf("몇일치를 출력하시겠습니까?\n");
	printf("1 ~ 228\n");
	printf("---------------------------------------\n\n");
	printf(": ");
	scanf_s("%d", &i, sizeof(i));

	if (i >= 1 && i < 229) // 데이터 범위 안의 입력 감지
	{
		for (int j = 0; j < i; j++)
			printf("· %s\n", x[j].data);
		printf("\n---------------------------------------\n\n");	
	}
	else // 데이터 범위 밖의 입력 감지
	{
		printf(" 잘못된 입력값입니다.\n\n");
	}
}
void print2()
{
	int i;
	printf("---------------------------------------\n");
	printf("포천시 확진자 수 내림차순 출력\n");
	printf("몇일치를 출력하시겠습니까?\n");
	printf("1 ~ 228\n");
	printf("---------------------------------------\n\n");
	printf(": ");
	scanf_s("%d", &i, sizeof(i));

	if (i >= 1 && i < 229) // 데이터 범위 안의 입력 감지
	{
		for (int j = 227; j > 227 - i; j--)
			printf("· %s\n", x[j].data);
		printf("\n---------------------------------------\n\n");
	}
	else // 데이터 범위 밖의 입력 감지
	{
		printf(" 잘못된 입력값입니다.\n\n");
	}
}

void exitt() 
{
	exit(0);
}