/*
 * 输入5个国家名字，按字母顺序(ascii码值从小到大)输出
 */
#include <stdio.h>

#define NUM 5

/* get the ascii value of char x */
int char_to_int(char x) {
	int temp = (int)x;

	return temp;
}

int main(void) {
	int i;
	int k;
	char *swap;
	char *arr[NUM] = {"Chinese", "English", "America", "France", "Germany"};

	printf("%d\n", (int)'A');
	for (i = NUM; i >= 0; i--) {
		for (k = 0; k < (i-1); k++) {
			if (char_to_int(arr[k][0]) > char_to_int(arr[k+1][0])) {
				swap = arr[k];
				arr[k] = arr[k+1];
				arr[k+1] = swap;
			}
		}
	}
	for (i = 0; i < NUM; i++) 
		printf("%s\n", arr[i]);

	return 0;
}
