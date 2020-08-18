#include <iostream>

using namespace std;

class Person {
	int pnumber;
	int* ref;
public:
	Person(int n) : pnumber(n), ref(&pnumber) {}
	~Person() { delete ref; }
	friend istream& operator >> (istream&, Person&);
	friend ostream& operator << (ostream&, Person&);
};

class Students {
	Person men;
	Person women;
public:
	Students(int m = 0, int w = 0) : men(m), women(w) {}
	friend istream& operator >> (istream&, Students&);
	friend ostream& operator << (ostream&, Students&);
};

istream& operator >> (istream& i, Person& p)
{
	i >> p.pnumber;
	p.ref = new int(p.pnumber);
	return i;
}

ostream& operator << (ostream& o, Person& p)
{
	o << p.pnumber << endl << "This number is stored at " << p.ref << endl;
	return o;
}

istream& operator >> (istream& i, Students& s)
{
	cout << "Enter a men number : ";		i >> s.men;
	cout << "Enter a women number : ";	i >> s.women;
	return i;
}

ostream& operator << (ostream& o, Students& s)
{
	o << endl	<< "The men number : "		<< s.men << endl;
	o				<< "The women number : "	<< s.women;
	return o;
}


void main()
{
	Students s;
	cin >> s;
	cout << s;
}