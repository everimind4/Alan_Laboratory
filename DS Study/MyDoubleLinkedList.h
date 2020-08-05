#include <iostream>
#include <string>

using namespace std;

typedef struct _dnode {
	int id;
	string name;
	int year, month, day;
	struct _dnode* prev;
	struct _dnode* next;
}DNODE;

class MyDoubleLinkedList {
	DNODE* head;
	void AddF(DNODE* node);
	void AddB(DNODE* node);
public:
	MyDoubleLinkedList();
	~MyDoubleLinkedList();
	void AddF(int, string, int, int, int);
	void AddB(int, string, int, int, int);
	void Insert(int, int, string, int, int, int);
	void Delete(int);
	void Search(int);
	void DisplayF();
	void DisplayB();
};

MyDoubleLinkedList::MyDoubleLinkedList()
{
	head = nullptr;
}

MyDoubleLinkedList::~MyDoubleLinkedList()
{
	delete head;
}

void MyDoubleLinkedList::AddF(DNODE* node)
{
	if (head == nullptr)
	{
		head = node;
		head->prev = nullptr;
		head->next = nullptr;
	}		
	else
	{
		DNODE* temp = head;
		while (temp->prev != nullptr)
			temp = temp->prev;
		temp->prev = node;
		node->prev = nullptr;
		node->next = temp;
	}
}

void MyDoubleLinkedList::AddB(DNODE* node)
{
	if (head == nullptr)
	{
		head = node;
		head->prev = nullptr;
		head->next = nullptr;
	}
	else
	{
		DNODE* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = node;
		node->next = nullptr;
		node->prev = temp;
	}
}

void MyDoubleLinkedList::AddF(int id, string name, int year, int month, int day)
{
	DNODE* _addf = new DNODE;
	_addf->id = id;
	_addf->name = name;
	_addf->year = year;
	_addf->month = month;
	_addf->day = day;
	AddF(_addf);
}

void MyDoubleLinkedList::AddB(int id, string name, int year, int month, int day)
{
	DNODE* _addb = new DNODE;
	_addb->id = id;
	_addb->name = name;
	_addb->year = year;
	_addb->month = month;
	_addb->day = day;
	AddB(_addb);
}

void MyDoubleLinkedList::Insert(int i_id, int id, string name, int year, int month, int day)
{
	DNODE* temp = head;
	while (temp->prev != nullptr && temp->id != i_id)
		temp = temp->prev;
	if (temp->prev == nullptr)
	{
		temp = head;
		while (temp->id != i_id)
		{
			if (temp->next == NULL && temp->id != i_id)
			{
				cout << "The id '" << i_id << "', the location you want to add does not exist in the list." << endl << endl;
				return;
			}
			temp = temp->next;
		}
			
	}
	DNODE* _insert = new DNODE;
	_insert->id = id;
	_insert->name = name;
	_insert->year = year;
	_insert->month = month;
	_insert->day = day;
	_insert->prev = temp;
	_insert->next = temp->next;
	if (temp->next)
		(temp->next)->prev = _insert;
	temp->next = _insert;
}

void MyDoubleLinkedList::Delete(int id)
{
	DNODE* temp = head;
	while (temp->prev != nullptr && temp->id != id)
		temp = temp->prev;
	if (temp->prev == nullptr)
	{
		temp = head;
		while (temp->next != nullptr && temp->id != id)
			temp = temp->next;
	}
		
	if (temp->prev == nullptr && temp->next)
		temp->next->prev = nullptr;
	else if (temp->next == nullptr && temp->prev)
		temp->prev->next = nullptr;
	else if (temp->next && temp->prev)
	{
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
	}
}

void MyDoubleLinkedList::Search(int id)
{
	DNODE* temp = head;
	while (temp->prev != nullptr && temp->id != id)
		temp = temp->prev;
	if (temp->prev == nullptr)
	{
		temp = head;
		while (temp->next != nullptr && temp->id != id)
			temp = temp->next;
	}
	if (temp->next == nullptr && temp->id != id)
	{
		cout << "The node for that id does not found." << endl << endl;
		return;
	}
	cout << temp->id << '-' << temp->name << '-' << temp->year << '.' << temp->month << '.' << temp->day << endl << endl;
}

void MyDoubleLinkedList::DisplayF()
{
	DNODE* temp = head;
	while (temp->prev != nullptr)
		temp = temp->prev;
	while (temp != nullptr)
	{
		cout << temp->id << '-' << temp->name << '-' << temp->year << '.' << temp->month << '.' << temp->day << endl;
		temp = temp->next;
	}
	cout << endl;
}

void MyDoubleLinkedList::DisplayB()
{
	DNODE* temp = head;
	while (temp->next != nullptr)
		temp = temp->next;
	while (temp != nullptr)
	{
		cout << temp->id << '-' << temp->name << '-' << temp->year << '.' << temp->month << '.' << temp->day << endl;
		temp = temp->prev;
	}
	cout << endl;
}