#include<iostream>
#include<sstream>
#include<algorithm>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<map>
#include<vector>
#include<cmath>
#include<queue>
#include<cstring>
#include<set>
#include<functional>
#include<list>
#include<stack>
#include<cstring>
#include<utility>
#include <climits>
#include<unordered_map>
using namespace std;
#define printf printf_s
#define sprintf sprintf_s
#define sscanf sscanf_s
#define scanf scanf_s

#define MX 1111111
#define lson l,m,n<<1
#define rson m+1,r,n<<1|1
using namespace std;
int num[MX], sum[MX << 2], add[MX << 2], inv[MX << 2];
string s;
inline void pushUp(int n){
	sum[n] = sum[n << 1] + sum[n << 1 | 1];
}
void build(int l, int r, int n)
{
	add[n] = -1, inv[n] = 0;
	if (l == r)
	{
		sum[n] = num[l];
		return;
	}
	int m = (l + r) >> 1;
	build(lson), build(rson), pushUp(n);
}
void flip(int x)
{
	if (inv[x] % 2) ++inv[x];
}
void pushDown(int n, int m)
{
	if (add[n] != -1)
	{
		add[n << 1] = add[n << 1 | 1] = add[n];
		flip(n << 1), flip(n << 1 | 1);
		sum[n << 1] = add[n] * (m - (m >> 1));
		sum[n << 1 | 1] = add[n] * (m >> 1);
		add[n] = -1;
	}
	if (inv[n] && inv[n] % 2)
	{
		++inv[n << 1];
		++inv[n << 1 | 1];
		sum[n << 1] = (m - (m >> 1)) - sum[n << 1];
		sum[n << 1 | 1] = (m >> 1) - sum[n << 1 | 1];
		++inv[n];
	}
}
void update(int L, int R, int v, int l, int r, int n)
{
	if (L <= l && r <= R)
	{
		add[n] = v, flip(n);
		sum[n] = v * (r - l + 1);
		return;
	}
	pushDown(n, r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, v, lson);
	if (m < R) update(L, R, v, rson);
	pushUp(n);
}
void inverse(int L, int R, int l, int r, int n)
{
	if (L <= l && r <= R)
	{
		++inv[n];
		sum[n] = r - l + 1 - sum[n];
		return;
	}
	pushDown(n, r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) inverse(L, R, lson);
	if (m < R) inverse(L, R, rson);
	pushUp(n);
}
int query(int L, int R, int l, int r, int n)
{
	if (L <= l && r <= R)
		return sum[n];
	pushDown(n, r - l + 1);
	int m = (l + r) >> 1, ans = 0;
	if (L <= m) ans += query(L, R, lson);
	if (m < R) ans += query(L, R, rson);
	return ans;
}
int main(){
	int t, cas = 0;
	scanf("%d", &t);
	while (t--){
		int n = 0, cnt = 0, k, r, len, q, a, b;
		scanf("%d", &k);
		while (k--){
			scanf("%d", &r), cin >> s, len = s.size();
			for (int i = 0; i < r; ++i)
				for (int j = 1; j <= len; ++j)
					num[n + i * len + j] = s[j - 1] - '0';
			n += r * len;
		}
		build(1, n, 1);
		printf("Case %d:\n", ++cas);
		scanf("%d", &q);
		while (q--){
			cin >> s;
			scanf("%d%d",&a, &b), ++a, ++b;
			if (s[0] == 'F')
				update(a, b, 1, 1, n, 1);
			else if (s[0] == 'E')
				update(a, b, 0, 1, n, 1);
			else if (s[0] == 'I')
				inverse(a, b, 1, n, 1);
			else printf("Q%d: %d\n", ++cnt, query(a, b, 1, n, 1));
		}
	}
}

線段樹 區間改值查詢
0,1 版
