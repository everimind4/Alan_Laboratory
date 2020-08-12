#include <iostream>

using namespace std;

class List;

class Node {
	friend class List;
	int data;
	Node* next;
};

class List {
	Node* head = new Node;
	int size;
public:
	List(int data = 0);
	void Add(int);
	void Insert(int, int);
	void Show();
};

List::List(int data)
{
	head->data = data;
	head->next = NULL;
	size = 1;
}

void List::Add(int data)
{
	Node* New = new Node;
	New->data = data;
	New->next = NULL;
	if (head->next == NULL)
		head->next = New;
	else
	{
		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = New;
	}
	size++;
}

void List::Insert(int idx, int data)
{
	if (idx <= 0)
		cout << "Wrong index!" << endl;
	else if (size == idx)
		cout << data << " is not added. Please use the function 'Add' without index number." << endl;
	else if (size < idx)
		cout << "You have entered an index number that is greater than the length of the list." << endl;
	else
	{
		Node* ins = head;
		for (int i = 0; i < idx - 1; i++)
			ins = ins->next;
		Node* n = new Node;
		n->data = data;
		n->next = ins->next;
		ins->next = n;
	}
	size++;
}

void List::Show()
{
	if (head == NULL)
		cout << "There is no element in the list." << endl;
	Node* ShowNode = head;
	while (ShowNode != NULL)
	{
		cout << ShowNode->data << ' ';
		ShowNode = ShowNode->next;
	}
	cout << endl;
}

int main()
{
	List l(7);
	l.Add(3);
	l.Add(5);
	l.Show();
	l.Insert(2, 4);
	l.Show();
	return 0;
}