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
#include<vector>
using namespace std;

#define M 1005
#define LL long long
LL dp[M][M], x[M], w[M];
LL sw[M] = {}, sxw[M] = {};
LL cross(LL x1, LL y1, LL x2, LL y2){
	return x1*y2 - x2*y1;
}
int main(){
	int n, m;
	while (cin >> n >> m){
		for (int i = 1; i <= n; i++)
			cin >> x[i] >> w[i];
		for (int i = 1; i <= n; i++){
			sw[i] = sw[i - 1] + w[i];
			sxw[i] = sxw[i - 1] + x[i] * w[i];
		}

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				dp[i][j] = (1LL << 60);
		dp[0][0] = 0;

		deque<pair<LL,LL>>q;
		for (int i = 1; i <= m; i++){
			q.clear();
			for (int j = i; j <= n; j++){
				//cross(x1-x0,y1-y0,x2-x0,y2-y0)
				//x2=sw[k] y=dp[k][j-1]+sxw[k] 
				// sw[j-1] dp[j-1][i-1]+sxw[j-1]  //在這裡 i,j 不是上面的i,j
				while (q.size() > 1 && cross(q.back().first - q[q.size() - 2].first, q.back().second - q[q.size() - 2].second, sw[j - 1] - q[q.size() - 2].first, dp[j - 1][i - 1] + sxw[j - 1] - q[q.size() - 2].second) < 0)//PxQ叉積<0代表新加入點斜率更低 不合法
					q.pop_back();
				//由下面的定義 1<=k<i  sw[k]=sw[i-1] (這裡i 換成j)
				q.push_back({ sw[j - 1], dp[j - 1][i - 1] + sxw[j - 1] });
				while (q.size() > 1 && q[1].second - q[0].second < (q[1].first - q[0].first)*x[j])//斜率<x[j]  q[1]比q[0] 更優 
					q.pop_front();
				//這時候q.front() 最優解 且是凸點
				// y=a*x+b 【dp[k][j-1] + sxw[k]】 =  【p[i].h 】* 【sw[k]】  +   【 dp[i][j] +  sxw[i] -sw[i]*p[i].h】 ;
				//i,j 迴圈關係 裡面i,j對調
				//dp[j][i]+  sxw[j] -sw[j]*p[j].h=y-a*x
				LL val = q.front().second - x[j] * q.front().first;
				//dp[j][i]=val-(sxw[j] -sw[j]*p[j].h)
				dp[j][i] = val - (sxw[j] - sw[j] * x[j]);
			}
		}
		printf("%lld\n", dp[n][m]);
	}
}
