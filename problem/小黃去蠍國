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
using namespace std;



long long d[15][15] = {};
int main(){
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 9; j++){
			long long a = pow(10, i - 1)*pow(j, i);
			d[i][j] = a + d[i - 1][j] - d[i - 1][j - 1] + d[i][j - 1];
		}
	int a, b;
	while (cin >> a >> b)
		printf("%lld\n", d[a][b]);
}
