#include <stdio.h>
#include <malloc.h>

#define MAX 2000000

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
	long sum = 0;
	int i;

	map = (char *)malloc(MAX*sizeof(char));
	if (!map) {
	       printf("malloc failed\n");
	       return -1;
	}

	preparePrimes(MAX);

	for (i = 2; i < MAX; i++)
		if (isPrimeFast(i)) sum += i;

	printf("%ld\n", sum);
	free(map);
	return 0;
}
