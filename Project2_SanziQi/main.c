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
			printf("�������\n");
			fflush(stdin);//������뻺���������������ַ������ݶ���ѭ��
			break;
		}
	} while (input);

	system("pause");
	return 0;
}