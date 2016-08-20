#include <stdio.h>
#include <malloc.h>

#define MAXSIZE  2

typedef struct item {
	char name[20];
	char addr[100];
	char code[7];
	char tail[11];
} person;

int main(void) {
	FILE *fp;
	int i;
	int test;
	person container[MAXSIZE];

	fp = fopen("test.txt", "r");
	if (fp != NULL) {
		// fscanf's return value is the number of "characters" printed
		while(fscanf(fp, "%s%s%s%s", container[i].name, container[i].addr,
			container[i].code, container[i].tail) == 4) {

			printf("name:%s addr:%s code:%s tail:%s\n", container[i].name,
				container[i].addr, container[i].code, container[i].tail);
			i++;
		}
	}
	fclose(fp);
	fp = NULL;

	return 0;
}

int insert(FILE *fp) {
	
}
