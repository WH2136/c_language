#include <stdio.h>

/*
 *
 */

#define C(r, x) r &= ~(1UL << x)
#define S(r, y) r |= (1UL << y)

int main(void) {
	int r, x, y;

	scanf("%X %d %d", &r, &x, &y);

	C(r, x);
	S(r, y);
	S(r, y-1);
	C(r, y-2);

	printf("%X\n", r);

	return 0;
}
