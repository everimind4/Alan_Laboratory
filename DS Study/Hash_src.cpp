#include "Hash.h"

void main()
{
	MyHash mh(10);

	if (mh.get() == NULL) return;

	mh.hash_insert(10, "È«±æµ¿", 2000, 1, 1);
	mh.hash_insert(11, "È«ÀÏµ¿", 2000, 1, 1);
	mh.hash_insert(12, "È«ÀÌµ¿", 2000, 1, 1);
	mh.hash_insert(13, "È«»ïµ¿", 2000, 1, 1);
	mh.hash_insert(14, "È«»çµ¿", 2000, 1, 1);
	mh.hash_insert(15, "È«¿Àµ¿", 2000, 1, 1);
	mh.hash_insert(21, "±èÀÏµ¿", 2000, 1, 1);
	mh.hash_insert(31, "ÀÌÀÏµ¿", 2000, 1, 1);
	
	mh.hash_display();

	mh.hash_search(15);

	mh.hash_delete(21);
	mh.hash_display();

	mh.hash_delete(27);
	mh.hash_display();
}