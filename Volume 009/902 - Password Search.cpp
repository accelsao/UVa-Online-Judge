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
#define scanf scanf_s
using namespace std;


int main() {
	Accel;
	int n;
	string s, t;
	while (cin >> n) {
		cin >> s;
		map<string, int> mp;
		for (int i = 0; i <= s.size() - n; ++i)
			mp[s.substr(i, n)]++;
		int x = 0;
		for (auto &m : mp)
			if (m.second > x) {
				x = m.second;
				s = m.first;
			}
		cout << s << endl;
	}
}
