#include <iostream>
using namespace std;

class Test {
	int 		value;       	// value of the object
	int		obj_number;	// number of the object
	static int      last_obj;	// number of the last object
public:
	Test(int n) {
		value = n;
		obj_number = ++last_obj;
		cout << "Standard constructor (object no."
			<< obj_number
			<< ") : value = " << value
			<< endl;
	}
	// copy constructor
	Test(const Test& t) {
		value = t.value;
		obj_number = ++last_obj;
		cout << "Copy constructor (object no."
			<< obj_number
			<< ") : value = " << value
			<< endl;
	}
	~Test() {
		cout << "Destructor (object no."
			<< obj_number << ")"
			<< endl;
	}
	// assignment operator
	Test& operator= (const Test& t) {
		value = t.value;
		cout << "Assignment operator (from object no."
			<< t.obj_number << " to object no." << obj_number
			<< ") : value = " << value
			<< endl;
		return (*this);
	}
	// increment operator
	int operator ++ () {
		return ++value;
	}
};
// external definition of the static member
int Test::last_obj = 0;
// global function printing the increased value
// parameter and return value are passed by copy
Test PrintNext(Test t) {
	cout << "New increased value = " << ++t << endl;
	return t;
}
// main function: creates some objects
void main() {
	cout << "1. New object" << endl;
	Test	t1(25);
	cout << endl;
	cout << "2. New object... copied" << endl;
	Test	t2 = t1;
	cout << endl;
	cout << "3. New object... increased" << endl;
	Test t3 = PrintNext(t1);
	cout << endl;
	cout << "4. Assignment of increased object" << endl;
	t2 = PrintNext(t3);
	cout << endl;
}