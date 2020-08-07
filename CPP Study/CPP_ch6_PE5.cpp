// SW�ڵ� ������ ���� C++ ���α׷��� (���ͻ�) 6�� �������� 5��
// ������ (�Լ�) �����ε� �ǽ�

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