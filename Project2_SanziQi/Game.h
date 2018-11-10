#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<time.h>


#define ROW 5
#define COL 5

void Game();
void stampGame(char board[ROW][COL], int row, int col);
void InitBoard(char board[ROW][COL], int row, int col);
void PlayerRemove(char board[ROW][COL], int row, int col);
void computerRemove(char board[ROW][COL], int row, int col);
//int IsWinGame(char board[ROW][COL], int row, int col);
char IsWinGame(char board[ROW][COL], int row, int col);
void find_win(char win);


