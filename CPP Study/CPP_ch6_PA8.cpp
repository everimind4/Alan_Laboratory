#include <iostream>

using namespace std;

class List;

class ListNode {
	friend class List;
	friend istream& operator >>(istream&, ListNode&);
	friend ostream& operator <<(ostream&, ListNode&);
	int data;
	ListNode* link;
public:
	ListNode() : data(0), link(nullptr) {}
	ListNode* Next() {
		return link;
	}
};

class List {
	friend istream& operator >>(istream&, List&);
	friend ostream& operator <<(ostream&, List&);
	ListNode* first;
public:
	List() : first(nullptr) {}
	void Add(ListNode&);
};

void List::Add(ListNode& n)
{
	if (first == nullptr)
	{
		first = new ListNode;
		first->data = n.data;
		first->link = nullptr;
	}
	else
	{
		ListNode* temp = new ListNode;
		temp = first;
		while (temp->Next() != nullptr)
			temp = temp->Next();
		temp->link = &n;
	}
}

istream& operator >>(istream& in, List& list)
{
	int count;
	cout << "How many nodes do you want to add : "; cin >> count;
	cout << endl;
	for (int i = 0; i < count; i++)
	{
		ListNode* temp = new ListNode;
		cout << "Node " << i + 1 << " : ";
		cin >> *temp;
		list.Add(*temp);
	}
	return in;
}

ostream& operator <<(ostream& out, List& list)
{
	if (list.first == nullptr)
	{
		cout << "There is no data stored in the list." << endl;
		return out;
	}
	cout << *(list.first);
	return out;
}

istream& operator >>(istream& in, ListNode& n)
{
	in >> n.data;
	n.link = nullptr;
	return in;
}

ostream& operator <<(ostream& out, ListNode& n)
{
	out << endl << "Nodes : " << n.data << " - ";
	ListNode* temp = n.link;
	while (temp != nullptr)
	{
		out << temp->data << " - ";
		temp = temp->Next();
	}
	out << "END" << endl;
	return out;
}

void main()
{
	List l;

	cin >> l;
	cout << l;
}