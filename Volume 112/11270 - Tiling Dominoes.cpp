#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<functional>
#include<unordered_map>
#include<stack>
using namespace std;



int n, m;
int main() {
	while (cin >> n >> m) {
		if (n < m)swap(n, m);
		long long dp[2][1 << 10] = {};
		int t = 0,left,up;
		int M = 1 << m;
		dp[0][M - 1] = 1;
		for (int i = 0; i<n; i++)
			for (int j = 0; j < m; j++) {
				memset(dp[!t], 0, sizeof(dp[!t]));
				for (int s = M-1; s >=0; s--) {
					if (!j)left = 1;//左邊邊界 當作有東西
					else left = (s >> (j - 1)) & 1;
					up = (s >> j) & 1;
					if (!up)//set 2x1
						dp[t ^ 1][s | (1 << j)] += dp[t][s];
					if (!left&&up)//set 1x2
						dp[t ^ 1][s | (1 << j) | (1 << (j - 1))] += dp[t][s];
					if (up)//set nothing
						dp[t ^ 1][s ^ (1 << j)] += dp[t][s];
				}
				t ^= 1;
			}
		printf("%lld\n", dp[t][M - 1]);
	}
}
