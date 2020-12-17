#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13
#define ESC 27

#define MENUINITROW 90
#define MENUINITCOL 35
#define MENUCOLDIST 8

void Fullscreen();
void SetConsoleColor();
void ClearConsole();
void go(int, int);
void CursorView(int);
void DrawTitle();
void DrawMenu();
void PrintCopyright();
int SelectMenu();
void ShowSelected(int);
void ShowLevel(int);
void ClearLevelInfo(int, int);
void NEWBIE(int, int);
void EASY(int, int);
void NORMAL(int, int);
void HARD(int, int);
void KOREAN(int, int);
void Play(int);
void MazeGenerator(int, int);
void ShowStartNEnd(int, int);
void MazeRunner(int, int);