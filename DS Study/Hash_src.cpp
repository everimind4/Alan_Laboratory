#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

void main()
{
	MyHash mh(10);

	if (mh.get() == NULL) return;

	mh.hash_insert(10, "全辨悼", 2000, 1, 1);
	mh.hash_insert(11, "全老悼", 2000, 1, 1);
	mh.hash_insert(12, "全捞悼", 2000, 1, 1);
	mh.hash_insert(13, "全伙悼", 2000, 1, 1);
	mh.hash_insert(14, "全荤悼", 2000, 1, 1);
	mh.hash_insert(15, "全坷悼", 2000, 1, 1);
	mh.hash_insert(21, "辫老悼", 2000, 1, 1);
	mh.hash_insert(31, "捞老悼", 2000, 1, 1);

	mh.hash_display();

	printf("search node : 15\n");
	NODE* t = mh.hash_search(15);
	if (t != NULL)
		mh.hash_displaynode(t);
	else
		printf("\tnot found node\n");

}