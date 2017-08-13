#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<sstream>
using namespace std;


void print(int n, int k,int r[][201]){
	if (!k)return;
	print(r[k][n] - 1, k - 1,r);
	printf("Depot %d at restaurant %d serves restaurant", k,(r[k][n]+n)/2 );
	if (r[k][n] == n)
		printf(" %d\n", n);
	else
		printf("s %d to %d\n", r[k][n], n);
}

int main(){
	int location[201] = {};
	int n, k;
	int a;
	int cas = 1;
	while (cin >> n >> k, n){
		for (int i = 1; i <= n; i++)
			cin >> location[i];
		int d[201][201] = {};
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++){
				int m = (i + j) / 2;
				d[i][j] = 0;
				for (int k = i; k <= j; k++)
					d[i][j] += abs(location[m] - location[k]);
			}

		int r[201][201] = {};
		//p個depot，涵蓋1~n點 值到j 都是同個區域
		int f[201][201] = {};//p個depot，涵蓋1~n點，其距離的總和。f(p,n)

		for (int i = 1; i <= n; i++)
			f[1][i] = d[1][i], r[1][i] = 1;

		for (int p = 2; p <= k; p++)
			for (int i = 1; i <= n; i++){

				f[p][i] = 1e9;
				for (int k = p; k <= i; k++)
					if (f[p - 1][k - 1] + d[k][i] < f[p][i]){
						f[p][i] = f[p - 1][k - 1] + d[k][i];
						r[p][i] = k;
						//從第k個位置往右到第j都屬於這個區域

					}



			}

		printf("Chain %d\n", cas++);
		print(n, k,r);
		printf("Total distance sum = %d\n", f[k][n]);
		puts("");
	}
}
