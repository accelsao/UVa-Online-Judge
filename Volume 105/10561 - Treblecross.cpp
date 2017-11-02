#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<string>
using namespace std;

const int maxn = 205;
int g[maxn], v[maxn];

int SG(int s) {
	memset(v, 0, sizeof(v));
	for (int i = 1; i <= s; i++) {
		int t = 0;
		if (s - i - 2 >= 0)
			t ^= g[s - i - 2];
		if (i - 3 >= 0)
			t ^= g[i - 3];
		v[t] = 1;	
	}
	int mv = -1;
	while (v[++mv]);
	return mv;
}

void init() {
	memset(g, 0, sizeof(g));
	g[1] = g[2] = g[3] = 1;
	for (int i = 4; i <= 200; i++)
		g[i] = SG(i);
}

int n, len, pos[maxn];
string str;

bool check() {
	int pre = -3, ret = 0;
	for (int i = 0; i <= len; i++) {
		if (str[i] == 'X') {
			if (i - pre <= 2)
				return false;
			int l = max(i - pre - 5, 0);// i-pre 包含 i這個X 左右X 兩格內也是禁區 2*2+1 =5
			if (l)
				ret ^= g[l];
			pre = i;
		}
	}

	int l = max(len - pre - 3, 0);//X..  這三塊都禁區 -3
	if (l)
		ret ^= g[l];
	return ret == 0;
}

bool judge() {
	n = 0;
	len = str.size();
	for (int i = 0; i < len; i++) 
		if (str[i] == '.') {
			str[i] = 'X';
			if (check())
				pos[n++] = i + 1;
			else if (i && i < len - 1 & str[i - 1] == 'X' && str[i + 1] == 'X')
				pos[n++] = i + 1;

			else if (i < len - 2 && str[i + 1] == 'X' && str[i + 2] == 'X')
				pos[n++] = i + 1;

			else if (i >= 2 && str[i - 1] == 'X' && str[i - 2] == 'X')
				pos[n++] = i + 1;
			str[i] = '.';
		}
	
	return n;
}

int main() {
	init();
	int T;
	cin >> T;
	while (T--) {
		cin >> str;
		puts(judge() ? "WINNING" : "LOSING");
		if (n)
			printf("%d", pos[0]);
		for (int i = 1; i < n; i++)
			printf(" %d", pos[i]);
		puts("");
	}
}
