#include <stdio.h>
#include <stdlib.h>
#define LIMIT	999
static unsigned int reverse(unsigned int x)
{
	unsigned int y = 0;
	while (x > 0) {
		y += x%10;
		x /= 10;
		y *= 10;
	}
	return y/10;
}

static int is_palindrom(unsigned int x)
{
	return x == reverse(x);
}

int main(int argc, char *argv[])
{
	unsigned int i, j, max = 0;
	for (i = LIMIT; i > 100; i--)
		for (j = i; j > 100; j--)
			if (is_palindrom(i*j) && max < i*j)
				max = i*j;

	printf("ans:%u\n", max);
	return 0;
}
