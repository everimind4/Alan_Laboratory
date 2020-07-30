#include <iostream>
#include <time.h>
using namespace std;

class Poly;

class Term
{
	friend Poly;
	int coef;
	int exp;
};

class Poly
{
	static Term* TermElement;
	static int idx;
	int start, finish;
	int term;
public:
	Poly(int);
	void GetData();
	void ShowData();
	Poly& Add(Poly&);
};

int Poly::idx = 0;
Term* Poly::TermElement = (Term*)new Term[100];

Poly::Poly(int n)
{
	start = idx;
	finish = start + n;
	term = n;
	idx += n;
}

void Poly::GetData()
{
	for (int i = start; i < finish; i++)
	{
		(TermElement + i)->coef = rand() % 9 + 1;
		(TermElement + i)->exp = term - i + start;
	}
}

void Poly::ShowData()
{
	int i;
	for (i = start; i < finish - 2; i++)
	{
		if ((TermElement + i)->coef != 1)
			cout << (TermElement + i)->coef << "x^" << (TermElement + i)->exp - 1 << " + ";
		else
			cout << "x^" << (TermElement + i)->exp - 1 << " + ";
	}
	if ((TermElement + i)->exp - 1 == 1)
		cout << (TermElement + i++)->coef << "x + ";
	cout << (TermElement + i)->coef << endl;

}

Poly& Poly::Add(Poly& p)
{
	if (term == p.term)
	{
		Poly temp(term);
		for (int i = 0; i < finish; i++)
		{
			TermElement[temp.start + i].coef = TermElement[start + i].coef + TermElement[p.start + i].coef;
			// (TermElement + temp.start + i)->coef = (TermElement + start + i)->coef + (TermElement + p.start + i)->coef;
			TermElement[temp.start + i].exp = TermElement[start + i].exp;
		}			
		return temp;
	}
	else if (term > p.term)
	{
		Poly temp(term);
		int i = 0;
		for (i; i < term - p.term; i++)
			TermElement[temp.start + i].coef = TermElement[start + i].coef;
		for (i; i < term; i++)
			TermElement[temp.start + i].coef = TermElement[start + i].coef + TermElement[p.start + i - (term - p.term)].coef;
		for (int j = 0; j < term; j++)
			TermElement[temp.start + j].exp = TermElement[start + j].exp;
		return temp;
	}
	else if (p.term > term)
	{
		Poly temp(p.term);
		int i = 0;
		for (i; i < p.term - term; i++)
			TermElement[temp.start + i].coef = TermElement[p.start + i].coef;
		for (i; i < p.term; i++)
			TermElement[temp.start + i].coef = TermElement[p.start + i].coef + TermElement[start + i - (p.term - term)].coef;
		for (int j = 0; j < p.term; j++)
			TermElement[temp.start + j].exp = TermElement[p.start + j].exp;
		return temp;
	}
	else
		return p;
}

int main()
{
	srand((unsigned int)time(NULL));
	Poly poly1(4);
	poly1.GetData();
	cout << "Poly #1 : ";
	poly1.ShowData();
	Poly poly2(5);
	poly2.GetData();
	cout << "Poly #2 : ";
	poly2.ShowData();
	Poly poly3(5);
	poly3 = poly1.Add(poly2);
	cout << "Poly #3 : ";
	poly3.ShowData();

	getchar();
}