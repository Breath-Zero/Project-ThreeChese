#pragma once
#include"Game.h"

void menu()
{
	printf("=============================\n");
	printf("======== 1.play =============\n");
	printf("======== 0.exit =============\n");
	printf("=============================\n");
}

int main()
{
	int input;
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			break;
		default:
			printf("输入错误：\n");
			fflush(stdin);//清空输入缓冲区，避免输入字符型数据而死循环
			break;
		}
	} while (input);

	system("pause");
	return 0;
}