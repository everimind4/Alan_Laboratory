#define _CRT_SECURE_NO_WARNINGS
#include "ContactManager.h"
#include <vector>

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
	bucket = (Contact**)new (Contact * [BucketSize]);
	if (bucket == NULL)
	{
		cout << "memory allocation failed!" << endl;
		return;
	}
	for (int i = 0; i < BucketSize; i++)
	{
		bucket[i] = (Contact*) new Contact;
		bucket[i] = NULL;
	}
}

int HashTable::F_Hash(int key)
{
	int h = key % BucketSize;
	return h;
}

void HashTable::GetData()
{
	FILE* fp = fopen("contact.txt", "rt");
	if (fp == nullptr)
	{
		printf("Fail to open file!");
		return;
	}
	char fpln[64];
	while (fgets(fpln, 64, fp) != NULL)
	{
		size_t len = strlen(fpln);
		if (fpln[len - 1] == '\n')
			fpln[len - 1] = '\0';
		SaveData(fpln, len);
	}
	fclose(fp);
}

void HashTable::SaveData(char* data, size_t len)
{
	Contact* n = (Contact*)new Contact;
	int i = 0, j = 0, data_idx = 0;
	string s = "";
	vector<string> temp;
	for (i; i < (int)len; i++)
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
	Contact* t = (Contact*)new Contact;
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

void HashTable::DisplayContact(Contact* t)
{
	cout << '\t' << "Name : " << t->name << endl
		<< '\t' << "Mobile : " << t->mobile_tel << endl
		<< '\t' << "Office : " << t->office_tel << endl
		<< '\t' << "Home : " << t->home_tel << endl
		<< '\t' << "E-mail : " << t->e_mail << endl
		<< '\t' << "Birth : " << t->birth << endl << endl;
}

void HashTable::Display()
{
	cout << STAR << endl;
	for (int i = 0; i < BucketSize; i++)
	{
		cout << "Bucket " << i << endl;
		Contact* t = bucket[i];
		while (t != NULL)
		{
			DisplayContact(t);
			t = t->next;
		}
	}
	cout << STAR << endl << endl;
}