#include <iostream>

using namespace std;

class Contact {
public:
	Contact();
	string name;
	string mobile_tel;
	string office_tel;
	string home_tel;
	string e_mail;
	string birth;
	Contact* next;
};

class HashTable {
	int BucketSize;
public:
	Contact** bucket;
	HashTable() : BucketSize(0), bucket(NULL) {}
	HashTable(int);
	int F_Hash(int);
	void GetData();
	void SaveData(char*, size_t);	
	void Insert(string, string, string, string, string, string);
	void DisplayContact(Contact*);
	void Display();
};