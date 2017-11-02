#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<string>
using namespace std;

int main() {
	int t, n, L;
	int p[56];
	cin >> t;
	for (int i = 1; i <= t;i++) {
		cin >> n >> L;
		for (int i = 0; i < n; i++)
			cin >> p[i];
		p[n] = L;
		int ans = 0;
		for (int i = 0; i < n; i += 2)
			ans ^= p[i+1] - p[i];
		printf("Case %d: %s\n", i, ans ? "First Player" : "Second Player");
	}
}
/*
沒東西動的人輸
若編號0~n 奇數堆無用  因為堆上加東西 下個人就把i-1堆 補到跟i堆一樣大
但如果是偶數堆
或者說是在0 上加東西 下一個人就沒東西動
所以可以看成把偶數堆 和i+1堆的差(可以補的量)
xorsum起來 
看來n/2堆 取任意數的nim

*/
