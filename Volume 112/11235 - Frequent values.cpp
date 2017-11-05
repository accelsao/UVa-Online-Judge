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

#define M 100010
int dp[M][20];
int L[M], R[M], A[M], c[M], p;
//遊程編碼後 c[i]表示第i段出現次數 相鄰,相同數字視同一段
//A[p],L[p],R[p] 位置p(1~n) 所在的"段" 編號 和"段"的左右端點的位置
/*
查詢(a,b) 3個東西的max
(1)
a到a所在的段的末端  的個數 (R[a]-a+1)
(2)
b所在的段的首端到b 的個數(b-L[b]+1)
(3)
找中間的部分 左位置所在的段+1 右-1 因為最左(1),最右(2) 都找過
A[L]+1~A[R]-1 的最大c[] (先用rmq處理)
*/
int query(int l, int r){//rmq query
	if (r < l)return 0;
	int k = log(1.0*r - l + 1) / log(2.0);
	//log y(x)=ln(x)/ln(y)
	//int k = log(1.0*r - l + 1);
	return max(dp[l][k], dp[r - (1 << k) + 1][k]);
	//while (1 << (i + 1) <= Right - Left + 1) ++i;
	//2^k<=區間長度D   k=log2(D)=log10(D/2)
}
int main(){
	int n, q, x, m;
	while (cin >> n&&n){
		cin >> q;
		m = 0;//段的編號
		p = 1 << 17;//pre 跟上個數字不同就換新的段
		for (int i = 1; i <= n; i++){
			cin >> x;
			if (!m || p != x){
				c[++m] = 1; //計數 初始1
				p = x;
			}
			else
				c[m]++;
			A[i] = m;
		}
		c[m + 1] = n;
		int k = 1, l = 1, r = c[1];
		for (int i = 1; i <= m; i++){
		
			for (int j = 1; j <= c[i]; j++)
				L[k] = l, R[k++] = r;
			l += c[i], r += c[i + 1];
		}
		//RMQ 轉成範圍最值查詢 值為一個數字出現的次數
		for (int i = 1; i <= m; i++)
			dp[i][0] = c[i];
		for (int j = 1; (1 << j) <= m; j++)
			for (int i = 1; i + (1 << j) - 1 <= m; i++)
				dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
		int a, b;
		while (q--){
			cin >> a >> b;
			if (L[a] == L[b])printf("%d\n", b - a + 1);//同段 都是同數字 所以直接輸出差距(數量)
			else printf("%d\n", max(max(R[a] - a + 1, b - L[b] + 1), query(A[a] + 1, A[b] - 1)));
		}
	}
}
