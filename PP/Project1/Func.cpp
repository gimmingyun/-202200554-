#include "Func.h"

/*
[���׸� 3] : �迭 ���
*/
struct Covid x[229]; // ��¥��_������ ��
char inp[20]; // ���ɾ�

/*
[���׸� 6] : ������ Ȱ�� 
*/
void (*F[3])(void) = { exitt, print1,print2 };
const char* word1[] = { "/exit","/print1","/print2" };
const char* word2[] = { "0","1","2"};

/*
[���׸� 7] : ���� �����
*/
/*
[���׸� 4] : ������ ���
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

void Menu() // ���� �Ŵ�
{
	printf("��⵵ ��õ�� Covid-19 ���� ������ ��\n");
	printf("0 �Ǵ� /exit : ���α׷� ����\n");
	printf("1 �Ǵ� /print1 : ������ �������� ���\n");
	printf("2 �Ǵ� /print2 : ������ �������� ���\n");
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
		printf(" �߸��� �Է°��Դϴ�.\n\n");
	}
}

void print1() 
{
	int i;
	printf("---------------------------------------\n");
	printf("��õ�� Ȯ���� �� �������� ���\n");
	printf("����ġ�� ����Ͻðڽ��ϱ�?\n");
	printf("1 ~ 228\n");
	printf("---------------------------------------\n\n");
	printf(": ");
	scanf_s("%d", &i, sizeof(i));

	if (i >= 1 && i < 229) // ������ ���� ���� �Է� ����
	{
		for (int j = 0; j < i; j++)
			printf("�� %s\n", x[j].data);
		printf("\n---------------------------------------\n\n");	
	}
	else // ������ ���� ���� �Է� ����
	{
		printf(" �߸��� �Է°��Դϴ�.\n\n");
	}
}
void print2()
{
	int i;
	printf("---------------------------------------\n");
	printf("��õ�� Ȯ���� �� �������� ���\n");
	printf("����ġ�� ����Ͻðڽ��ϱ�?\n");
	printf("1 ~ 228\n");
	printf("---------------------------------------\n\n");
	printf(": ");
	scanf_s("%d", &i, sizeof(i));

	if (i >= 1 && i < 229) // ������ ���� ���� �Է� ����
	{
		for (int j = 227; j > 227 - i; j--)
			printf("�� %s\n", x[j].data);
		printf("\n---------------------------------------\n\n");
	}
	else // ������ ���� ���� �Է� ����
	{
		printf(" �߸��� �Է°��Դϴ�.\n\n");
	}
}

void exitt() 
{
	exit(0);
}