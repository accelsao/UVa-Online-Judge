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
#include<fstream>
#include<stack>
#include<vector>
using namespace std;


//dp[i] = (dp[j - 1] - cost[j] + dist[j]) + cost[i] + dist[i]
int cost[100001], d[100001];
int p[100001][3];
int dp[100001];
int f(int j) {
	return dp[j - 1] - cost[j] + d[j];
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int c, n;
		cin >> c >> n;
		p[0][0] = p[0][1] = p[0][2] = cost[0] = 0;
		for (int i = 1; i <= n; i++) {
			cin >> p[i][0] >> p[i][1] >> p[i][2];
			cost[i] = cost[i - 1] + abs(p[i][0] - p[i - 1][0]) + abs(p[i][1] - p[i - 1][1]);
			p[i][2] += p[i - 1][2];
			d[i] = abs(p[i][0]) + abs(p[i][1]);
		}
		deque<int>q;
		for (int i = 1; i <= n; i++) {
			while (!q.empty() && f(i) <= f(q.back()))
				q.pop_back();
			q.push_back(i);
			while (!q.empty() && p[i][2] - p[q.front() - 1][2] > c)
				q.pop_front();
			dp[i] = f(q.front())+ cost[i] + d[i];
		}
		printf("%d\n", dp[n]);
		if (t)
			puts("");
	}
}
// dp[i] = dp[j-1] + cost[j, i] + dist[j] + dist[i]  j<=i
// dp[i] = dp[j-1] + cost[i] - cost[j] + dist[j] + dist[i]
// dp[i] = (dp[j-1] - cost[j] + dist[j]) + cost[i] + dist[i]
