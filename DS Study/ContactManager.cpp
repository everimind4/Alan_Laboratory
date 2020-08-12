#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "ContactManager.h"
#include <vector>

using namespace std;

#define STAR "****************************************"

Contact::Contact()
{
	name = "";
	mobile_tel = "";
	office_tel = "";
	home_tel = "";
	e_mail = "";
	birth = "";
	next = NULL;
}

HashTable::HashTable(int size)
{
	BucketSize = size;
	bucket = new Contact*[BucketSize];
	if (bucket == NULL)
	{
		cout << "memory allocation failed!" << endl;
		return;
	}
	for (int i = 0; i < BucketSize; i++)
	{
		bucket[i] = new Contact;
		bucket[i] = NULL;
	}
}

int HashTable::F_Hash(int key)
{
	int h = key % BucketSize;
	return h;
}

void HashTable::Load()
{
	ifstream file;
	ofstream file_backup;
	file.open("contact.txt");
	file_backup.open("contact_backup.txt");
	if (!file.is_open())
	{
		cout << "Fail to open file!" << endl;
		return;
	}
	char fpln[64];
	while (file.peek() != EOF)
	{
		file.getline(fpln, 64);
		size_t len = strlen(fpln);
		file_backup << fpln << endl;
		Save(fpln, len);
	}
	file.close();
	file_backup.close();
	}

void HashTable::Save(char* data, size_t len)
{
	Contact* n = new Contact;
	int  data_idx = 0;
	string s = "";
	vector<string> temp;
	for (int i = 0; i < (int)len + 1; i++)
	{
		if (data[i] != ',' && data[i] != '\0')
		{
			s += data[i];
			continue;
		}
		else
			temp.push_back(s);
		s = "";
	}
	n->name = temp[0];
	n->mobile_tel = temp[1];
	n->office_tel = temp[2];
	n->home_tel = temp[3];
	n->e_mail = temp[4];
	n->birth = temp[5];
	n->next = NULL;
	temp.clear();
	int key = 0;
	for (int i = 0; i < (int)(n->name).size(); i++)
		key += n->name[i];
	int h = F_Hash(key);
	if (bucket[h] == NULL)
		bucket[h] = n;
	else
	{
		Contact* t = bucket[h];
		while (t->next != NULL)
			t = t->next;
		t->next = n;
	}
}

void HashTable::Insert(string name, string mobile_tel, string office_tel, string home_tel, string e_mail, string birth)
{
	Contact* t = new Contact;
	t->name = name;
	t->mobile_tel = mobile_tel;
	t->office_tel = office_tel;
	t->home_tel = home_tel;
	t->e_mail = e_mail;
	t->birth = birth;
	t->next = NULL;
	int key = 0;
	for (int i = 0; i < (int)(t->name).size(); i++)
		key += t->name[i];
	int h = F_Hash(key);
	if (bucket[h] == NULL)
		bucket[h] = t;
	else
	{
		Contact* n = bucket[h];
		while (n->next != NULL)
			n = n->next;
		n->next = t;
	}
}

void HashTable::Display(Contact* t)
{
	cout << '\t' << "Name   : " << t->name << endl
		<< '\t' << "Mobile : " << t->mobile_tel << endl
		<< '\t' << "Office : " << t->office_tel << endl
		<< '\t' << "Home   : " << t->home_tel << endl
		<< '\t' << "E-mail : " << t->e_mail << endl
		<< '\t' << "Birth  : " << t->birth << endl << endl;
}

void HashTable::DisplayAll()
{
	cout << STAR << endl;
	for (int i = 0; i < BucketSize; i++)
	{
		cout << "Bucket " << i << endl;
		Contact* t = bucket[i];
		while (t != NULL)
		{
			Display(t);
			t = t->next;
		}
	}
	cout << STAR << endl << endl;
}

void HashTable::Sync()
{
	ofstream file;
	file.open("contact.txt");
	if (!file.is_open())
	{
		printf("Fail to open file!");
		return;
	}	
	for (int i = 0; i < BucketSize; i++)
	{
		Contact* t = bucket[i];
		while (t != NULL)
		{
			string contact = t->name + "," + t->mobile_tel + "," + t->office_tel + "," + t->home_tel + "," + t->e_mail + "," + t->birth;
			file << contact << endl;
			t = t->next;
		}
	}
}