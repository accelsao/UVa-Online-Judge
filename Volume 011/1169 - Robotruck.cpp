#include<iostream>
#include<string>
#include<string>
#include<sstream>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

int n, m, k;
const int M = 100005;
int dp[M], cost[M], d[M], x[M], y[M], w[M];
deque<int>q;
int f(int j) {
	return dp[j - 1] - cost[j] + d[j];
}
int main() {
	int t;
	cin >> t;
	int c, n;
	while (t--){
		cin >> c >> n;
		w[0] = cost[0] = x[0] = y[0] = 0;
		for (int i = 1; i <= n; i++){
			cin >> x[i] >> y[i] >> w[i];
			cost[i] = cost[i - 1] + abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
			w[i] += w[i - 1];
			d[i] = abs(x[i]) + abs(y[i]);
		}
		q.clear();
		q.push_back(0);
		for (int i = 1; i <= n; i++){
			while (!q.empty() && w[i] - w[q.front()] > c)
				q.pop_front();
			dp[i] = f(q.front() + 1) + cost[i] + d[i];
			while (!q.empty() && f(q.back() + 1) >= f(i + 1))
				q.pop_back();
			q.push_back(i);
		}
		printf("%d\n", dp[n]);
		if (t)puts("");
	}
}
// dp[i] = dp[j-1] + cost[j, i] + dist[j] + dist[i]  j<=i
// dp[i] = dp[j-1] + cost[i] - cost[j] + dist[j] + dist[i]
// dp[i] = (dp[j-1] - cost[j] + dist[j]) + cost[i] + dist[i]
