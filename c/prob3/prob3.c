#include <stdio.h>
#include <stdlib.h>

unsigned long long is_prime(unsigned long long num)
{
	unsigned long long i, is_prime = 1;
	for (i = 2; i < num/2; i++) {
		if (num%i == 0) {
			is_prime = 0;
			break;
		}
	}
	return is_prime;
}

unsigned long long max_prime_factor(unsigned long long num)
{
	unsigned long long  max_prime;
	unsigned long long t_num = num, i = 2;
	printf("Factors of %llu are :", num);
	while (t_num && i <= t_num) {
		if (t_num%i == 0) {
			t_num /= i;
			if (is_prime(i))
				max_prime = i;
			printf("%llu ", i);
			continue;
		}
		i++;
	}
	printf("\n");
	return max_prime;
}


int main(int argc, char *argv[])
{
	//printf("%lu is %s\n", atol(argv[1]), is_prime(atol(argv[1])) ?
	//		"prime" : "not a prime");
	printf("Max  prime factor for %llu is %llu\n", 600851475143ULL,
			max_prime_factor(600851475143ULL));
	return 0;
}
