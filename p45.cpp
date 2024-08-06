#include <stdio.h> // printf()
#include <string.h> // strcpy_s()

int main() // p45
{
	char x[9]; // 9 bytes of memory are allocated for x

	strcpy_s(x, "COMPILER"); // strcp() is a function that copies a string to another string

	printf("%u\n", x); // %u is an unsigned integer
	printf("%s\n", x); // %s is a string
	printf("%s\n", &x[0]); //p45
	printf("%s\n", &x[3]); //p46
} // end of main()
