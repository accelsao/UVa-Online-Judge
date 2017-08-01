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


int main(){
	int n;
	int t = 1;
	while (cin >> n, n){
		double x[205], y[205] = {};
		double r[101][3] = {}; 
		for (int i = 0; i < n; i++){
			cin >>r[i][0] >> r[i][1] >> r[i][2];
			x[i * 2] = r[i][0] - r[i][2];
			x[i * 2 + 1] = r[i][0] + r[i][2];
			y[i * 2] = r[i][1] - r[i][2];
			y[i * 2 + 1] = r[i][1] + r[i][2];
		}
		sort(x, x + n * 2);
		sort(y, y + n * 2);

		double sum = 0;
		for (int i = 0; i < n * 2 - 1; i++)
			for (int j = 0; j < n * 2 - 1; j++)
				for (int k = 0; k < n; k++)
					if (r[k][0] - r[k][2] <= x[i] && r[k][0] + r[k][2] >= x[i + 1] && r[k][1] - r[k][2] <= y[j] && r[k][1] + r[k][2] >= y[j + 1]){
						sum += (x[i + 1] - x[i])*(y[j + 1] - y[j]);
						break;
					}
		printf("%d %.2lf\n", t++, sum);
	}

}
