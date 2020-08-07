#include <iostream>

using namespace std;

class Complex {
	float real;
	float imag;
public:
	Complex(float r = 0.0, float i = 0.0) : real(r), imag(i) {}
};

class Triplet {
	Complex one;
	Complex two;
	Complex* three;
public:
	Triplet();
	~Triplet();
	Triplet(const Triplet&);
	void operator=(const Triplet&);
};

Triplet PrintTriplet(Triplet t)
{
	return t;
}

Triplet::Triplet()
{
	three = new Complex;
	cout << "Default Constructor called." << endl;
}

Triplet::~Triplet()
{
	delete three;
	cout << "Triplet Destructor called." << endl;
}

Triplet::Triplet(const Triplet& src)
{
	one = src.one;
	two = src.two;
	three = new Complex;
	*three = *src.three;
	cout << "Copy Constructor called." << endl;
}

void Triplet::operator=(const Triplet& src)
{
	one = src.one;
	two = src.two;
	three = new Complex;
	*three = *src.three;
	cout << "Assign operator called." << endl;
}

void main()
{
	Triplet t1;
	Triplet t2 = t1;
	Triplet t3 = PrintTriplet(t1);
	t2 = PrintTriplet(t3);
}