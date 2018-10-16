//2017029589_·ùÁö¹ü_509
//Assembly_line

#include <stdio.h>
#include <stdlib.h>

int arr1[101];
int arr2[101];
int t1[101];
int t2[101];
int dp[101][2];
int L[101][2];
int result[101];

int Assembly(int n) {
	int e1, e2, x1, x2, num;
	scanf("%d %d %d %d", &e1, &e2, &x1, &x2);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &num);
		arr1[i] = num;
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &num);
		arr2[i] = num;
	}
	for (int i = 1; i <= n - 1; ++i) {
		scanf("%d", &num);
		t1[i] = num;
	}
	for (int i = 1; i <= n - 1; ++i) {
		scanf("%d", &num);
		t2[i] = num;
	}
	dp[1][0] = arr1[1] + e1;
	dp[1][1] = arr2[1] + e2;

	for (int i = 2; i <= n; ++i) {
		int first, second;
		first = dp[i - 1][0] + arr1[i];
		second = dp[i - 1][1] + t2[i - 1] + arr1[i];

		if (first <= second) {
			dp[i][0] = first;
			L[i][0] = 1;
		}
		else {
			dp[i][0] = second;
			L[i][0] = 2;
		}
		
		first = dp[i - 1][0] + t1[i - 1] + arr2[i];
		second = dp[i - 1][1] + arr2[i];

		if (first <= second) {
			dp[i][1] = first;
			L[i][1] = 1;
		}
		else {
			dp[i][1] = second;
			L[i][1] = 2;
		}
	}
	x1 += dp[n][0];
	x2 += dp[n][1];
	
	if (x1 <= x2) {
		result[n] = 1;
		return x1;
	}
	else {
		result[n] = 2;
		return x2;
	}
}

int main(void) {
	int n;
	scanf("%d", &n);
	printf("%d\n", Assembly(n));

	for (int i = n; i > 1; --i) {
		result[i - 1] = L[i][result[i]-1];
	}


	for (int i = 1; i <= n; ++i) {
		printf("%d %d\n", result[i], i);
	}
	return 0;
}