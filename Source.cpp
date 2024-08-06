#include <stdio.h>
//#include <stdint.h>
//#include <string>

int main()
{
	int i, *p;
	//int *p;

	i = 43;
	p = &i;

	printf("%d %d\n", i, *p);

	//return 0;
}