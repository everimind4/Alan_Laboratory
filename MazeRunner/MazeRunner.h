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

#define CENTERROW 116
#define CENTERCOL 32
#define MENUINITROW CENTERROW - 16
#define MENUINITCOL CENTERCOL + 3
#define MENUCOLDIST 8

// ConsoleSetting.c
void Fullscreen();
void SetConsoleColor();
void ClearConsole();
void go(int, int);
void CursorView(int);

// ConsoleUI.c
void DrawTitle();
void DrawMenu();
void PrintVersion();
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

// DrawText.c
void DrawString(int, int, const char*);
int DrawChar(int, int, char);
void DrawNumber(int, int, int);

// GamePlay.c
int Play(int);
void ShowStartNEnd(int, int);
int MazeRunner(int, int);
void ShowMaze(int, int, int);
void Arrow(int, int, int);
void Score(clock_t);

// MazeGenerator.c
void MazeGenerator(int, int);
void SetRight(int, int, int);
void SetDown(int, int, int);
int GetDown(int, int);