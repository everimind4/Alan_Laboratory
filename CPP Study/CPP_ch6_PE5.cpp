// SW코딩 역량을 위한 C++ 프로그래밍 (정익사) 6장 연습문제 5번
// 연산자 (함수) 오버로딩 실습

#include <iostream>

using namespace std;

class PointerClass {
	int number;
	int* pointer;
public:
	PointerClass() : number(0), pointer(NULL) {}
	friend istream& operator >> (istream& in, PointerClass& pc);
	friend ostream& operator << (ostream& out, PointerClass& pc);
};

istream& operator >> (istream& in, PointerClass& pc)
{
	in >> pc.number;
	pc.pointer = &pc.number;
	return in;
}

ostream& operator << (ostream& out, PointerClass& pc)
{
	out << pc.number << " at " << pc.pointer;
	return out;
}

void main() {
	PointerClass p;
	cout << "input an object . . ." << endl;
	cin >> p;
	cout << "You have input an object " << p;
}