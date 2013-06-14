#include <stdio.h>
#define LIMIT 4000000
#define IS_EVEN(x)	((x%2) ? 0 : 1)
unsigned long find_result()
{
	unsigned int sum = 0, term1, term2;
	unsigned long result = 0;
	term1 = 0; term2 = 1;
	while(1) {
		sum = term1 + term2;
		term2 = term1;
		term1 = sum;
		if (sum > LIMIT)
			break;
		if (IS_EVEN(sum))
			result += sum;
	}
	return result;
}

int main()
{
	printf("Result is %lu\n", find_result());
	return 0;
}       
