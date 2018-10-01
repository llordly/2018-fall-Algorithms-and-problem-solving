//2017029589_·ùÁö¹ü_509

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int n, num;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		arr[i] = num;
	}
	for (int j = 1; j < n; ++j) {
		int key = arr[j];
		int i = j - 1;
		while (i >= 0 && arr[i] < key) {
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", arr[i]);
	}
}
// insertion sort 2.1-1 2.1-2