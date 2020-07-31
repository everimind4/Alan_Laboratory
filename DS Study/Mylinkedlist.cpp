#include "Mylinkedlist.h"

using namespace std;

int main()
{
	MyLinkedList ll;

	ll.Add(0, "John", 2000, 1, 1);
	ll.Add(1, "Mike", 2010, 10, 10);
	ll.Add(2, "Tom", 2011, 10, 11);
	ll.Add(3, "Jake", 2012, 10, 12);
	ll.Add(4, "Lee", 2013, 10, 13);
	ll.Display();
	/*	ll.Insert(1, 10, "Kim", 2019, 9, 1);
	ll.Display();
	ll.Delete();
	ll.Display();*/

	return 0;
}