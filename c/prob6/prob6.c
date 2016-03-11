#include <gmp.h>

/* To get hands dirty with GMP, otherwise there is
 * no need for GMP for this problem. Do not forget
 * to use -lgmp option while compiling.
 */

int main()
{
	mpz_t a, b;
	mpz_init(a);
	mpz_init(b);
	int i;
	for (i = 1; i <= 100; i++) {
		mpz_add_ui(a, a, i*i);
		mpz_add_ui(b, b, i);
	}
	mpz_mul(b, b, b);
	mpz_sub(a, b, a);
	gmp_printf("Ans: %Zd\n", a);
	return 0;
}
