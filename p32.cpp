#include <stdio.h>

// int, long, char µÊ, double , long long¿¡·¯
int main()
{
	int x;
	double y;
	long z;

	x = 34;
	y = 3712.8876;
	z = 123000;

	printf("%u %u %u\n", &x, &y, &z);
}