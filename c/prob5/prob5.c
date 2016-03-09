#include <stdio.h>
#include <stdlib.h>
static unsigned int lcm(unsigned int a, unsigned int b)
{
	int c, t;

	if (a < b) { c = a; a = b; b = c; }

	if (b > 1 && a % b == 0) return b;

	c = 1;
	t = a;

	for (;a % b != 0;c++)
		a = t * c;

	return a;
}

static unsigned int evenly_divisible_by(int limit)
{
	int i;
	unsigned int ans = 1, l;

	for (i = 1; i <= limit; i++) {
		l = lcm(ans, i);
		ans = (l < ans) ? ans : l;
	}

	return ans;
}

int main(int argc, char *argv[])
{
	int limit;

	if (argc != 2) return -1;

	limit = atoi(argv[1]);

	if (limit)
		printf("ans = %u\n", evenly_divisible_by(limit));
	else
		printf("Invalid input value\n");

	return 0;
}
