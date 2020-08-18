#include <iostream>
#define MAXNUM 20

using namespace std;

class Complex {
	friend class Stack;
	int real;
	int imag;
public:
	Complex(int r = NULL, int i = NULL) : real(r), imag(i) {}
	friend istream& operator >> (istream&, Complex&);
	friend ostream& operator << (ostream&, Complex&);
};

class Stack {
	Complex line[MAXNUM];
	int num;
public:
	Stack(int n = 0) : num(n) {}
	void Push(Complex);
	Complex Pop();
	friend ostream& operator << (ostream&, Stack&);
};

void Stack::Push(Complex complex)
{
	if (num == MAXNUM)
	{
		cout << "Stack is full! " << complex << " was not stored in stack." << endl;
		return;
	}		
	line[num++] = complex;
}

Complex Stack::Pop()
{
	if (num == 0)
	{
		cout << "Stack is empty!" << endl;
		return line[num];
	}
	Complex temp(line[--num].real, line[num].imag);
	return temp;
}

istream& operator >> (istream& i, Complex& c)
{
	cout << "Enter a integer for real part and imaginary part of complex number." << endl;
	cout << "Real : ";		i >> c.real;
	cout << "Imaginary : ";	i >> c.imag;
	return i;
}

ostream& operator << (ostream& o, Complex& c)
{
	o << c.real << " + " << c.imag << "i";
	return o;
}

ostream& operator << (ostream& o, Stack& s)
{
	for (int i = 0; i < s.num; i++)
	{
		o << "#"; printf("%2d", i + 1); o << " : " << s.line[i] << endl;
	}		
	return o;
}

void main()
{
	Stack s;
	s.Pop();
	Complex c1(1, 2);
	Complex c2(3, 4);
	Complex c3;
	cin >> c3;
	cout << c3 << endl;
	s.Push(c1);
	s.Push(c2);
	for (int i = 0; i < MAXNUM; i++)
		s.Push(c3);
	cout << s << endl;
	s.Pop();
	cout << s << endl;
	Complex c4(4, 5);
	s.Push(c4);
	cout << s << endl;
	s.Pop();
	cout << s;
}