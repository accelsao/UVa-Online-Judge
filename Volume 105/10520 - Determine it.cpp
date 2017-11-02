#include <iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
using namespace std;


long long a[21][21];


int main(){
long long n, an1;
	while (cin >> n >> an1){
		a[n][0] = 1;
		a[n][1] = an1;
		for (int j = 2; j <= n; j++){
			int m = 0;
			for (int k = 1; k < j; k++)
				if (a[n][k] + a[n][k] > m)m = a[n][k] + a[n][k];
			a[n][j] = m;
		}
		for (int i = n - 1; i > 0; i--)
			for (int j = 0; j <= n;j++){
			//n-1 0
				if (i >= j){
					long long m1 = 0;
					for (int k = i + 1; k <= n; k++)
						if (a[k][1] + a[k][j] > m1)m1 = a[k][1] + a[k][j];
					a[i][j] = m1;
					if (j > 0){
						long long m2 = 0;
						for (int k = 1; k < j; k++)
							if (a[i][k] + a[n][k]>m2 )m2 = a[i][k] + a[n][k];
						a[i][j]+=m2;
					}
				}
				else{
					long long m = 0;
					for (int k = i; k < j; k++)
						if (a[i][k] + a[k + 1][j] > m)m = a[i][k] + a[k + 1][j];
					a[i][j] = m;
				}
		}
		cout << a[1][n] << endl;
	}
}
