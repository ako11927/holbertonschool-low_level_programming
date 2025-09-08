#include "../main.h"
#include <stdio.h>
int main(void){
	printf("%d\n", is_prime_number(1));
	printf("%d\n", is_prime_number(1024));
	printf("%d\n", is_prime_number(16));
	printf("%d\n", is_prime_number(17));
	printf("%d\n", is_prime_number(25));
	printf("%d\n", is_prime_number(-1));
	printf("%d\n", is_prime_number(113));
	printf("%d\n", is_prime_number(7919));
	return (0);
}
