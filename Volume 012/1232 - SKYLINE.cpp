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
using namespace std;

struct Node{
	int mx, mn, b;//label
}ST[1<<19];
long long ans;
void update(int k){
	ST[k].mx = max(ST[k << 1].mx, ST[k << 1 | 1].mx);
	ST[k].mn = min(ST[k << 1].mn, ST[k << 1 | 1].mn);
}
void dw(int k){
	if (ST[k].b){
		ST[k << 1].mx = ST[k << 1].mn = ST[k << 1].b = ST[k].b;
		ST[k << 1|1].mx = ST[k << 1|1].mn = ST[k << 1|1].b = ST[k].b;
		ST[k].b = 0;
	}
}
void mdf(int k, int L, int R, int &l, int &r, int h){
	if (R < L)return;
	if (R != L)
		dw(k);
	if (ST[k].mn > h)return;
	if (l <= L&&R <= r){
		if (h >= ST[k].mx){
			ans += (R - L + 1);
			ST[k].mx = ST[k].mn = ST[k].b=h;
			return;
		}
	}
	int m = (L + R) >> 1;
	if (l <= m)mdf(k << 1, L, m, l, r, h);
	if (r > m)mdf(k << 1 | 1, m + 1, R, l, r, h);
	update(k);
}
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int t, n, x, y, h;
	while (cin >> t,t){
		while (t--){
			cin >> n;
			memset(ST, 0, sizeof(ST));
			ans = 0;
			for (int i = 0; i < n; i++){
				cin >> x >> y >> h;
				y--;
				mdf(1, 1, 100000, x, y, h);
			}
			printf("%lld\n", ans);
		}
	}
}
