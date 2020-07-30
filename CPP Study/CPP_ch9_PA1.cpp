#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Printer {
public:
	Printer() {}
	virtual void Method(char* buffer) = 0;
	virtual int Dpi() = 0;
};

// (1)
//class LaserPrinter : public Printer {
//public:
//	void Method(char* buffer) { return; }
//// 	int Dpi() { return 0; }
//};


// (2)
class DotMatrixPrinter : public Printer {
	int nDots;
public:
	DotMatrixPrinter(int n) : nDots(n) {}
	void Method(char* buffer) {
		sprintf(buffer, "Dot matrix printer with %d pins", nDots);
		printf("%s\n\n", buffer);
	}
	int Dpi() {
		switch (nDots) {
		case 8: return 150;
		case 9: return 160;
		case 24: return 300;
		default: return 100;
		}
	}
};

int main()
{
	// LaserPrinter pl;
	Printer* dp = new DotMatrixPrinter(24);
	char* test[256] = { '\0', };
	dp->Method((char*)test);
	printf("The function 'Dpi()' generate that number : %d\n", dp->Dpi());
	return 0;
}