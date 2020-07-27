#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	stack<char> mystack;
	FILE* stack = fopen("DS5.6_2.cpp", "rt");
	while (1)
	{
		char test = (char)fgetc(stack);
		if (strcmp(&test, "{") == 0)
			mystack.push(test);
		if (strcmp(&test, "(") == 0)
			mystack.push(test);
		if (strcmp(&test, "}") == 0)
		{
			char* temp = &mystack.top();
			if (strcmp(temp, "{"))
				mystack.pop();
		}
		if (strcmp(&test, ")") == 0)
		{
			char* temp = &mystack.top();
			if (strcmp(temp, "("))
				mystack.pop();
		}
		if (test == EOF)
			break;
	}
	fclose(stack);
	int idx_temp = 1;
	cout << "Stack #" << idx_temp << " : ";
	mystack.pop();
	cout << endl;
	
	return 0;
}


