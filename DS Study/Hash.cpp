#include <iostream>
#include <cstdlib>
#include <string>
#include "Hash.h"

MyHash::MyHash(int size)
{
    BucketSize = size;
    bucket = (NODE**)new (NODE * [BucketSize]);
    if (bucket == NULL)
    {
        cout << "memory allocation failed!" << endl;
        return;
    }
    for (int i = 0; i < BucketSize; i++)
    {
        bucket[i] = (NODE*) new NODE;
        bucket[i] = NULL;
    }
}

MyHash::~MyHash()
{
    NODE* t, * p;
    for (int i = 0; i < BucketSize; i++)
    {
        t = bucket[i];
        while (t != NULL)
        {
            p = t;
            t = t->next;
            delete p;
        }
    }
    delete[] bucket;
}

NODE** MyHash::get()
{
    if (bucket == NULL)
        return NULL;
    else return bucket;
}

int MyHash::hash_func(int key)
{
    int h = key % BucketSize;
    return h;
}

void MyHash::hash_insert(int _id, string _name, int y, int m, int d)
{
    NODE* t = (NODE*)new NODE;
    t->id = _id;
    t->name = _name;
    t->year = y;
    t->month = m;
    t->day = d;
    t->next = NULL;

    int h = hash_func(t->id);

    if (bucket[h] == NULL)
        bucket[h] = t;
    else
    {
        NODE* n = bucket[h];
        while (n->next != NULL)
            n = n->next;
        n->next = t;
    }
}

void MyHash::hash_displaynode(NODE* t)
{
    cout << '\t' << t->id << ',' << t->name << ',' << t->year << '-' << t->month << '-' << t->day << endl;
}

void MyHash::hash_display()
{
    for (int i = 0; i < BucketSize; i++)
    {
        cout << "Bucket " << i << endl;
        NODE* t = bucket[i];
        while (t != NULL)
        {
            hash_displaynode(t);
            t = t->next;
        }
    }
}

NODE* MyHash::hash_search(int id)
{
    int h = hash_func(id);

    NODE* t = bucket[h];
    while (t != NULL)
    {
        if (t->id == id)
            return t;
        t = t->next;
    }
    return NULL;
}