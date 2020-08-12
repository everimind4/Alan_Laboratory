// SW코딩 역량을 위한 C++ 프로그래밍 (정익사) 6장 프로그래밍 과제 6번
// (1) 입출력연산자 오버로딩

#include <iostream>

using namespace std;

class Note {
	class NoteImpl* nl;
public:
	Note(int, int);
	~Note();
	void Sound();
	void Increase(int);
	void Modulate(int);
	friend istream& operator >> (istream&, Note&);
	friend ostream& operator << (ostream&, Note&);
	Note& operator++();
	Note& operator++()int;
};

class NoteImpl {
	friend Note;
	int pitch;
	int duration;
	NoteImpl(int p, int d) : pitch(p), duration(d) {}
	void Sound();
public:
	void PutP(int);
	void PutD(int);
	int GetP();
	int GetD();
};

istream& operator >> (istream& in, Note& note)
{
	int p_temp = 0, d_temp = 0;
	in >> p_temp;
	in >> d_temp;
	note.nl->PutP(p_temp);
	note.nl->PutD(d_temp);
	return in;
}

ostream& operator << (ostream& out, Note& note)
{
	out << "Pitch : " << note.nl->GetP() << endl << "Duration : " << note.nl->GetD() << endl;
	return out;
}

Note::Note(int pitch = 0, int duration = 0)
{
	nl = new NoteImpl(pitch, duration);
}

Note::~Note()
{
	delete nl;
}

void Note::Sound()
{
	nl->Sound();
}

void Note::Increase(int delta)
{
	nl->pitch += delta;
}

void Note::Modulate(int cycles)
{
	for (int i = 1; i <= cycles; i++)
	{
		nl->pitch++;
		nl->duration = 1 + i % 2;
		nl->Sound();
	}
}

void NoteImpl::Sound()
{
	cout << "Sound() : pitch = " << pitch << ", duration = " << duration << endl;
}

void NoteImpl::PutP(int input)
{
	pitch = input;
}
void NoteImpl::PutD(int input)
{
	duration = input;
}

int NoteImpl::GetP()
{
	return pitch;
}

int NoteImpl::GetD()
{
	return duration;
}

void main()
{
	Note n;

	cout << "Please enter pitch and duration . . ." << endl;
	cin >> n;
	cout << n;
}

// 1. NoteImpl 클래스의 멤버 변수에 접근이 가능한 Sound 함수를 이용해 출력
// 2. NoteImpl 클래스에 대한 연산자 오버로딩 함수를 추가로 정의해 2단계로 오버로딩하여 구현 ★ 문제 의도와 가장 잘 일치하는 방법
// 3. NoteImpl 클래스의 메소드를 정의해 해당 메소드로 클래스 멤버에 접근