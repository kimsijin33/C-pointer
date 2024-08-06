#include <stdio.h>
#include <string.h>

int	main()
{
	int i, *p;
	i = 43;
	p = &i;

	*p = 16;
	printf("%d\n", i);
}
