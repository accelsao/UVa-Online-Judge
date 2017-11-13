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
#include<ctime>
#include<vector>
#define accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define LL long long
using namespace std;

char E[500005];
int f[500005];
void pre(char *p, int len) {
	int i, j;
	for (i = 1, j = f[0] = -1; i < len; i++) {

		while (j >= 0 && p[j + 1] != p[i])
			j = f[j];
		if (p[j + 1] == p[i])
			j++;
		f[i] = j;
	}
}
int KMP(string t, char p[], int tlen, int plen) {
	int i, j, c = 0;
	for (i = 0, j = -1; i < tlen; i++) {
		while (j >= 0 && p[j + 1] != t[i])
			j = f[j];
		if (p[j + 1] == t[i])j++;
		if (j == plen - 1) {
			c++;
			j = f[j];
			if (c >= 2)return c;
		}
	}
	return c;
}
int main() {
	accel;
	string a, s, w;
	int n;
	cin >> n;
	while (n--) {
		cin >> a >> w >> s;
		int c[1024] = {}, ans[1024] = {}, id = 0;
		for (int i = 0; i < a.size(); i++)
			c[a[i]] = i;
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < w.size(); j++)
				E[j] = a[(c[w[j]] + i) % a.size()];
			E[w.size()] = '\0';
			pre(E, w.size());
			int cnt = KMP(s, E, s.size(), w.size());
			if (cnt == 1)
				ans[id++] = i;
		}
		if (!id)
			puts("no solution");
		else if (id == 1)
			printf("unique: %d\n", ans[0]);
		else {
			printf("ambiguous:");
			for (int i = 0; i < id; i++)
				printf(" %d", ans[i]);
			puts("");
		}
	}
}
