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
	void Insert(TNODE*, TNODE*);
	void Display();
	void Delete(TNODE*);
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

void MyLinkedList::Insert(TNODE* _node, TNODE* node)
{
	

}

void MyLinkedList::Display()
{
	if (head == NULL)
		cout << "There is no elements." << endl;
	else
	{
		TNODE* temp = head;
		while (temp != NULL)
		{
			cout << temp->id << '-' << temp->name << '-' << temp->year << '.' << temp->month << '.' << temp->day << endl;
			temp = temp->next;
		}
	}
}

void MyLinkedList::Delete(TNODE* node)
{

}

void MyLinkedList::Search(int id)
{

}

