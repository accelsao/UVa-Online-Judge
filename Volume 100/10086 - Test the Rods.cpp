#include <algorithm>
#include<iostream>
using namespace std;

int dp[305][305];
int argdp[305][305][2];
int main() {
	int T1, T2;
	int n, m;
	int A[305], B[305];
	int i, j, k;
	while (cin>>T1>>T2){
		if (T1 == 0 && T2 == 0)
			break;
		for (int i = 0; i < 305; i++)
			for (int j = 0; j < 305; j++)
				dp[i][j] = 1e9;
		dp[0][0] = 0;
		cin>>n;
		int ch = 0;
		for (i = 0; i < n; i++) {
			cin>>m;
			for (j = 1; j <= m; j++)
				cin>>A[j];
			for (j = 1; j <= m; j++)
				cin>>B[j];
			A[0] = B[0] = 0;
			for (j = 0; j <= m; j++) {
				for (k = 0; k <= ch; k++) {//ch 前一個最大的可能+m 目前的數 要小於T1 T2=ch+m(最大可能數)-T1
					if (k + j <= T1 && (ch + m) - (k + j) <= T2) {
						if (dp[k + j][(ch + m) - (k + j)] > dp[k][ch - k] + A[j] + B[m - j]) {
							dp[k + j][(ch + m) - (k + j)] = dp[k][ch - k] + A[j] + B[m - j];
							argdp[k + j][(ch + m) - (k + j)][0] = k;
							argdp[k + j][(ch + m) - (k + j)][1] = ch - k;
						}
					}
				}
			}
			ch += m;
		}
		printf("%d\n", dp[T1][T2]);
		int ret[105];
		for (i = n - 1; i >= 0; i--) {
			ret[i] = T1 - argdp[T1][T2][0];
			int tt1 = T1, tt2 = T2;
			T1 = argdp[tt1][tt2][0];
			T2 = argdp[tt1][tt2][1];

		}
		for (i = 0; i < n; i++) {
			if (i)   putchar(' ');
			printf("%d", ret[i]);
		}
		puts("\n");
	}
}
