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
#define N 400005
#define M
using namespace std;

struct Trie {
	int ch[N][26];
	int cnt[26];
	int sz;
	void init() {
		sz = 1;
		Re(ch[0], 0);
		Re(cnt, 0);
	}
	void in(string s) {
		int len = s.size();
		int u = 0;
		for (int i = 0; i< len; i++) {
			int c = s[i] - 'a';
			if (!ch[u][c]) {
				Re(ch[sz], 0);
				ch[u][c] = sz++;
				if (i)cnt[c]++;
			}
			u = ch[u][c];
		}
	}
}pre,suf;

int n, v[26];
string s;

int main() {
	Accel;
	while (cin >> n) {
		pre.init(), suf.init();
		Re(v, 0);
		while(n--){
			cin >> s;
			if (s.size() == 1)
				v[s[0] - 'a'] = 1;
			pre.in(s);
			reverse(s.begin(), s.end());
			suf.in(s);
		}
		LL ans = (LL)(pre.sz - 1)*(suf.sz - 1);
		for (int i = 0; i < 26; i++)
			ans -= (LL)pre.cnt[i] * suf.cnt[i] - v[i];//v 單個字的情況 要扣掉
		printf("%lld\n", ans);
	}
}
