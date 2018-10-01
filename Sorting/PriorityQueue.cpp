//2017029589_류지범_509

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_HEAP_SIZE 100000

int heap_size;
int heap[MAX_HEAP_SIZE];

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heap_increase_key(int *arr, int i, int key) {
	if (heap[i] > key) return;
	
	while (i > 1 && heap[i / 2] < key) {
		heap[i] = heap[i / 2];
		i /= 2;
	}
	heap[i] = key;
}

void insert_heap(int num) {
	heap_size++;
	heap[heap_size] = INT_MIN;
	heap_increase_key(heap, heap_size, num);
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
	heap_size = 0;
	int n, m;

	while (true) {
		scanf("%d", &n);
		switch (n) {
		case 0:
			printf("\n");
			for (int i = 1; i <= heap_size; ++i) {
				printf("%d ", heap[i]);
			}
			return 0;
			break;
		case 1:
			scanf("%d", &n);
			insert_heap(n);
			break;
		case 2:
			if (heap_size < 1) return 0;
			printf("%d ", heap[1]);
			swap(&heap[1], &heap[heap_size]);
			heap_size--;
			max_heapify(heap, 1);
			break;
		case 3:
			//n인덱스에 m넣기
			scanf("%d %d", &n, &m);
			if (heap[n] == m) break;
			else if (heap[n] > m) {
				heap[n] = m;
				max_heapify(heap, n);
			}
			else {
				heap[n] = m;
				for (int i = n; i > 0; i /= 2) {
					max_heapify(heap, i);
				}
			}
			break;
		default:
			break;
		}
	}
	
	return 0;
}


/*

for (int i = heap_size / 2; i > 0; --i) {
max_heapify(heap, i);
}

int j = heap_size;
int l = heap_size - k;
for (j; j > l; --j) {
printf("%d ", heap[1]);
swap(&heap[1], &heap[j]);
heap_size--;
max_heapify(heap, 1);
}

printf("\n");

for (int i = 1; i <= heap_size; ++i) {
printf("%d ", heap[i]);
}




*/