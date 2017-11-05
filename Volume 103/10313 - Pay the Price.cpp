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

//dp[i][j] 表示i元最多用j個硬幣的方法數
long long dp[301][1001] = {};
int main(){
	dp[0][0] = 1;
	for (int i = 0; i < 301; i++)
		for (int j = 0; j+i< 301; j++)
			//用了k個硬幣組成j + i元的方法數是由用了k-1個硬幣組成j元的方法數而來
			for (int k = 1; k <= 1000; k++) 
				dp[j + i][k] += dp[j][k - 1]; 
				
			
	//dp[6][3]=dp[6][2]+dp[5][2]+dp[4][2]+dp[3][2]+dp[2][2]+dp[1][2]+dp[0][2]
	string s;
	int n[3];
	while (getline(cin, s)){
		stringstream ss(s);
		int i = 0;
		while (ss >> n[i])i++;
		switch (i){
		case 1: printf("%lld\n", dp[n[0]][1000]); break;
		case 2: printf("%lld\n", dp[n[0]][n[1]]); break;
		case 3: // 因為當L1 == 0會越界 因此要多個if判斷
			if (n[1] == 0) printf("%lld\n", dp[n[0]][n[2]]);
			else printf("%lld\n", dp[n[0]][n[2]] - dp[n[0]][n[1] - 1]);
			break;
		}
	
	}
}
