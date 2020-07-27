#include <iostream>
using namespace std;

class Complex {
public :
	Complex() {
		r = 0;
		i = 0;
	}
	void Add(Complex c) {
		r += c.r;
		i += c.i;
	}
	void Add(Complex* pc) {
		r += (*pc).r;
		i += (*pc).i;
	}
	void Add(int a, int b = 0) {
		r += a;
		i += b;
	}
	Complex operator+(Complex y) {
		Complex c;
		c.r = r + y.r;
		c.i = i + y.i;
		return c;
	}
	Complex operator++(int) {
		Complex c;
		c.r = ++r;
		c.i = ++i;
		return c;
	}
	int r;
	int i;
};
Complex Multiply(Complex c1, Complex c2) {
	Complex c3;
	c3.r = c1.r * c2.r - c1.i * c2.i;
	c3.i = c1.r * c2.i + c1.i * c2.r;
	return c3;
}
Complex Multiply(Complex c, int n) {
	c.r *= n;
	c.i *= n;
	return c;
}
void Print(Complex c) {
	cout << c.r << "+" << c.i << "i" << endl;
}
void Print(int n) {
	cout << n << endl;
}
void Print(const char* string) {
	cout << string << endl;
}
void Print() {
	cout << endl;
}

int main() {
	Complex x; x.Add(3, 1);
	Complex y; y.Add(1, 2);
	int z = 4;
	Print("Sum of the complex numbers : ");
	cout << "x = "; Print(x);
	cout << "y = "; Print(y);
	x.Add(y);
	Print("----");
	cout << "x+y = ";  Print(x);
	y.Add(z);
	cout << "After y.Add(z)::y = "; Print(y);
	Complex product1, product2;
	int v = 7;
	product1 = Multiply(x, y);
	product2 = Multiply(x, v);
	Print(); Print();
	Print("x equals to : ");
	Print(x); Print();
	Print("y equals to : ");
	Print(y); Print();
	Print("v equals to : ");
	Print(v);
	Print();
	Print("x * y = ");
	Print(product1);
	Print();
	Print("x * v = ");
	Print(product2);
	Print();
	cout << "x.operator+(y) = "; Print(x + y);
	cout << "x.operator+(y) = "; Print(x.operator+(y));
	cout << "x++ = "; Print(x++);
	system("pause");

	return 0;
}