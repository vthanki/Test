#include <stdio.h>

/* Fill arr using following shell command
 * $ cat digits.txt | a.out
 */

int arr[20][20];

enum direction {
	NORTH,
	EAST,
	WEST,
	SOUTH,
	NE,
	NW,
	SE,
	SW,
};

#define PROD(_i, _j, dir) ({						\
	int a = _i, b = _j, x = 4, p = 1;				\
	while (x-- > 0 && (a < 20 && a >= 0) && (b < 20 && b >= 0)) {	\
		p *= arr[a][b];						\
		switch (dir) {						\
		case NORTH:						\
			a--; break;					\
		case SOUTH:						\
			a++; break;					\
		case EAST:						\
			b--; break;					\
		case WEST:						\
			b++; break;					\
		case NE:						\
			a--; b++; break;				\
		case NW:						\
			a--; b--; break;				\
		case SE:						\
			a++; b++; break;				\
		case SW:						\
			a++; b--; break;				\
		}							\
	}								\
	p;							\
})

int find_max_prod(int i, int j)
{
	int prod = 1, tprod;
	if (prod < (tprod = PROD(i,j,NORTH))) prod = tprod;
	if (prod < (tprod = PROD(i,j,EAST))) prod = tprod;
	if (prod < (tprod = PROD(i,j,WEST))) prod = tprod;
	if (prod < (tprod = PROD(i,j,SOUTH))) prod = tprod;
	if (prod < (tprod = PROD(i,j,NE))) prod = tprod;
	if (prod < (tprod = PROD(i,j,NW))) prod = tprod;
	if (prod < (tprod = PROD(i,j,SE))) prod = tprod;
	if (prod < (tprod = PROD(i,j,SW))) prod = tprod;
	return prod;
}

int main()
{
	int i, j;
	int prod = 1, tprod=0;

	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			scanf("%d", &arr[i][j]);

	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			if (prod < (tprod = find_max_prod(i, j)))
				prod = tprod;

	printf("ans:%d\n", prod);
	return 0;
}

