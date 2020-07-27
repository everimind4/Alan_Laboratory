#include <iostream>
#include "arraystack.h"
using namespace std;

int main()
{
	ArrayStack<int> A;
	A.push(7);
	A.push(13);
	cout << A.top() << endl;
	A.push(9);
	cout << A.top() << endl; A.pop();
	cout << A.top() << endl; A.pop();
	cout << A.top() << endl;
	ArrayStack<string> B(10);
	B.push("Bob");
	B.push("Alice");
	cout << B.top() << endl; B.pop();
	B.push("Eve");
	cout << B.top() << endl;

	return 0;
}