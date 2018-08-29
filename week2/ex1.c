#include"stdio.h"
#include "limits.h"
#include"float.h"
int a;
float b;
double c;
int main()
{
	a = INT_MAX;
	b = FLT_MAX;
	c = DBL_MAX;
	printf("%d %ld\n%f %ld\n%f %ld", a, sizeof(a), b, sizeof(b), c, sizeof(c));
	return 0;
}

