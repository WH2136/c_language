#include <stdio.h>

int main(void) {
	char *name;
	int age;
	int tall;
	FILE *fp = fopen("test.in", "r");

	if(fp != NULL ) {
		fscanf(fp, "%s%d%d", name, &age, &tall);
		fclose(fp);
	}

	printf("the result is:%s%d%d\n", name, age, tall);

	return 0;
}
