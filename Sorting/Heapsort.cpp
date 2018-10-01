//2017029589_·ùÁö¹ü_509

#include <stdio.h>
#include <stdlib.h>

int heap_size;

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void max_heapify(int *arr, int index) {
	int temp = index;
	
	if (heap_size < index * 2) return;
	if (heap_size == index * 2) {
		if (arr[index] < arr[index * 2]) {
			temp = index * 2;
		}
	}
	else {
		if (arr[index * 2] > arr[index * 2 + 1]) {
			if (arr[index] < arr[index * 2]) {
				temp = index * 2;
			}
		}
		else {
			if (arr[index] < arr[index * 2 + 1]) {
				temp = index * 2 + 1;
			}
		}
	}

	if (temp != index) {
		swap(&arr[temp], &arr[index]);
		max_heapify(arr, temp);
	}
}

int main(void) {
	int N, k, num;
	scanf("%d %d", &N, &k);
	int *heap = (int*)malloc(sizeof(int)*(N + 1));
	heap_size = N;

	for (int i = 1; i <= N; ++i) {
		scanf("%d", &num);
		heap[i] = num;
	}

	for (int i = heap_size / 2; i > 0; --i) {
		max_heapify(heap, i);
	}

	int count = 0;
	int j = heap_size;
	int l = heap_size - k;
	for (j; j > l; --j) {
		count++;
		printf("%d ", heap[1]);
		swap(&heap[1], &heap[j]);
		heap_size--;
		max_heapify(heap, 1);
		//if (count == k) break;
	}

	printf("\n");

	for (int i = 1; i <= heap_size; ++i) {
		printf("%d ", heap[i]);
	}

	return 0;
}