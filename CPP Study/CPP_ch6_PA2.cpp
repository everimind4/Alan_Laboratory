#include <iostream>
#include <string>

using namespace std;

class vector {
public:
	int r;
	int i;
	vector() : r(0), i(0) {}
	vector(int a, int b) {
		r = a; i = b;
	}
	void setv(int x, int y);
	vector operator++() {
		vector t;
		t.r = ++r;
		t.i = ++i;
		return t;
	}
	vector operator++(int) {
		vector t;
		t.r = r++;
		t.i = i++;
		return t;
	}
};
void vector::setv(int x, int y) {
	r = x; i = y;
};
ostream& operator << (ostream& cout, vector a)
{
	cout << a.r << " + " << a.i << "i";
	return cout;

}
int main()
{
	vector v1(1, 2);
	cout << v1 << endl;
	cout << v1++ << endl;
	cout << v1 << endl;
	cout << ++v1 << endl;
	cout << v1 << endl;

	return 0;
}