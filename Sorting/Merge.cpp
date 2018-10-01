//2017029589_·ùÁö¹ü_509

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100001
int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i>mid) {
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	}
	else {
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];
	}

	for (l = left; l <= right; l++) {
		list[l] = sorted[l];
	}
}

void sort(int list[], int left, int right) {
	int mid;

	if (left<right) {
		mid = (left + right) / 2;
		sort(list, left, mid);
		sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int main(void) {
	int n, num;
	scanf("%d", &n);
	int *arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &num);
		arr[i] = num;
	}
	sort(arr, 0, n-1);
	for (int i = n - 1; i >= 0; --i) {
		printf("%d\n", arr[i]);
	}
	free(arr);
	return 0;
}