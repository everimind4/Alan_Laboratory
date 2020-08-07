// SW�ڵ� ������ ���� C++ ���α׷��� (���ͻ�) 6�� �������� 5�� �ڵ带 Ȱ��
// ���� ������ �ǽ�

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
	pointer = new int(number); // �� ������ ��� ����°�?
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