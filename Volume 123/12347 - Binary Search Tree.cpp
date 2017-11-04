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


#define L 10000
int ST[L][15], A[L];
void Build(int n){
	for (int i = 0; i < n; i++)
		ST[i][0] = A[i];
	for (int k = 1, t = 2; t <= n; k++, t <<= 1)//k相當於degree 每層大小2^k
		for (int i = 0; i + t <= n; i++)
			ST[i][k] = max(ST[i][k - 1], ST[i + (t >> 1)][k - 1]);
}
void Post(int i,int n){
	if (i > n)return;
	int m = i, c, t, k;
	while (1){
		c = 0;
		for (k = 1, t = 2; m + t <= n; k++, t <<= 1)
			if (ST[m][k] > ST[m][0]){
				c = 1;
				break;
			}
		if (ST[m][0] > ST[i][0]){
			c = 1;
			break;
		}
		if (!c&&m > n)break;
		m += (t >> 1);
	}
	if (c){
		Post(i + 1, m - 1);
		Post(m, n);
	}
	else
		Post(i + 1, n);
	printf("%d\n", A[i]);
}
int main(){
	int i = 0;
	while (cin >> A[i])
		i++;
	Build(i);
	Post(0,i-1);
}
