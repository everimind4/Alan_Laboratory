#include <iostream>

#define CAPACITY 15	// nodeÀÇ ÃÑ¼ö

using namespace std;

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
}NODE, *LPNODE;

class MyBinaryTree {
	NODE nodes[CAPACITY + 1];
public:
	void Build();
	void Display(int);
	void preorder(LPNODE);
	void inorder(LPNODE);
	void postorder(LPNODE);
};

void MyBinaryTree::Build()
{
	for (int i = 1; i <= CAPACITY; i++)
	{
		nodes[i].data = 'A' + i - 1;
		nodes[i].left = NULL;
		nodes[i].right = NULL;
	}
	for (int i = 2; i <= CAPACITY; i++)
	{
		if (i % 2 == 0)
		{
			nodes[i / 2].left = &nodes[i];
		}
		else
		{
			nodes[i / 2].right = &nodes[i];
		}
	}
}

void MyBinaryTree::Display(int type)
{
	switch (type) {
	case 0: MyBinaryTree::preorder(&nodes[1]);
		break;
	case 1: MyBinaryTree::inorder(&nodes[1]);
		break;
	case 2: MyBinaryTree::postorder(&nodes[1]);
		break;
	default: cout << "Wrong number." << endl;
	}
}

void MyBinaryTree::preorder(LPNODE ptr)
{
	if (ptr)
	{
		cout << char(ptr->data) << ' ';
		MyBinaryTree::preorder(ptr->left);
		MyBinaryTree::preorder(ptr->right);
	}
}

void MyBinaryTree::inorder(LPNODE ptr)
{
	if (ptr)
	{
		MyBinaryTree::inorder(ptr->left);
		cout << char(ptr->data) << ' ';
		MyBinaryTree::inorder(ptr->right);
	}
}

void MyBinaryTree::postorder(LPNODE ptr)
{
	if (ptr)
	{
		MyBinaryTree::postorder(ptr->left);
		MyBinaryTree::postorder(ptr->right);
		cout << char(ptr->data) << ' ';
	}
}

int main()
{
	MyBinaryTree mbt;
	mbt.Build();
	mbt.Display(1);
}

