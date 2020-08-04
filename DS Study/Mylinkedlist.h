#include <iostream>
#include <string>

using namespace std;

typedef struct _tnode {
	int id;
	string name;
	int year, month, day;
	struct _tnode* next;
} TNODE;

class MyLinkedList {
	TNODE* head;
public:
	MyLinkedList();
	~MyLinkedList();	
	void Add(TNODE*);
	void Add(int, string, int, int, int);
	void Insert(int, int, string, int, int, int);
	void Display();
	void Delete(int);
	void Search(int);	
};
	
MyLinkedList::MyLinkedList()
{
	head = NULL;
}

MyLinkedList::~MyLinkedList()
{
	// delete
}

void MyLinkedList::Add(TNODE* node)
{
	if (head == NULL)
		head = node;
	else
	{
		TNODE* temp = head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = node;
	}
}

void MyLinkedList::Add(int id, string name, int year, int month, int day)
{
	TNODE* _new = new TNODE;
	_new->id = id;
	_new->name = name;
	_new->year = year;
	_new->month = month;
	_new->day = day;
	_new->next = NULL;
	Add(_new);
}

void MyLinkedList::Insert(int i_id, int id, string name, int year, int month, int day)
{
	TNODE* temp = head;
	while (temp->id != i_id)
	{
		if (temp->next == NULL && temp->id != i_id)
		{
			cout << "The id '" << i_id << "', the location you want to add does not exist in the list." << endl << endl;
			return;
		}
		temp = temp->next;
	}
		
	TNODE* _insert = new TNODE;
	_insert->id = id;
	_insert->name = name;
	_insert->year = year;
	_insert->month = month;
	_insert->day = day;
	_insert->next = temp->next;
	temp->next = _insert;
}

void MyLinkedList::Display()
{
	if (head == NULL)
		cout << "There is no elements." << endl;
	else
	{
		TNODE* temp = head;
		while (temp)
		{
			cout << temp->id << '-' << temp->name << '-' << temp->year << '.' << temp->month << '.' << temp->day << endl;
			temp = temp->next;
		}
	}
	cout << endl;
}

void MyLinkedList::Delete(int id)
{
	TNODE* temp = head;
	while (temp->next->id - id)
		temp = temp->next;
	temp->next = temp->next->next;
}

void MyLinkedList::Search(int id)
{
	TNODE* temp = head;
	while (temp->id - id)
	{
		if (temp->next == NULL && temp->id - id)
		{
			cout << "The node for that id does not found." << endl << endl;
			return;
		}
		temp = temp->next;
	}		
	cout << temp->id << '-' << temp->name << '-' << temp->year << '.' << temp->month << '.' << temp->day << endl << endl;
}