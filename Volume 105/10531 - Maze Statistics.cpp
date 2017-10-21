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
#include<unordered_map>
#include<stack>
using namespace std;

typedef long long LL;
const int HASH = 30007;
const int STATE = 300;
const int MAXD = 8;
const double EPS = 1e-15;
int n, m;
double maze[MAXD][MAXD];
int code[MAXD], ch[MAXD];

//14
void decode(int st){
	for (int i = m; i >= 0; --i){
		code[i] = st & 7;
		st >>= 3;
	}
}

int encode(){
	int st = 0;
	int i, cnt = 1;
	memset(ch, -1, sizeof(ch));
	ch[0] = 0, ch[1] = 1;
	for (i = 0; i <= m; ++i){
		if (ch[code[i]] == -1)
			ch[code[i]] = ++cnt;
		code[i] = ch[code[i]];//long long 2^63
		st <<= 3;
		st |= code[i];
		//code 最多到15
	}
	return st;
}

struct HASHMAP{
	int head[HASH], next[STATE], size;
	int state[STATE];
	double f[STATE];
	void clear(){
		size = 0;
		memset(head, -1, sizeof(head));
	}
	void push(int st, double ans){
		int i;
		decode(st);
		for (i = 0; i <= m; ++i)
			if (code[i]==1)
				break;
		if (i == m + 1) //如果编号为1的连通块不存在，那就不可行
			return;
		int x = st%HASH;
		for (i = head[x]; i != -1; i = next[i])
			if (st == state[i]){
				f[i] += ans;
				return;
			}
		f[size] = ans;
		state[size] = st;
		next[size] = head[x];
		head[x] = size++;
	}
}hm[2];


void dp_blank(int i, int j, int cur){
	if (fabs(1.0 - maze[i][j]) < EPS)//機率如果是0
		return;
	int lef, up;
	for (int k = 0; k < hm[cur].size; ++k){
		if (fabs(hm[cur].f[k]) < EPS)
			continue;
		decode(hm[cur].state[k]);
		lef = code[j - 1], up = code[j];
		if (lef && up){//兩邊都有 連起來
			if (lef != up){	//code 都會更新 然後從0開始出現 不同數字算是不同連通塊 所以如果不同連通塊要連通 把數字大的都變小的 
				if (lef < up)
					swap(lef, up);
				for (int t = 0; t <= m; ++t)
					if (code[t] == lef)
						code[t] = up;		
			}
		}
		else{
			if (lef || up)//只有單邊有接起來
				code[j] = lef | up;
			else
				code[j] = m + 1;//新建連通塊
		}
		hm[cur ^ 1].push(encode(), hm[cur].f[k] * (1.0 - maze[i][j]));//連通機率
	}
}

void dp_block(int i, int j, int cur){
	if (fabs(maze[i][j])<EPS) 
		return;	
	int k;
	for (k = 0; k < hm[cur].size; ++k){
		if (fabs(hm[cur].f[k])<EPS) 
			continue;
		decode(hm[cur].state[k]);
		code[j] = 0;//同理
		hm[cur ^ 1].push(encode(), hm[cur].f[k] * maze[i][j]);
	}
}

double solve(){
	int cur = 0;
	memset(code, 0, sizeof(code));
	hm[cur].clear();
	code[1] = 1;
	hm[cur].push(encode(), 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j){
			hm[cur ^ 1].clear();
			dp_blank(i, j, cur);//如果可以過
			dp_block(i, j, cur);//如果是障礙物
			cur ^= 1;
		}
	double ret = 0;
	for (int i = 0; i < hm[cur].size; ++i){
		decode(hm[cur].state[i]);
		if (code[m] == 1) //都連通
			ret += hm[cur].f[i];
		
	}
	return ret;
}

void work(){
	double sum = solve();//有解迷宮的機率
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j){
			double cache = maze[i][j];
			maze[i][j] = 1.0;//如果這格是障礙物
			double ss = solve();
			printf("%lf%c", ss*cache / sum, (j == m) ? '\n' : ' ');
			maze[i][j] = cache;
		}
}

int main(){
	int T;
	cin >> T;
	while (T--){
		cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				cin >> maze[i][j];
		work();
	}
}
