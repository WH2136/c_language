#include <stdio.h>
#include <malloc.h>

#define MAXSIZE  2

typedef struct item {
	char name[20];
	char addr[100];
	char code[7];
	char tel[11];
} person;

int insert(char  *file_path);

int main(void) {
	FILE *fp;
	int i = 0;
	int test;
	person container[MAXSIZE];
	char *file_path = "test.txt";
	/*
	 * mode-w:"Truncate"  file  to zero length or create text file for writing.
	 * mode-a:Open for appending (writing at end of file).
	 */
	fp = fopen(file_path, "r");
	if (fp != NULL) {
		/* fscanf's return value is the number of "characters" printed */
		while(fscanf(fp, "%s%s%s%s", container[i].name, container[i].addr,
			container[i].code, container[i].tel) == 4) {

			printf("name:%s addr:%s code:%s tel:%s\n", container[i].name,
				container[i].addr, container[i].code, container[i].tel);
			i++;
		}
	}
	fclose(fp);
	fp = NULL;
	if (insert(file_path) == 1)
		printf("insert successfully\n");

	return 0;
}

int insert(char *file_path) {
	int result;
	person test;
	FILE *fp;

	if ((fp = fopen(file_path, "a+")) == NULL) {
		printf("open file failed\n");
		goto failed;
	}
	printf("please input the item you want to insert\n");
	scanf("%s %s %s %s", test.name, test.addr, test.code, test.tel);
#if 0
	if ((result = fseek(fp, 0, SEEK_END)) == -1) {
		printf("fseek failed\n");
		goto failed;
	}
#endif
	if (fprintf(fp, "%s %s %s %s", test.name, test.addr, 
			test.code, test.tel) > 0)
		goto success;
	else
		goto failed;
	
failed:
	fclose(fp);
	return 0;
success:
	fclose(fp);
	return 1;
}
