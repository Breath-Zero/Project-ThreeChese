#pragma once
#include"Game.h"

void Game()
{
	char a='w';
	//int a = -1;
	int count = 0;
	char board[ROW][COL];
	InitBoard(board,ROW,COL);
	stampGame(board, ROW, COL);

	while (1)
	{
		PlayerRemove(board, ROW, COL);
		count++;
		stampGame(board, ROW, COL);
		a=IsWinGame(board, ROW, COL);
		/*if (a == 1)
		{
			printf("玩家赢\n");
			return;
		}
		else if(a == 0)
		{
			printf("电脑赢\n");
			return;
		}
		if (count == ROW * COL)
		{
			printf("平局\n");
			return;
		}*/
		if (a != ' ')
		{
			find_win(a);
			break;
		}
		computerRemove(board, ROW, COL);
		count++;
		stampGame(board, ROW, COL);
		a = IsWinGame(board, ROW, COL);
		/*if (a == 1)
		{
			printf("玩家赢\n");
			return;
		}
		else if(a == 0)
		{
			printf("电脑赢\n");
			return;
		}
		if (count == ROW*COL)
		{
			printf("平局\n");
			return;
		}*/

		if (a != ' ')
		{
			find_win(a);
			break;
		}

	}
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	memset(board, ' ', sizeof(board[0][0])*row*col);
}

void stampGame(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		
		if (i<row-1)
		{
			for (j = 0; j < row; j++)
			{
				printf("---");
				if (j < row-1)
					printf("|");
			}
		}
		printf("\n");

	}
}

void PlayerRemove(char board[ROW][COL], int row, int col)
{
	int x = -1, y = -1;
    printf("玩家走：\n");
	while (1)
	{		
		scanf("%d %d", &x, &y);
		if (x <= row && y <= col && x > 0 && y > 0)
		{
			if (board[x-1][y-1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				return;
			}
			else
			{
				printf("此位被占了请重新输入：\n");
			}
		}
		else
		{
			printf("垃圾输入错误：\n");
		}
	}
	
}

void computerRemove(char board[ROW][COL], int row, int col)
{
	int x = -1, y = -1;
	printf("电脑走：\n");


	while (1)
	{
		x = rand() % row;
		y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = 'X';
			return;
		}
	}
}

//int IsWinGame(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < row; i++)
//	{
//		if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
//		{
//			if (board[i][0] == 'X')
//			{
//				return 0;
//			}
//			else if (board[i][0] == 'O')
//			{
//				return 1;
//			}
//		}
//	}
//	for (i = 0; i < row; i++)
//	{
//		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
//		{
//			if (board[0][i] == 'X')
//			{
//				return 0;
//			}
//			else if (board[0][i] == 'O')
//			{
//				return 1;
//			}
//		}
//	}
//	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
//		(board[2][0] == board[1][1] && board[1][1] == board[0][2]))
//	{
//		if (board[1][1] == 'X')
//		{
//			return 0;
//		}
//		else if (board[1][1] == 'O')
//		{
//			return 1;
//		}
//	}
//	return -1;
//}

char IsWinGame(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col - 1; j++)
		{
			if (board[i][j] != board[i][j + 1])
				break;
		}
		if (j == col - 1)
			return board[i][0];
			//return '0';
	}
	for (i = 0; i < col; i++)
	{
		int j = 0;
		for (j = 0; j < row - 1; j++)
		{
			if (board[j][i] != board[j + 1][i])
				break;
		}
		if (j == row - 1)
			return board[0][i];
			//return '0';

	}

	for (i = 0; i < row - 1; i++)
	{
		if (board[i][i] != board[i + 1][i + 1])
			break;
	}
	if (i == row - 1)
		return board[0][0];
		//return '0';

////=========================


	for (i = 0; i < row - 1; i++)
	{
		if (board[i][row - 1 - i] != board[i + 1][row - 1 - i - 1])
			break;
	}
	if (i == row - 1)
		return board[row - 1][0];
		//return '0';

	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return ' ';
		}
	}
	return 'Q';
}
void find_win(char win)
{
	if (win == 'O')
		printf("玩家赢\n");
	else if (win == 'X')
		printf("电脑赢\n");
	else
		printf("平局\n");
}
