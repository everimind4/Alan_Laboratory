#include <iostream>
#include <vector>
using namespace std;

class PatternMatch {
protected:
	virtual int patternmatch(const char*, const char*) = 0;
	virtual int getType() = 0;
};

class Brutal_Force : public PatternMatch {
public:
	int patternmatch(const char*, const char*);
	int getType() { return 0; }
};

class Boyer_Moore : public PatternMatch {
public:
	vector<int> buildLastFunction(const char*);
	int patternmatch(const char*, const char*);
	int getType() { return 1; }
};

int Brutal_Force::patternmatch(const char* pText, const char* pPtrn)
{
	int lenText = (int)strlen(pText);
	int lenPtrn = (int)strlen(pPtrn);
	if (lenText < lenPtrn)
		return -1;
	for (int i = 0; i < lenText; i++)
	{
		int j = 0;
		while (pText[i + j] == pPtrn[j])
		{
			j++;
			if (j == lenPtrn)
				cout << "Find at idx #" << i << endl;
		}
	}
	return -1;
}

vector<int> Boyer_Moore::buildLastFunction(const char* pPtrn)
{
	int lenPtrn = (int)strlen(pPtrn);

	const int N_ASCII = 128;
	vector<int> last(N_ASCII);
	for (int i = 0; i < N_ASCII; i++)
		last[i] = -1;
	for (int i = 0; i < lenPtrn; i++)
		last[pPtrn[i]] = i;
	return last;
}

int Boyer_Moore::patternmatch(const char* pText, const char* pPtrn)
{
	int lenText = (int)strlen(pText);
	int lenPtrn = (int)strlen(pPtrn);

	vector<int> last = buildLastFunction(pPtrn);
	int i = lenPtrn - 1;
	if (lenText - 1 < i)
		return -1;

	int j = lenPtrn - 1;
	do {
		if (pPtrn[j] == pText[i])
			if (j == 0)
				cout << "Find at idx #" << i << endl;
			else {
				i--; j--;
				continue;
			}
			i = i + lenPtrn - min(j, 1 + last[pText[i]]);
			j = lenPtrn - 1;
	} while (i <= lenText - 1);
	return -1;
}

void main()
{
	/*Brutal_Force bf;
	bf.patternmatch("aaabbababaaabababaaa", "aba");*/
	Boyer_Moore bm;
	bm.patternmatch("aababbaaabaaabaaaa", "aba");
}