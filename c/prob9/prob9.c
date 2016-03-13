#include <stdio.h>

/* Source: http://www.friesian.com/pythag.htm - Very nice read, indeed */

int is_triplet_valid(int m)
{
	int a, b, c, n;
	if((500 - (m*m)) % m == 0) {
		n = (500 - (m*m))/m;
		if (n > m) return 0;
	}
	else
		return 0;
	a = m*m - n*n;
	b = 2*m*n;
	c = m*m + n*n;
	if (a+b+c == 1000)
		printf("ans:%d\n", a*b*c);
	else
		return 0;
}

int main()
{
	int m;
	for (m = 3; !is_triplet_valid(m); m++)
		;
	return 0;
}
