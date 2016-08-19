#include <stdio.h>

#define NUM 4

typedef struct s_student {
	char *name;
	int score;
} student;

int main(void) {
	int avr;
	int i;
	int sum = 0;
	student arr[NUM] = {
		{"xiaowang", 68},
		{"jone", 70},
		{"hehe", 54},
		{"boer", 64}
		};

	for (i = 0; i < NUM; i++) {
		sum += arr[i].score;
	}
	avr = sum/NUM;
	printf("the average score is:%d\n", avr);

	for (i = 0; i < NUM; i++) {
		if (arr[i].score > avr)
			printf("name:%s, socre:%d\n", arr[i].name, arr[i].score);
	}

	return 0;
}
