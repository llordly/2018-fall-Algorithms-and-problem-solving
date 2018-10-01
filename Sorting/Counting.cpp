//2017029589_·ùÁö¹ü_509

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int N, M, K, num, a, b, ans;
	scanf("%d %d %d", &N, &M, &K);
	int *count = (int*)malloc(sizeof(int) * (M + 1));
	int *countSum = (int*)malloc(sizeof(int) * (M + 1));
	int *A = (int*)malloc(sizeof(int) * K);
	int *B = (int*)malloc(sizeof(int) * K);

	for (int i = 0; i <= M; ++i) {
		count[i] = 0;
	}

	for (int i = 0; i < K; ++i) {
		A[i] = B[i] = 0;
	}
	
	for (int i = 0; i < K; ++i) {
		scanf("%d %d", &a, &b);
		A[i] = a, B[i] = b;
	}

	for (int i = 0; i < N; ++i) {
		scanf("%d", &num);
		count[num]++;
	}
	for (int i = 1; i <= M; ++i) {
		count[i] += count[i - 1];
	}
	for (int i = 0; i < K; ++i) {
		printf("%d\n", count[B[i]] - count[A[i] - 1]);
	}
	return 0;
}