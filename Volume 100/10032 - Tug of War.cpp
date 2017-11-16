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
#include<stack>
#include<ctime>
#include<vector>
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define LL long long
#define Re(a,b) memset(a,b,sizeof(a))
#define N
#define M
using namespace std;

LL dp[30000];
int p[101];
int main() {
	Accel;
	int t;
	cin >> t;
	while (t--) {
		int n, s = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> p[i], s += p[i];
		Re(dp, 0);
		int w = s / 2, hn = n / 2;
		dp[0] = 1;
		for (int i = 0; i < n; i++) {
			for (int j = w; j >= p[i]; j--) 
				dp[j] |= dp[j - p[i]] << 1LL;

			//cout << dp[p[i]] << endl;
		}
		if (n & 1)
			while (!(dp[w] & (1LL << hn)) && !(dp[w] & (1LL << (hn + 1))))
				w--;
		else
			while (!(dp[w] & (1LL<<hn)))
				w--;
		
		printf("%d %d\n", w, s - w);
		if (t)puts("");
	}
}
