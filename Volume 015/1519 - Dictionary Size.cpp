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
/*
現在考慮普遍情況  
pre XXXbbb
suf bbbXXX
若只考慮重復b的情況
假設左邊x個b，右邊y個b
不考慮重復情況左邊應為（1+x）選擇
右邊應為（1+y）選擇
總共有這麼(1+x)*(1+y)
但是實際情況應該是1+x+y種情況
則應該減去x*y種情況
還有一個要註意的是如果出現單獨的字符，應該標記，建立trie樹的時候，不會把單個字符算進去 因為題目要求非空前後綴字串
*/
