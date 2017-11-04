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


///////*sum,min,max*/
//maxnode 10^6
const int M = 1 << 17;
int sm, mn, mx;
struct Tree{
	int mxv[M], mnv[M], smv[M], set[M], add[M];
	void mt(int m, int L, int R){//維護
		int l = m * 2, r = l + 1;
		if (L < R){
			smv[m] = smv[l] + smv[r];
			mnv[m] = min(mnv[l] , mnv[r]);
			mxv[m] = max(mxv[l] , mxv[r]);
		}
		if (set[m] >= 0)
			mxv[m] = mnv[m] = set[m], smv[m] = (R - L + 1)*set[m];
		if (add[m])
			mnv[m] += add[m], mxv[m] += add[m], smv[m] += (R - L + 1)*add[m];
	}
	void pd(int m){//往下傳標記
		int l = m * 2, r = l + 1;
		if (set[m] >= 0){
			set[l] = set[r] = set[m];
			add[l] = add[r] = 0;
			set[m] = -1;
		}
		if (add[m]){
			add[l] += add[m], add[r] += add[m];
			add[m] = 0;
		}
	
	}
	void update(int m, int L, int R,int y1,int y2,int op,int v){
		int l = m * 2, r = m * 2 + 1;
		if (y1 <= L&&R <= y2){
			if (op == 1)add[m] += v;
			else
				set[m] = v, add[m] = 0;
		}
		else{
			pd(m);
			int M = (L + R) / 2;
			if (y1 <= M)
				update(l, L, M, y1, y2, op, v);
			else mt(l, L, M);
			if (y2 > M)update(r, M + 1, R, y1, y2, op, v);
			else mt(r, M + 1, R);
		}
		mt(m, L, R);
	}
	void query(int m, int L, int R, int s,int y1,int y2){
		if (set[m] >= 0){
			int v = set[m] + add[m] + s;
			sm += v*(min(y2, R) - max(y1, L) + 1);
			mn = min(mn, v);
			mx = max(mx, v);
		}
		else if (y1 <= L&&R <= y2){
			sm += smv[m] + s*(R - L + 1);
			mn = min(mn, mnv[m] + s);
			mx = max(mx, mxv[m] + s);
		}
		else{
			int M = (R + L) >> 1;
			if (y1 <= M)
				query(m * 2, L, M, s + add[m],y1,y2);
			if (y2 > M)
				query(m * 2 + 1, M + 1, R, s + add[m],y1,y2);
		}

	}
};
Tree t[22];
int main(){
	int r, c, m;
	int op, x1, x2, y1, y2, v;
	while (cin >> r >> c >> m){
		memset(t, 0, sizeof(t));
		for (int i = 1; i <= r; i++){
			memset(t[i].set, -1, sizeof(t[i].set));
			t[i].set[1] = 0;
		}
		while (m--){
			cin >> op >> x1 >> y1 >> x2 >> y2;
			if (op < 3){//修改
				cin >> v;
				for (int i = x1; i <= x2; i++)
					t[i].update(1, 1, c, y1, y2, op, v);
			}
			else{
				sm = 0, mx = -1e9, mn = 1e9;
				for (int i = x1; i <= x2; i++)
					t[i].query(1, 1, c, 0, y1, y2);
				printf("%d %d %d\n", sm, mn, mx);
			}
		}
	}
}
