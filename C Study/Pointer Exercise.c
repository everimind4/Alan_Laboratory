#include <stdio.h>

void main()
{
	int a[10] = { 0,1,2,9,0,0,0,0,0,15 };
	int(*p)[3] = &a;
	printf("%d\n", *((*p) + 0));
	printf("%d\n", p[0][1]);
	printf("%d\n", *((*p) + 2));

	printf("%d\n", *(*(p + 3)));
	printf("%d\n", *((*p) + 3));

	/*

	printf("%p\n", &a);
	printf("%p\n", a);
	printf("%d\n", *a);
	printf("%p\n", p[0]);
	printf("%p\n", p[1]);
	printf("%p", p[2]);*/
}