//2017029589_RyuJibeom_509
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define MAX_HEAP_SIZE 300000

int countBit(double x) {
	return (int)ceil(log(x) / log(2));
}

typedef struct Node{
	int weight;
	Node *left_child;
	Node *right_child;
}Node;

int heap_size;
Node *heap[MAX_HEAP_SIZE];

int huffmanCode = 0;

void swap(Node *a, Node *b) {
	Node temp = *a;
	*a = *b;
	*b = temp;
}

void heap_increase_key(int i, Node *newNode) {
	while (i > 1 && heap[i / 2]->weight > newNode->weight) {
		heap[i] = heap[i / 2];
		i /= 2;
	}

	heap[i] = newNode;
}

void insert_heap(Node *newNode) {
	heap_size++;
	heap_increase_key(heap_size, newNode);
}

void min_heapify(Node *arr[], int index) {
	int temp = index;

	if (heap_size < index * 2) return;
	if (heap_size == index * 2) {
		if (arr[index]->weight > arr[index * 2]->weight) {
			temp = index * 2;
		}
	}
	else {
		if (arr[index * 2]->weight < arr[index * 2 + 1]->weight) {
			if (arr[index]->weight > arr[index * 2]->weight) {
				temp = index * 2;
			}
		}
		else {
			if (arr[index]->weight > arr[index * 2 + 1]->weight) {
				temp = index * 2 + 1;
			}
		}
	}

	if (temp != index) {
		swap(arr[temp], arr[index]);
		min_heapify(arr, temp);
	}
}

Node *extract_min_heap() {
	if (heap_size < 1) return NULL;
	swap(heap[1], heap[heap_size]);
	heap_size--;
	min_heapify(heap, 1);
	return heap[heap_size + 1];
}

void build_min_heap() {
	for (int i = heap_size / 2; i > 0; --i) {
		min_heapify(heap, i);
	}
}

Node *makeNode(Node *a, Node *b) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->weight = a->weight + b->weight;
	if (a->weight < b->weight) {
		newNode->left_child = a;
		newNode->right_child = b;
	}
	else {
		newNode->left_child = b;
		newNode->right_child = a;
	}
	return newNode;
}

void printResult(Node *result, int height) {
	if (result->left_child != NULL) {
		printResult(result->left_child, height + 1);
	}
	if (result->right_child != NULL) {
		printResult(result->right_child, height + 1);
	}
	if (result->left_child == NULL && result->right_child == NULL) {
		huffmanCode += result->weight * height;
		return;
	}
}

int main(void) {
	int n, weight, total;
	char alpha[5];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s %d", alpha, &weight);
		heap[i] = (Node*)malloc(sizeof(Node));
		heap[i]->weight = weight;
		heap[i]->left_child = NULL;
		heap[i]->right_child = NULL;
	}

	scanf("%d", &total);

	heap_size = n;
	build_min_heap();
	
	Node *result;
	while (true) {
		Node *a = extract_min_heap();
		Node *b = extract_min_heap();
		Node *c = makeNode(a, b);
		if (heap_size == 0) {
			result = c;
			break;
		}
		insert_heap(c);
	}
	
	printResult(result, 0);
	printf("%d\n%d", countBit(n) * total, huffmanCode);
	return 0;
}