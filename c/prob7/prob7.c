#include <stdio.h>
#include <malloc.h>

/* Assumption that 10001'th prime will be less than MAX */
#define MAX 1000000

char *map;

static void preparePrimes(long N) {

	long i, j;
	for (j = 2; j < N; j++ ) {
		for (i = j*2; i < N; i+=j) {
			map[i] = 1;
		}
	}
}


static int isPrimeFast(long N) {
	return map[N] == 0;
}

int main()
{
	long i, j = 2;

	map = (char *)malloc(MAX*sizeof(char));
	if (!map) {
	       printf("malloc failed\n");
	       return -1;
	}

	preparePrimes(MAX);

	for (i = 0; i < 10001 && j < MAX;)
		if (isPrimeFast(j++)) i++;

	printf("%u\n", j-1);
	free(map);
	return 0;
}
