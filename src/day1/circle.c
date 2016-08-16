#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE  20

typedef struct class {
	char *name;
	struct class *next;
} student;


student *insert(student *index, char *name) {
	student *temp = (student *)malloc(sizeof(student));

	temp->next;
	index->next = temp;
	temp->name = name;
	index = temp;

	return index;
}

int del(student *prev) {
	return 0;
}
/*
 * pointer of structure is just a pointer.
 * if it isn't point to a struct space, struct member next is useless.
 */
int main(void) {
	student *tail = NULL;
	//char temp[MAXSIZE];
	char *arr[MAXSIZE];
	int num, i;
	student *swap = NULL;
	student *head = (student *)malloc(sizeof(student));
	
	head->next = NULL;
	tail = head;
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%s", arr[i]);
		//tail = insert(tail, temp);
		swap = (student *)malloc(sizeof(student));
		swap->next = NULL;
		swap->name = arr[i];
		tail->next = swap;
		tail = swap;
	}
	tail = head->next;
#if 1
	while(tail) {
		printf("%s\n", tail->name);
		tail=tail->next;
	}
#endif
	
	return 0;
}

