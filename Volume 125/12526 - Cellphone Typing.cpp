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
#define N 1100000
#define M
#define scanf scanf_s
using namespace std;

struct Trie {
	int ch[N][26];
	int val[N], sz;
	Trie() { sz = 1;Re(ch[0], 0); Re(val, 0);}
	void init() { sz = 1; Re(ch[0], 0); Re(val, 0); }
	void in(char *s) {
		int u = 0, n = strlen(s);
		for (int i = 0; i < n; i++) {
			int c = s[i] - 'a';
			if (!ch[u][c]) {
				Re(ch[sz], 0);
				val[sz] = 0;
				ch[u][c] = sz++;
			}
			u = ch[u][c];
		}
		val[u] = 1;
	}
	int find(char *s) {
		int ans = 0, pos = 0,n=strlen(s);
		for (int i = 0; i < n; i++) {
			int c = 0;
			for (int j = 0; j < 26; j++)
				if (ch[pos][j])
					c++;
			c += val[pos];
			if (c > 1 || !i)
				ans++;
			pos = ch[pos][s[i] - 'a'];
		}
		return ans;
	}
}d;
char s[N][100];
int main() {
	Accel;
	int n;
	while (cin >> n) {
		d.init();
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			d.in(s[i]);
		}
		int sm = 0;
		for (int i = 0; i < n; i++) 
			sm += d.find(s[i]);
		printf("%.2lf\n", sm*1.0 / n);
	}
}
