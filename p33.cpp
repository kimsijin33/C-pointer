#include <stdio.h>

// 16비트 프로세서 였을 때 int 2byte
// 64bit 프로세서에서 long 은 8 byte
//https://myblog.opendocs.co.kr/archives/1230
//https://stackoverflow.com/questions/11438794/is-the-size-of-c-int-2-bytes-or-4-bytes

int main()
{
	int x;
	double y;
	long z;

	x = 34;
	y = 3712.8876;
	z = 123000;

	printf("%u %u %u\n", &x, &y, &z);
	printf("%d %d %d\n", sizeof(x), sizeof(y), sizeof(z));

}