#include<string>
#include<cstdio>
#include<iostream>
#include<queue>
#include<cmath>
#include<stack>
#include<cctype>
#include<cstring>
#include<sstream>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include <regex>
#include<cassert>
using namespace std;



/*
更動後的值x在 x-d<=y<=x+d 
轉移 min{f(i-1,y)}+|x-h|=f(i,x)
*/
#define N 101
#define INF 1LL<<60
#define LL long long
#define scanf scanf_s
LL d;
int n,p[N];
long long dp[2][N*N * 2];//修改的值 2N 有N個數  O(n^3)
vector<long long>v;
vector<long long>::iterator it;
int main(){
	int t;
	cin >> t;
	while (t--){
		v.clear();
		cin >> n >> d;
		for (int i = 0; i < n; i++)
			cin >> p[i];
		if (abs(p[0] - p[n - 1]) > (n - 1)*d){
			puts("impossible");
			continue;
		}
		for (int i = 0; i < n; i++)
			for (int j = -(n - 1); j <= n - 1; j++)
				v.push_back(p[i] + j*d);//所有費用可能
		sort(v.begin(), v.end());
		it= unique(v.begin(), v.end());//刪除重複 由小排序
		v.resize(distance(v.begin(), it));
		int m = v.size();
		for (int i = 0; i < m; i++){
			dp[0][i] = INF;
			if (v[i] == p[0])dp[0][i] = 0;//p[0]不能修改所以給0
			
		//d[i][j] 已修改了i個數 第i個數改為p[j] 的最小費用
		int t = 0;
		for (int i = 1; i < n; i++){
			int k = 0;
			for (int j = 0; j < m; j++){
				while (k < m&&v[k] < v[j] - d)k++;//兩者值小於d
				while (k + 1 < m&&v[k + 1] <= v[j] + d&&dp[t][k + 1] <= dp[t][k])//找最小值 
					k++;
				if (dp[t][k] == INF)dp[t ^ 1][j] = INF;
				else dp[t^1][j] = dp[t][k] + abs(v[j] - p[i]);	
			}
			t ^= 1;
		}
		for (int i = 0; i < m; i++)
			if (p[n - 1] == v[i]){
				printf("%lld\n", dp[t][i]);
				break;
			}
	}
}
