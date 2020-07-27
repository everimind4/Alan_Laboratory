#include <iostream>
using namespace std;

int main()
{
	int a = 2;
	int b = 10;
	int& c = b;
	cout << "&b = " << &b << ", &c = " << &c << endl;
	cout << endl << "b equals to " << b << endl;

	c = a * b;
	cout << "After c = a * b : a = " << a << ", b = " << b << ", c = " << c << endl;
	cout << endl << "now b equals to " << b << endl;
	system("pause");
	
	return 0;
}