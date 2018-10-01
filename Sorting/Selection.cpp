//2017029589_·ùÁö¹ü_509

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void selection_sort(int *arr,int n, int m) {
	int minIndex, temp;

	for (int i = 0; i < m; ++i) {
		minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}
		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}
	for (int i = 0; i < n; ++i) {
		printf("%d\n", arr[i]);
	}
}

int main(void) {
	int N, M, num;
	scanf("%d %d", &N, &M);
	int *arr = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &num);
		arr[i] = num;
	}

	selection_sort(arr, N, M);
	return 0;
}