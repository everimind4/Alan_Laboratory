#include "MazeRunner.h"

int main()
{
    Fullscreen();
    SetConsoleColor();
    CursorView(0);
    do {        
        ClearConsole();
        DrawTitle();
        DrawMenu();
        PrintVersion();
        PrintCopyright();
    } while (Play(SelectMenu()));
}