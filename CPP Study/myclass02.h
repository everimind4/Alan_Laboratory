#include <list>
#include <map>
#include <iostream>
#include <time.h>

using namespace std;

class myclass02 {
	std::list<int> tlist;
	std::map<int, int> tmap;
public:
	void SetData(int count);
	void DisplayList();
	void DisplayMap();
};

void myclass02::SetData(int count)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < count; i++)
	{
		int value = rand() % 101;
		tlist.push_back(value);
		tmap.insert(make_pair(i + 1, value));
	}		
}

void myclass02::DisplayList()
{
	cout << "List" << endl << endl;
	// list의 원소가 0개가 될 때까지 front 출력 후 pop 반복
	/*while (!tlist.empty()) 
	{
		cout << tlist.front() << endl;
		tlist.pop_front();
	}*/
	list<int>::iterator iter;
	for (iter = tlist.begin(); iter != tlist.end(); iter++)
		cout << *iter << ' ';
	cout << endl << endl;
}

void myclass02::DisplayMap()
{
	cout << "Map" << endl << endl;
	map<int, int>::iterator iter;
	for (iter = tmap.begin(); iter != tmap.end(); iter++)
		cout << "(" << iter->first << ", " << iter->second << ")" << endl;
	cout << endl;
}


