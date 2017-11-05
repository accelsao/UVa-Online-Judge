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

struct node{
	int l, r;
	long long v;
	bool operator<(const node &a)const{
		if (v != a.v)return v < a.v;
		if (l != a.l)return l > a.l;
		return r > a.r;
	}
	node(int a, int b, long long c) :
		l(a), r(b), v(c){}
	node() :
		l(0), r(0), v(0){}

};
#define INF 1LL<<60
struct STNode{
	int lx, rx;//left max right max
	node ans;
}ST[1<<20];
long long a[1 << 20], s[1 << 20];
void build(int k, int l, int r){
	if (l == r){
		ST[k].lx = ST[k].rx = l;
		ST[k].ans = node(l, r, a[l]);
		return;
	}
	if (l > r){
		ST[k].ans = node(-1, -1, -INF);
		return;
	}
	int m = (l + r) >> 1;
	build(k << 1, l, m);
	build(k << 1 | 1, m + 1, r);
	ST[k].ans = node(l, r, -INF);
	ST[k].ans = max(ST[k].ans, ST[k << 1].ans);//左區間
	ST[k].ans = max(ST[k].ans, ST[k << 1|1].ans);//右區間
	ST[k].ans = max(ST[k].ans, node(ST[k << 1].rx, ST[k << 1 | 1].lx, s[ST[k << 1 | 1].lx] - s[ST[k << 1].rx - 1]));
	ST[k].lx = s[ST[k << 1].lx] < s[ST[k << 1 | 1].lx] ? ST[k << 1 | 1].lx : ST[k << 1].lx;
	ST[k].rx = s[ST[k << 1].rx - 1] <= s[ST[k << 1|1].rx - 1] ? ST[k << 1].rx : ST[k << 1|1].rx;
	/*
	ST[k].rmax = ST[k<<1|1].rmax;
    if(SUM[r]-SUM[ST[k].rmax-1] <= SUM[r]-SUM[ST[k<<1].rmax-1])
        ST[k].rmax = ST[k<<1].rmax;
	*/
}
node query(int k,int l,int r,int ql,int qr,int &pl,int &pr){
	if (ql <= l&&r <= qr){
		pl = ST[k].lx;
		pr = ST[k].rx;
		return ST[k].ans; 
	}
	int m = (l + r) >> 1;
	node ans = node(l, r, -INF);
	int lp, ls, rp, rs;//p前綴 s後綴
	pl = -1, pr = -1;
	if (ql <= m&&qr > m){
		ans = max(ans, query(k << 1, l, m, ql, qr, lp, ls));
		ans = max(ans, query(k << 1 | 1, m + 1, r, ql, qr, rp, rs));
		if (ls != -1 && rp != -1)
			ans = max(ans, node(ls, rp, s[rp] - s[ls - 1]));
		if (ql <= l)
			pl = s[rp] > s[lp] ? rp : lp;
		if (qr >= r)
			pr = s[rs-1] >= s[ls-1] ? ls : rs;
	}
	else if (qr <= m){
		ans = max(ans, query(k << 1, l, m, ql, qr, lp, ls));
		if (ql <= l)pl = lp;
	}
	else if (ql>m){
		ans = max(ans, query(k << 1 | 1, m + 1, r, ql, qr, rp, rs));
		if (qr >= r)pr = rs;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int n, q, l, r, T = 1;
	while (cin >> n >> q){
		for (int i = 1; i <= n; i++)
			cin >> a[i], s[i] = s[i - 1] + a[i];
		build(1, 1, n);
		printf("Case %d:\n", T++);
		int tl, tr;
		while (q--){
			cin >> l >> r;
			node ans = query(1, 1, n, l, r, tl, tr);
			printf("%d %d\n", ans.l, ans.r);
		}
	}
}
