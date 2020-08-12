// SW�ڵ� ������ ���� C++ ���α׷��� (���ͻ�) 6�� ���α׷��� ���� 6��
// (1) ����¿����� �����ε�

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

// 1. NoteImpl Ŭ������ ��� ������ ������ ������ Sound �Լ��� �̿��� ���
// 2. NoteImpl Ŭ������ ���� ������ �����ε� �Լ��� �߰��� ������ 2�ܰ�� �����ε��Ͽ� ���� �� ���� �ǵ��� ���� �� ��ġ�ϴ� ���
// 3. NoteImpl Ŭ������ �޼ҵ带 ������ �ش� �޼ҵ�� Ŭ���� ����� ����