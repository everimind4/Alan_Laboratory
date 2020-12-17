#include "MazeRunner.h"

void DrawString(int row, int col, const char* string) {
	int printrow = row, printcol = col;
	go(printrow, printcol);	
	for (int i = 0; i < (int)strlen(string); i++) {
		if (string[i] == ' ') {
			printrow += 2;
			continue;
		}
		else if (string[i] == '\n') {
			printcol += 7;
			printrow = row;
			continue;
		}
		int width = DrawChar(printrow, printcol, string[i]);
		printrow += (width + 1) * 2;
	}
}

int DrawChar(int row, int col, char ch) {
	toupper(ch);
	switch (ch) {
	case 'A':
		go(row, col);       printf("  бсбс");
		go(row, col + 1);   printf("бс    бс");
		go(row, col + 2);   printf("бсбсбсбс");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf("бс    бс");
		return 4;
	case 'B':
		go(row, col);       printf("бсбсбс");
		go(row, col + 1);   printf("бс    бс");
		go(row, col + 2);   printf("бсбсбс");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf("бсбсбс");
		return 4;
	case 'C':
		go(row, col);       printf("  бсбсбс");
		go(row, col + 1);   printf("бс");
		go(row, col + 2);   printf("бс");
		go(row, col + 3);   printf("бс");
		go(row, col + 4);   printf("  бсбсбс");
		return 4;
	case 'D':
		go(row, col);       printf("бсбсбс");
		go(row, col + 1);   printf("бс    бс");
		go(row, col + 2);   printf("бс    бс");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf("бсбсбс");
		return 4;
	case 'E':
		go(row, col);       printf("бсбсбсбс");
		go(row, col + 1);   printf("бс");
		go(row, col + 2);   printf("бсбсбсбс");
		go(row, col + 3);   printf("бс");
		go(row, col + 4);   printf("бсбсбсбс");
		return 4;
	case 'F':
		go(row, col);       printf("бсбсбсбс");
		go(row, col + 1);   printf("бс");
		go(row, col + 2);   printf("бсбсбсбс");
		go(row, col + 3);   printf("бс");
		go(row, col + 4);   printf("бс");
		return 4;
	case 'G':
		go(row, col);       printf(" бсбсбс");
		go(row, col + 1);   printf("бс");
		go(row, col + 2);   printf("бс  бсбс");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf(" бсбсбс");
		return 4;
	case 'H':
		go(row, col);       printf("бс    бс");
		go(row, col + 1);   printf("бс    бс");
		go(row, col + 2);   printf("бсбсбсбс");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf("бс    бс");
		return 4;
	case 'I':
		go(row, col);       printf("бсбсбс");
		go(row, col + 1);   printf("  бс");
		go(row, col + 2);   printf("  бс");
		go(row, col + 3);   printf("  бс");
		go(row, col + 4);   printf("бсбсбс");
		return 3;
	case 'J':
		go(row, col);       printf("      бс");
		go(row, col + 1);   printf("      бс");
		go(row, col + 2);   printf("бс    бс");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf("  бсбс");
		return 4;
	case 'K':
		go(row, col);       printf("бс    бс");
		go(row, col + 1);   printf("бс  бс");
		go(row, col + 2);   printf("бсбс");
		go(row, col + 3);   printf("бс  бс");
		go(row, col + 4);   printf("бс    бс");
		return 4;
	case 'L':
		go(row, col);       printf("бс");
		go(row, col + 1);   printf("бс");
		go(row, col + 2);   printf("бс");
		go(row, col + 3);   printf("бс");
		go(row, col + 4);   printf("бсбсбсбс");
		return 4;
	case 'M':
		go(row, col);       printf("бс      бс");
		go(row, col + 1);   printf("бсбс  бсбс");
		go(row, col + 2);   printf("бс  бс  бс");
		go(row, col + 3);   printf("бс      бс");
		go(row, col + 4);   printf("бс      бс");
		return 5;
	case 'N':
		go(row, col);       printf("бс      бс");
		go(row, col + 1);   printf("бсбс    бс");
		go(row, col + 2);   printf("бс  бс  бс");
		go(row, col + 3);   printf("бс    бсбс");
		go(row, col + 4);   printf("бс      бс");
		return 5;
	case 'O':
		go(row, col);       printf("  бсбс");
		go(row, col + 1);   printf("бс    бс");
		go(row, col + 2);   printf("бс    бс");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf("  бсбс");
		return 4;
	case 'P':
		go(row, col);       printf("бсбсбс");
		go(row, col + 1);   printf("бс    бс");
		go(row, col + 2);   printf("бсбсбс");
		go(row, col + 3);   printf("бс");
		go(row, col + 4);   printf("бс");
		return 4;
	case 'Q':
		go(row, col);       printf("  бсбс");
		go(row, col + 1);   printf("бс    бс");
		go(row, col + 2);   printf("бс  бсбс");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf("  бсбс  бс");
		return 5;
	case 'R':
		go(row, col);       printf("бсбсбс   ");
		go(row, col + 1);   printf("бс    бс");
		go(row, col + 2);   printf("бсбсбс   ");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf("бс    бс");
		return 4;
	case 'S':
		go(row, col);       printf("бсбсбсбс");
		go(row, col + 1);   printf("бс");
		go(row, col + 2);   printf("бсбсбсбс");
		go(row, col + 3);   printf("      бс");
		go(row, col + 4);   printf("бсбсбсбс");
		return 4;
	case 'T':
		go(row, col);       printf("бсбсбс");
		go(row, col + 1);   printf("  бс");
		go(row, col + 2);   printf("  бс");
		go(row, col + 3);   printf("  бс");
		go(row, col + 4);   printf("  бс");
		return 3;
	case 'U':
		go(row, col);       printf("бс    бс");
		go(row, col + 1);   printf("бс    бс");
		go(row, col + 2);   printf("бс    бс");
		go(row, col + 3);   printf("бс    бс");
		go(row, col + 4);   printf("  бсбс");
		return 4;
	case 'V':
		go(row, col);       printf("бс      бс");
		go(row, col + 1);   printf(" бс    бс");
		go(row, col + 2);   printf("  бс  бс");
		go(row, col + 3);   printf("   бсбс");
		go(row, col + 4);   printf("    бс");
		return 5;
	case 'W':
		go(row, col);       printf("бс  бс  бс");
		go(row, col + 1);   printf("бс  бс  бс");
		go(row, col + 2);   printf("бс  бс  бс");
		go(row, col + 3);   printf(" бсбсбсбс");
		go(row, col + 4);   printf("  бс  бс");
		return 5;
	case 'X':
		go(row, col);       printf("бс  бс");
		go(row, col + 1);   printf(" бсбс");
		go(row, col + 2);   printf("  бс");
		go(row, col + 3);   printf(" бсбс");
		go(row, col + 4);   printf("бс  бс");
		return 3;
	case 'Y':
		go(row, col);       printf("бс    бс");
		go(row, col + 1);   printf(" бс  бс");
		go(row, col + 2);   printf("  бсбс");
		go(row, col + 3);   printf("   бс");
		go(row, col + 4);   printf("   бс");
		return 4;
	case 'Z':
		go(row, col);       printf("бсбсбсбс");
		go(row, col + 1);   printf("     бс");
		go(row, col + 2);   printf("   бс");
		go(row, col + 3);   printf(" бс");
		go(row, col + 4);   printf("бсбсбсбс");
		return 4;
	default: return 0;
	}	
}