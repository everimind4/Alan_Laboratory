#include "MazeRunner.h"

int main()
{
    do {
        Fullscreen();
        ClearConsole();
        SetConsoleColor();
        CursorView(0);
        DrawTitle();
        DrawMenu();
        PrintVersion();
        PrintCopyright();
    } while (Play(SelectMenu()));
}