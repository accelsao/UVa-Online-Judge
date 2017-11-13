http://www.cnblogs.com/chenxiwenruo/p/3447615.html
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
const int maxn = 1000001;
struct RPN {//reverseprimenum
	int n;//num
	int f;//factor
	bool operator<(const RPN t)const {
		return n < t.n;
	}
}rpn[maxn];
int rx;//rpn下標
int bs(int m) {
int l=1,r=
}
int main() {
	char c;
	int d;
	while (cin >> c>>d) {
		if (c == 'q') {
			int u = bs(d + 1);
			printf("%lld", sum(u));
		}
		else {
			int u = m[d / 10];
			updatec(u, -1);
			updaten(u, -rpn[u].f);
		}
	}
}
