#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>

int mult_ok(int x, int y) {
	int p = x*y;
	/* x es 0, o dividir p por x = y */
	return !x || (p/x) == y;
}

int64_t hi(int64_t x) {
	return x >> 32;
}
int64_t lo(int64_t x) {
	return ((1L << 32) - 1) & x;
}
int64_t mult_ok64(int64_t a, int64_t b){
	int64_t s0, s1, s2, s3; 

	int64_t x = lo(a) * lo(b);
	s0 = lo(x);

	x = hi(a) * lo(b) + hi(x);
	s1 = lo(x);
	s2 = hi(x);

	x = s1 + lo(a) * hi(b);
	s1 = lo(x);

	x = s2 + hi(a) * hi(b) + hi(x);
	s2 = lo(x);
	s3 = hi(x);

	int64_t result = s1 << 32 | s0;
	int64_t carry = s3 << 32 | s2;
	return carry;	
}


int main(){
	int64_t x = 1000000000000, y = 100000000000;
	printf("%" PRId64 "\n",mult_ok64(x,y));

}
