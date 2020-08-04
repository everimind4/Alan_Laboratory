#include <iostream>

#define CAPACITY 15	// nodeÀÇ ÃÑ¼ö

using namespace std;

class MyBinaryTree {
	int data;
public:
	MyBinaryTree* left;
	MyBinaryTree* right;
	void GetData(int);	
	void preorder(MyBinaryTree*);
	void inorder(MyBinaryTree*);
	void postorder(MyBinaryTree*);
};

void MyBinaryTree::GetData(int element)
{

}

void MyBinaryTree::preorder(MyBinaryTree* ptr)
{

}

void MyBinaryTree::inorder(MyBinaryTree* ptr)
{

}

void MyBinaryTree::postorder(MyBinaryTree* ptr)
{

}

int main()
{
	MyBinaryTree nodes[CAPACITY + 1];
	for (int i = 1; i <= CAPACITY; i++)
	{
		nodes[i].GetData('A' + i - 1);
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
	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
	cout << endl;
}

