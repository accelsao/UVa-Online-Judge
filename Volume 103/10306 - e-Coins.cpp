#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<cctype>
#include<sstream>
using namespace std;

int c[41][2];
int dp[301][301];
int change(int m, int s){
	for (int i = 0; i <= s; i++)
		for (int j = 0; j <= s; j++)
			dp[i][j] = 301;
	dp[0][0] = 0;

	for (int i = 0; i < m; i++){
		for (int x = c[i][0]; x*x + c[i][1] * c[i][1] <= s*s; x++)
			for (int y = c[i][1]; x*x + y*y <= s*s; y++)
				dp[x][y] = min(dp[x][y], dp[x - c[i][0]][y - c[i][1]] + 1);
	}
	int ans = 301;
	for (int i = 0; i <= s; i++)
		for (int j = 0; j <= s; j++)
			if (i*i + j*j == s*s)
				ans = min(ans, dp[i][j]);
	return ans;
}
int main(){
	int t;
	cin >> t;
	while (t--){
		int m, s;
		cin >> m >> s;
		for (int i = 0; i < m; i++)
			cin >> c[i][0] >> c[i][1];
		int ans = change(m, s);
		if (ans > 300)
			puts("not possible");
		else
			printf("%d\n", ans);
	}
}
