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


char g[2010][2010], dp[2010][2010];
int lx[4010], rx[4010], ly[4010], ry[4010];
long long x[4010], y[4010];
int main() {
	int cases = 0;
	int m, n, w;
	int i, j, k, p, q, r;
	while (cin >> m >> n >> w, n + m + w) {
		map<int, int> Rx, Ry;
		Rx[0] = 1, Ry[0] = 1;
		Rx[n] = 1, Ry[m] = 1;
		for (i = 0; i < w; i++) {
			cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
			rx[i]++, ry[i]++;
			Rx[lx[i]] = 1, Ry[ly[i]] = 1;
			Rx[rx[i]] = 1, Ry[ry[i]] = 1;
		}
		int sizex = 0, sizey = 0;
		for (map<int, int>::iterator it = Rx.begin();
			it != Rx.end(); it++) {
			it->second = sizex;
			x[sizex++] = it->first;
		}
		for (map<int, int>::iterator it = Ry.begin();
			it != Ry.end(); it++) {
			it->second = sizey;
			y[sizey++] = it->first;
		}
		memset(g, 0, sizeof(g));
		memset(dp, 0, sizeof(dp));
		for (i = 0; i < w; i++) {
			int llx = Rx[lx[i]], rrx = Rx[rx[i]];
			int rry = Ry[ry[i]];
			for (p = llx+1; p <= rrx; p++)//第一個 左上都可到達 g[][]=0;
				g[p][rry] = 1;

		}
		dp[sizex - 1][sizey - 1] = 1;
		long long ret = 0;
		for (i = sizex - 1; i > 0; i--) {
			for (j = sizey - 1; j > 0; j--) {
				if (g[i][j])
					continue;
				if (!dp[i][j])
					ret += (x[i] - x[i - 1])*(y[j] - y[j - 1]);
				dp[i - 1][j] |= dp[i][j];
				dp[i][j - 1] |= dp[i][j];
			}
		}
		printf("Case %d: %lld\n", ++cases, ret);
	}
}
//參考morris
