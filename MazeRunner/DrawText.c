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
	ch = toupper(ch);
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
		go(row, col + 4);   printf("бсбсбс");
		return 3;
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
	case '!':
		go(row, col);       printf("  бс");
		go(row, col + 1);   printf("  бс");
		go(row, col + 2);   printf("  бс");
		go(row, col + 4);   printf("  бс");
		return 2;
	default: return 0;
	}
}

void DrawNumber(int row, int col, int number) {
	switch (number) {
	case 1:
		go(row - 10, col);      printf("                бсбс");
		go(row - 11, col + 1);  printf("                бсбс");
		go(row - 12, col + 2);  printf("                бсбс");
		go(row - 13, col + 3);  printf("                бсбс");
		go(row - 14, col + 4);  printf("                бсбс");
		go(row - 15, col + 5);  printf("                бсбс");
		go(row - 16, col + 6);  printf("                бсбс");
		go(row - 17, col + 7);  printf("                бсбс");
		go(row - 18, col + 8);  printf("                бсбс");
		go(row - 19, col + 9);  printf("                бсбс");
		go(row - 20, col + 10); printf("                бсбс");
		go(row - 21, col + 11); printf("                бсбс");
		go(row - 22, col + 12); printf("                бсбс");
		go(row - 23, col + 13); printf("                бсбс");
		go(row - 24, col + 14); printf("                бсбс");
		go(row - 25, col + 15); printf("                бсбс");
		break;
	case 2:
		go(row - 10, col);      printf("    бсбсбсбсбсбс");
		go(row - 11, col + 1);  printf("  бсбсбсбсбсбсбсбс");
		go(row - 12, col + 2);  printf("бсбс            бсбс");
		go(row - 13, col + 3);  printf("бсбс            бсбс");
		go(row - 14, col + 4);  printf("бсбс            бсбс"); 
		go(row - 15, col + 5);  printf("бсбс            бсбс"); 
		go(row - 16, col + 6);  printf("           бсбсбс"); 
		go(row - 17, col + 7);  printf("           бсбсбс"); 
		go(row - 18, col + 8);  printf("       бсбсбс"); 
		go(row - 19, col + 9);  printf("       бсбсбс");
		go(row - 20, col + 10); printf("   бсбсбс");
		go(row - 21, col + 11); printf("   бсбсбс"); 
		go(row - 22, col + 12); printf("бсбс");
		go(row - 23, col + 13); printf("бсбс");
		go(row - 24, col + 14); printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 25, col + 15); printf("бсбсбсбсбсбсбсбсбсбс");
		break;
	case 3:
		go(row - 10, col);      printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 11, col + 1);  printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 12, col + 2);  printf("                бсбс");
		go(row - 13, col + 3);  printf("                бсбс");
		go(row - 14, col + 4);  printf("                бсбс");
		go(row - 15, col + 5);  printf("                бсбс");
		go(row - 16, col + 6);  printf("                бсбс");
		go(row - 17, col + 7);  printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 18, col + 8);  printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 19, col + 9);  printf("                бсбс");
		go(row - 20, col + 10); printf("                бсбс");
		go(row - 21, col + 11); printf("                бсбс");
		go(row - 22, col + 12); printf("                бсбс");
		go(row - 23, col + 13); printf("                бсбс");
		go(row - 24, col + 14); printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 25, col + 15); printf("бсбсбсбсбсбсбсбсбсбс");
		break;
	case 4:
		go(row - 10, col);      printf("бсбс            бсбс");
		go(row - 11, col + 1);  printf("бсбс            бсбс");
		go(row - 12, col + 2);  printf("бсбс            бсбс");
		go(row - 13, col + 3);  printf("бсбс            бсбс");
		go(row - 14, col + 4);  printf("бсбс            бсбс");
		go(row - 15, col + 5);  printf("бсбс            бсбс");
		go(row - 16, col + 6);  printf("бсбс            бсбс");
		go(row - 17, col + 7);  printf("  бсбсбсбсбсбсбсбсбс");
		go(row - 18, col + 8);  printf("    бсбсбсбсбсбсбсбс");
		go(row - 19, col + 9);  printf("                бсбс");
		go(row - 20, col + 10); printf("                бсбс");
		go(row - 21, col + 11); printf("                бсбс");
		go(row - 22, col + 12); printf("                бсбс");
		go(row - 23, col + 13); printf("                бсбс");
		go(row - 24, col + 14); printf("                бсбс");
		go(row - 25, col + 15); printf("                бсбс");
		break;
	case 5:
		go(row - 10, col);      printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 11, col + 1);  printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 12, col + 2);  printf("бсбс");
		go(row - 13, col + 3);  printf("бсбс");
		go(row - 14, col + 4);  printf("бсбс");
		go(row - 15, col + 5);  printf("бсбс");
		go(row - 16, col + 6);  printf("бсбс");
		go(row - 17, col + 7);  printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 18, col + 8);  printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 19, col + 9);  printf("                бсбс");
		go(row - 20, col + 10); printf("                бсбс");
		go(row - 21, col + 11); printf("                бсбс");
		go(row - 22, col + 12); printf("                бсбс");
		go(row - 23, col + 13); printf("                бсбс");
		go(row - 24, col + 14); printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 25, col + 15); printf("бсбсбсбсбсбсбсбсбсбс");
		break;
	case 6:
		go(row - 10, col);      printf("  бсбсбсбсбсбсбс");
		go(row - 11, col + 1);  printf("  бсбсбсбсбсбсбс");
		go(row - 12, col + 2);  printf("бсбс");
		go(row - 13, col + 3);  printf("бсбс");
		go(row - 14, col + 4);  printf("бсбс");
		go(row - 15, col + 5);  printf("бсбс");
		go(row - 16, col + 6);  printf("бсбс");
		go(row - 17, col + 7);  printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 18, col + 8);  printf("бсбсбсбсбсбсбсбсбсбс");
		go(row - 19, col + 9);  printf("бсбс            бсбс");
		go(row - 20, col + 10); printf("бсбс            бсбс");
		go(row - 21, col + 11); printf("бсбс            бсбс");
		go(row - 22, col + 12); printf("бсбс            бсбс");
		go(row - 23, col + 13); printf("бсбс            бсбс");
		go(row - 24, col + 14); printf("  бсбсбсбсбсбсбсбс");
		go(row - 25, col + 15); printf("    бсбсбсбсбсбсбс");
		break;
	case 7:
		go(row - 10, col);      printf("    бсбсбсбсбсбс");
		go(row - 11, col + 1);  printf("  бсбсбсбсбсбсбсбс");
		go(row - 12, col + 2);  printf("бсбс            бсбс");
		go(row - 13, col + 3);  printf("бсбс            бсбс");
		go(row - 14, col + 4);  printf("бсбс            бсбс");
		go(row - 15, col + 5);  printf("бсбс            бсбс");
		go(row - 16, col + 6);  printf("бсбс            бсбс");
		go(row - 17, col + 7);  printf("                бсбс");
		go(row - 18, col + 8);  printf("                бсбс");
		go(row - 19, col + 9);  printf("                бсбс");
		go(row - 20, col + 10); printf("                бсбс");
		go(row - 21, col + 11); printf("                бсбс");
		go(row - 22, col + 12); printf("                бсбс");
		go(row - 23, col + 13); printf("                бсбс");
		go(row - 24, col + 14); printf("                бсбс");
		go(row - 25, col + 15); printf("                бсбс");
		break;	
	case 8:
		go(row - 10, col);      printf("    бсбсбсбсбсбс");
		go(row - 11, col + 1);  printf("  бсбсбсбсбсбсбсбс");
		go(row - 12, col + 2);  printf("бсбс            бсбс");
		go(row - 13, col + 3);  printf("бсбс            бсбс");
		go(row - 14, col + 4);  printf("бсбс            бсбс");
		go(row - 15, col + 5);  printf("бсбс            бсбс");
		go(row - 16, col + 6);  printf("бсбс            бсбс");
		go(row - 17, col + 7);  printf("  бсбсбсбсбсбсбсбс");
		go(row - 18, col + 8);  printf("  бсбсбсбсбсбсбсбс");
		go(row - 19, col + 9);  printf("бсбс            бсбс");
		go(row - 20, col + 10); printf("бсбс            бсбс");
		go(row - 21, col + 11); printf("бсбс            бсбс");
		go(row - 22, col + 12); printf("бсбс            бсбс");
		go(row - 23, col + 13); printf("бсбс            бсбс");
		go(row - 24, col + 14); printf("  бсбсбсбсбсбсбсбс");
		go(row - 25, col + 15); printf("    бсбсбсбсбсбс");
		break;
	case 9:
		go(row - 10, col);      printf("    бсбсбсбсбсбс");
		go(row - 11, col + 1);  printf("  бсбсбсбсбсбсбсбс");
		go(row - 12, col + 2);  printf("бсбс            бсбс");
		go(row - 13, col + 3);  printf("бсбс            бсбс");
		go(row - 14, col + 4);  printf("бсбс            бсбс");
		go(row - 15, col + 5);  printf("бсбс            бсбс");
		go(row - 16, col + 6);  printf("бсбс            бсбс");
		go(row - 17, col + 7);  printf("    бсбсбсбсбсбсбсбс");
		go(row - 18, col + 8);  printf("      бсбсбсбсбсбсбс");
		go(row - 19, col + 9);  printf("                бсбс");
		go(row - 20, col + 10); printf("                бсбс");
		go(row - 21, col + 11); printf("                бсбс");
		go(row - 22, col + 12); printf("                бсбс");
		go(row - 23, col + 13); printf("                бсбс");
		go(row - 24, col + 14); printf("                бсбс");
		go(row - 25, col + 15); printf("                бсбс");
		break;
	case 0:
		go(row - 10, col);      printf("    бсбсбсбсбсбс");
		go(row - 11, col + 1);  printf("  бсбсбсбсбсбсбсбс");
		go(row - 12, col + 2);  printf("бсбс            бсбс");
		go(row - 13, col + 3);  printf("бсбс            бсбс");
		go(row - 14, col + 4);  printf("бсбс            бсбс");
		go(row - 15, col + 5);  printf("бсбс            бсбс");
		go(row - 16, col + 6);  printf("бсбс            бсбс");
		go(row - 17, col + 7);  printf("бсбс            бсбс");
		go(row - 18, col + 8);  printf("бсбс            бсбс");
		go(row - 19, col + 9);  printf("бсбс            бсбс");
		go(row - 20, col + 10); printf("бсбс            бсбс");
		go(row - 21, col + 11); printf("бсбс            бсбс");
		go(row - 22, col + 12); printf("бсбс            бсбс");
		go(row - 23, col + 13); printf("бсбс            бсбс");
		go(row - 24, col + 14); printf("  бсбсбсбсбсбсбсбс");
		go(row - 25, col + 15); printf("    бсбсбсбсбсбс");
		break;	
	default: break;
	}
}