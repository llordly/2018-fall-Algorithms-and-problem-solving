//2017029589_RyuJibeom_509
#include <stdio.h>
#include <stdlib.h>

int arr[101];
int dp[101][101];
int s[101][101];

void printOrder(int i, int j) {
	int k;
	if (i == j)
		printf("%d ", i);
	else {
		k = s[i][j];
		printf("( ");
		printOrder(i, k);
		printOrder(k + 1, j);
		printf(") ");
	}
}

int main(void) {
	int n, num;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		scanf("%d", &num);
		arr[i] = num;
	}

	for (int d = 0; d < n; ++d) {
		for (int i = 1; i <= n - d; ++i) {
			int j = i + d;
			if (j == i) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = 2e9;
			for (int k = i; k <= j - 1; ++k) {
				int min = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
				
				if (dp[i][j] > min) {
					dp[i][j] = min;
					s[i][j] = k;
				}
			}
		}
	}

	printf("%d\n", dp[1][n]);

	printOrder(1, n);
	return 0;

}