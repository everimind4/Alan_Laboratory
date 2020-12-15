#include "MazeRunner.h"
#include <Windows.h>

int main()
{
    Fullscreen();
    ClearConsole();
    SetConsoleColor();
    CursorView(0);
    DrawTitle();
    DrawMenu();
    SelectMenu();
}