#include "Hash.h"

void main()
{
	MyHash mh(10);

	if (mh.get() == NULL) return;

	mh.hash_insert(10, "ȫ�浿", 2000, 1, 1);
	mh.hash_insert(11, "ȫ�ϵ�", 2000, 1, 1);
	mh.hash_insert(12, "ȫ�̵�", 2000, 1, 1);
	mh.hash_insert(13, "ȫ�ﵿ", 2000, 1, 1);
	mh.hash_insert(14, "ȫ�絿", 2000, 1, 1);
	mh.hash_insert(15, "ȫ����", 2000, 1, 1);
	mh.hash_insert(21, "���ϵ�", 2000, 1, 1);
	mh.hash_insert(31, "���ϵ�", 2000, 1, 1);
	
	mh.hash_display();

	mh.hash_search(15);

	mh.hash_delete(21);
	mh.hash_display();

	mh.hash_delete(27);
	mh.hash_display();
}