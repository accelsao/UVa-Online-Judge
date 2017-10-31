#include<iostream>
#include<cstring>
using namespace std;

int dp[21][100001], m[21], N;
int dfs(int n,int s) {
	if (dp[n][s] != -1)return dp[n][s];
	if (!s)return dp[n][s] = 1;
	dp[n][s] = 0;
	for (int i = 1; i <= m[n]; i++) {
		if (s < i)break;
		if (!dfs((n + 1) % (2 * N), s - i))
			dp[n][s] = 1;
	}
	return dp[n][s];
}
int main() {
	int s;
	while (cin >> N, N) {
		memset(dp, -1, sizeof(dp));
		cin >> s;
		for (int i = 0; i < 2 * N; i++)
			cin >> m[i];
		printf("%d\n", dfs(0, s) ? 1 : 0);
	}
}
