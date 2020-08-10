#include <string>

using namespace std;

class NODE
{
public:
    NODE() : id(0), name(""), year(0), month(0), day(0), next(NULL) {}
    int id;
    string name;
    int year, month, day;
    NODE* next;
};

class MyHash
{
    int BucketSize;
public:
    NODE** bucket;
    MyHash() : BucketSize(0), bucket(NULL) {}
    MyHash(int);
    ~MyHash();
    NODE** get();
    int hash_func(int);
    void hash_insert(int, string, int, int, int);
    // void hash_delete(int); 노드 하나만 지우는 메소드 구현하기
    void hash_displaynode(NODE* t);
    void hash_display();
    NODE* hash_search(int);
};