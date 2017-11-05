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

int N, S, T, X[35], Y[35];
int ret, U[35];
void dfs(int nd, int cost, int used) {
	if (cost + (N - X[nd] + N - Y[nd] - 2) >= ret)
		return;
	if (used == S) {
		ret = min(ret, cost + (N - X[nd] + N - Y[nd] - 2));
		return;
	}
	int i;
	for (i = 1; i < T; i++) {
		if (!U[i]) {
			U[i] = 1;
			dfs(i, cost + abs(X[i] - X[nd]) + abs(Y[i] - Y[nd]), used + 1);
			U[i] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int i, j, cases = 0;
	while (cin>>N>>T>>S,N+T+S) {
		int g[35][35] = {};
		for (i = 0; i < T; i++) {
			cin >> X[i] >> Y[i];
			g[X[i]][Y[i]]++;
		}
		X[0] = 0, Y[0] = 0;
		T = 1;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)
				if (g[i][j])
					X[T] = i, Y[T] = j, T++;			
		}
		for (int i = 0; i < T; i++)U[i] = 0;
		ret = 1e9;
		dfs(0, 0, 0);
		printf("Case %d: %d\n", ++cases, ret);
	}
}
