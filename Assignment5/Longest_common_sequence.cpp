//2017029589_RyuJibeom_509
#include <cstdio>
#include <cstring>
#include <algorithm>

char x[1001];
char y[1001];
int dp[1001][1001];
int lcs2[1001][1001][2];
char lcs[1001][1001];
char str[1001];
int a, b;

int LCS(char *x, char *y, int n, int m) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (x[i - 1] == y[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				lcs[i][j] = x[i - 1];
			}
			else {
				if (dp[i - 1][j] <= dp[i][j - 1]) {
					dp[i][j] = dp[i][j - 1];
					lcs2[i][j][0] = i;
					lcs2[i][j][1] = j - 1;
				}
				else {
					dp[i][j] = dp[i - 1][j];
					lcs2[i][j][0] = i - 1;
					lcs2[i][j][1] = j;
				}
			}
		}
	}
	return dp[n][m];
}

char *LCS2(int n, int m, int length, char *str) {
	if (n == 0 || m == 0)
		return str;
	else {
		if (lcs[n][m] != 0) {
			str[length] = lcs[n][m];
			return LCS2(n - 1, m - 1, length - 1, str);
		}
		else {
			return LCS2(lcs2[n][m][0], lcs2[n][m][1], length, str);
		}
	}
}

int main() {

	scanf("%s %s", x, y);
	int n = strlen(x);
	int m = strlen(y);

	int result = LCS(x, y, n, m);

	printf("%s", LCS2(n, m, result - 1, str));
}