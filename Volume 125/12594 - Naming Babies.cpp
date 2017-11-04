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

string str, name;
const int N = 20010;
int n, m;
deque<int>q;
int p[30];//pos
#define LL long long 
LL s1[N], s2[N], s3[N], val[N], dp[510][N];
LL up(int l, int k, int i) {//拿分子
	return (dp[i - 1][l] - s2[l] + s3[l] + l * s1[l]) - (dp[i - 1][k] - s2[k] + s3[k] + k * s1[k]);
}
LL dw(int l, int k) {
	return l - k;
}
int T = 1;
void solve(){
	for (int i = 1; i <= n; i++)dp[1][i] = s2[i] - s3[i];
	for (int i = 2; i <= m; i++){
		q.clear();
		q.push_back(i - 1);
		for (int j = i; j <= n; j++){
			//若第二點較第一點優 把第一點退出
			while (q.size() > 1 && up(q[1], q[0], i) <= s1[j] * dw(q[1], q[0]))
				q.pop_front();
			int k = q.front();
			dp[i][j] = dp[i - 1][k] + s2[j] - s2[k] - k * (s1[j] - s1[k]) - (s3[j] - s3[k]);
			while (q.size() > 1 && up(j, q.back(), i)*dw(q.back(), q[q.size() - 2]) <= up(q.back(), q[q.size() - 2], i)*dw(j, q.back()))
				q.pop_back();
			q.push_back(j);
		}
	}
	printf("Case %d: %lld\n", T++, dp[m][n]);
}
int main(){
	int t;
	cin >> t;
	while (t--){
		cin >> str >> m;
		for (int i = 0; i < str.size(); i++)
			p[str[i] - 'a'] = i;
		cin >> name;
		n = name.size();
		val[1] = p[name[0] - 'a'];
		s1[1] = val[1], s2[1] = 0, s3[1] = val[1] * val[1];
		for (int i = 1; i < n; i++) {
			val[i + 1] = p[name[i] - 'a'];
			s1[i + 1] = s1[i] + val[i + 1];
			s2[i + 1] = s2[i] + i * val[i + 1];
			s3[i + 1] = s3[i] + val[i + 1] * val[i + 1];
		}
		solve();
	}
}
/*
dp[i][j]表示前i个字符分成j段的最小代价和
dp[i][j] = dp[k][j - 1] + (0 * pos[k + 1] + 1 * pos[k + 2] + … + (i - k - 1) * pos[i]) - (pos[k + 1] ^ 2 + pos[k + 2] ^ 2 + … + pos[i] ^ 2)
＝dp[k][j - 1] + (k * pos[k + 1] + (k + 1) * pos[k + 2] + … + (i - 1) * pos[i]) - k * (pos[k + 1] + pos[k + 2] + … + pos[i]) - (pos[k + 1] ^ 2 + pos[k + 2] ^ 2 + … + pos[i] ^ 2)
s1=(pos[k + 1] + pos[k + 2] + … + pos[i])
s2=（k * pos[k + 1] + (k + 1) * pos[k + 2] + … + (i - 1) * pos[i] ）
s3=(pos[k + 1] ^ 2 + pos[k + 2] ^ 2 +… + pos[i] ^ 2)

dp[i][j] = dp[k][j - 1] + (s2[i] - s2[k]) - k * (s1[i] - s1[k]) - (s3[i] - s3[k])

设l > k，且点l比点k优
则dp[k][j - 1] + (s2[i] - s2[k]) - k * (s1[i] - s1[k]) - (s3[i] - s3[k]) >= dp[l][j - 1] + (s2[i] - s2[l]) - l * (s1[i] - s1[l]) - (s3[i] - s3[l])
化简得s1[i] >= ( (dp[l][j - 1] - s2[l] + s3[l] + l * s2[l]) - (dp[k][j - 1] - s2[k] + s3[k] + k * s2[k]) ) / (l - k)
因为s1随着i的递增而递增，所以得到斜率方程
*/
//斜率DP優化
