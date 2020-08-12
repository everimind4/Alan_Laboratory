// SW코딩 역량을 위한 C++ 프로그래밍 (정익사) 6장 프로그래밍 과제 6번
// (1) 입출력연산자 오버로딩

#include <iostream>

using namespace std;

class Note {
	class NoteImpl* ni;
public:
	Note(int, int);
	Note(const Note&); // (2)-1 복사생성자
	~Note();
	void Sound();
	void Increase(int);
	void Modulate(int);
	friend istream& operator >> (istream&, Note&);
	friend ostream& operator << (ostream&, Note&);
	Note& operator++();
	Note& operator++(int);
	void operator=(Note&); // (2)-2 대입연산자 오버로딩
};

class NoteImpl {
	friend Note;
	int pitch;
	int duration;
	NoteImpl(int p, int d) : pitch(p), duration(d) {}
	void Sound();
public:
	// (1)-3 : NoteImpl의 멤버 변수에 접근 가능해 입출력이 가능한 메소드 함수들
	/*void PutP(int);
	void PutD(int);
	int GetP();
	int GetD();*/
	friend istream& operator >> (istream&, NoteImpl&);
	friend ostream& operator << (ostream&, NoteImpl&);
};

istream& operator >> (istream& in, Note& note)
{
	// (1)-3
	/*int p_temp = 0, d_temp = 0;
	in >> p_temp >> d_temp;
	note.ni->PutP(p_temp);
	note.ni->PutD(d_temp);*/
	cin >> *(note.ni);
	return in;
}

ostream& operator << (ostream& out, Note& note)
{
	// (1)-3
	// out << "Pitch : " << note.ni->GetP() << endl << "Duration : " << note.ni->GetD() << endl;
	cout << *(note.ni) << endl;
	return out;
}

istream& operator >> (istream& in, NoteImpl& n)
{
	int p_temp = 0, d_temp = 0;
	in >> p_temp >> d_temp;
	n.pitch = p_temp;
	n.duration = d_temp;
	return in;
}

ostream& operator << (ostream& out, NoteImpl& n)
{
	out << "Pitch : " << n.pitch << endl << "Duration : " << n.duration << endl;
	return out;
}

Note& Note::operator++() // Prefix
{
	ni->pitch++;
	return *this;
}

Note& Note::operator++(int) // Postfix
{
	ni->duration++;
	return *this;
}

Note::Note(int pitch = 0, int duration = 0)
{
	ni = new NoteImpl(pitch, duration);
}

// (2)-1
Note::Note(const Note& src)
{
	ni = new NoteImpl(0, 0);
	*ni = *(src.ni);
	cout << "Copy constructor called." << endl;
}

Note::~Note()
{
	delete ni;
}

void Note::Sound()
{
	ni->Sound();
}

void Note::Increase(int delta)
{
	ni->pitch += delta;
}

void Note::Modulate(int cycles)
{
	for (int i = 1; i <= cycles; i++)
	{
		ni->pitch++;
		ni->duration = 1 + i % 2;
		ni->Sound();
	}
}

void NoteImpl::Sound()
{
	cout << "Sound : pitch = " << pitch << ", duration = " << duration << endl;
}

// (2)-2 대입연산자 오버로딩
void Note::operator=(Note& n)
{
	ni->pitch = n.ni->pitch;
	ni->duration = n.ni->duration;
	cout << "Assign operator overloaded." << endl;
}

// (1)-3
//void NoteImpl::PutP(int input)
//{
//	pitch = input;
//}
//void NoteImpl::PutD(int input)
//{
//	duration = input;
//}
//
//int NoteImpl::GetP()
//{
//	return pitch;
//}
//
//int NoteImpl::GetD()
//{
//	return duration;
//}

int main()
{
	Note n;

	cout << "Please enter pitch and duration." << endl;
	cin >> n;
	cout << n;
	++n;
	cout << n;
	n++; 
	cout << n;

	Note n1 = n;
	cout << n1;
	Note n2;
	n2 = n;
	cout << n2;

	n.Increase(5);
	n.Modulate(3);

	return 0;
}

// (1) NoteImpl 클래스 입출력 연산자 오버로딩
// (1)-1. NoteImpl 클래스의 멤버 변수에 접근이 가능한 Sound 함수를 이용해 출력
// (1)-2. NoteImpl 클래스에 대한 연산자 오버로딩 함수를 추가로 정의해 NoteImpl 클래스에서 1번, Note 클래스에서 1번, 총 2번 오버로딩하여 구현 ★ 문제 의도와 가장 잘 일치하는 방법
// (1)-3. NoteImpl 클래스의 메소드를 정의해 해당 메소드로 클래스 멤버에 접근

// (2) 복사생성자, 치환연산자 구현