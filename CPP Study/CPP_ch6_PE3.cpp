#include <iostream>

using namespace std;

class Person {
	int p;
	char* pname;
public:
	Person(char* name = nullptr) : p(0), pname(name) {}
	friend istream& operator >> (istream&, Person&);
	friend ostream& operator << (ostream&, Person&);
};

class Student {
	int s;
	Person* p;
public:
	Student(char* name = nullptr) : s(0), p(new Person(name)) {}
	friend istream& operator >> (istream&, Student&);
	friend ostream& operator << (ostream&, Student&);
};

istream& operator >> (istream& in, Person& p)
{
	cout << "Please enter a value to assign to person index 'p' : ";
	in >> p.p;
	return in;
}

ostream& operator << (ostream& out, Person& p)
{
	out << "Person index : #" << p.p << endl << "Person name : " << p.pname << endl;
	return out;
}

istream& operator >> (istream& in, Student& s)
{
	cout << "Please enter a value to assign to student number 's' : ";
	in >> s.s >> *(s.p);
	return in;
}

ostream& operator << (ostream& out, Student& s)
{
	out << "Student number : #" << s.s << endl << *(s.p);
	return out;
}

void main()
{
	char name[] = "Alan";
	Student s(name);
	cin >> s;
	cout << s;
	system("pause");
}