#include <stdio.h>
#include <string.h>

int main()
{

	char x[9];

	printf("d %d\n", x);
	printf("s %s\n", x);

	strcpy_s(x, "COMPILER");

	printf("%s\n", x);
	printf("x d: %d\n", x);
	printf("x[0] d: %d\n", x[0]);

	x[0] = 66;
	printf("%c\n", x[0]);

	printf("%s\n", &x);
	printf("%s\n", &x[0]);

}