// SW코딩 역량을 위한 C++ 프로그래밍 (정익사) 6장 연습문제 5번 코드를 활용
// 복사 생성자 실습

#include <iostream>

using namespace std;

class PointerClass {
	int number;
	int* pointer;
public:
	PointerClass();
	PointerClass(const PointerClass&);
	~PointerClass();
	void operator = (const PointerClass&);
	friend istream& operator >> (istream& in, PointerClass& pc);
	friend ostream& operator << (ostream& out, PointerClass& pc);
};

PointerClass::PointerClass()
{
	number = 0;
	pointer = new int(number);
}

PointerClass::PointerClass(const PointerClass& src)
{
	number = src.number;
	pointer = new int(number);
	cout << "Copy Constructor called" << endl;
}

PointerClass::~PointerClass()
{
	delete pointer;
	cout << "deletion complete" << endl;
}

void PointerClass::operator = (const PointerClass& src)
{
	number = src.number;
	pointer = new int(number); // 이 공간은 어떻게 지우는가?
}

istream& operator >> (istream& in, PointerClass& pc)
{
	in >> pc.number;
	return in;
}

ostream& operator << (ostream& out, PointerClass& pc)
{
	out << "You have input an object " << pc.number << " at " << pc.pointer;
	return out;
}

void main() {
	PointerClass p;
	cout << "input an object . . ." << endl;
	cin >> p;
	cout << p << endl;

	PointerClass p1 = p;
	cout << p1 << endl;

	p1 = p;
	cout << p1 << endl;
}