#include <stdio.h>

void DscSort (int a[], unsigned int n) {
	int i, k;
	int temp;

	for (i=n; i>0; i--) {
		for (k=0; k<(i-1); k++) {
			if (a[k] < a[k+1]) {
				temp = a[k];
				a[k] = a[k+1];
				a[k+1] = temp;
			}
		}
	}
	for (i=0; i<n; i++)
		printf("%d ", a[i]);
}

int main(void) {
	int InputArray[] = {1,5,4,8,3,2,9,6,7,0};
	//int OutputArray[] = {9,8,7,6,5,4,3,2,1,0};

	DscSort(InputArray, 10);

	return 0;
}
