#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* Fill digits array by running program like:
 * $ cat ./digits | tr -d "\n" | ./a.out
 */
int main()
{
	char digits[1024] = {0};
	long rc, len = 0, i, j, max = 0, prod, maxi, si, ei;
	rc = read(0, digits, sizeof(digits));
	if (rc < 0)
		printf("Error %d in reading\n", rc);
	//printf("digits %d:\n%s\n", strlen(digits), digits);
	len = strlen(digits);
	for (i = 0; i < len-13;) {
		prod = 1;
		for (j = i; j < i+13; j++) {
			if (digits[j] == '0') {
				i = j;
				break;
			}
			prod *= (digits[j] - '0');
		}
		i++;
		if (max < prod) { max = prod; maxi = i-1; }
	}
	printf("ans:%ld, index:%ld\n", max, maxi);
	for (i = maxi; i < maxi + 13; i++)
		printf("%c ", digits[i]);
	printf("\n");
	return 0;
}
