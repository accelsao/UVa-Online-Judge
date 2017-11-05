#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<cctype>
#include<sstream>
using namespace std;


//人數至多50人 用longlong 64元素
int main(){
	int t;
	int p[101];
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		int tot = 0;
		for (int i = 0; i < n; i++)
			cin >> p[i], tot += p[i];
		int hs = tot / 2;//1隊重量上限
		int hn = n / 2;//人數上限
		long long dp[45000+1] = {};//重量
		for (int i = 1; i <= hs; i++)dp[i] = 0;
		dp[0] = 1;
		for (int i = 0; i < n; i++)
			for (int j = hs; j >= p[i]; j--)
				dp[j] |= dp[j - p[i]] << 1LL;
		if (n % 2)//奇數 檢查 n/2(hn) 和 n/2+1  ex: 3 有 1或2人的可能 
			while (!(dp[hs] & (1LL << hn)) && !(dp[hs] & (1LL << (hn + 1))))
				hs--;
		else//偶數只有平分可能  其他相差會>1
			while (!(dp[hs] & (1LL << hn)))
				hs--;

		printf("%d %d\n", hs, tot - hs);
		if (t)
			puts("");
	}
}
