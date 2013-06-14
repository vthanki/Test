#include <stdio.h>
#define MAX_NUM	1000
int main()
{
	int limit = MAX_NUM;
	int result = 0;
	while (--limit)
		result += (!(limit % 3) || !(limit % 5)) ? limit : 0;
	printf("Result = %d\n", result);
	return 0;
}
