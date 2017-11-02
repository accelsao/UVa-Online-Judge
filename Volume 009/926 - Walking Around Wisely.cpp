#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
#include<sstream>
using namespace std;


bool b[31][31][2] = {};//右+上
int main(){
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				for (int k = 0; k < 2;k++)
				b[i][j][k] = 0;
		//k=0 右 k=1 上
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i <= x2; i++)
			for (int j = y1; j <= y2; j++){
				if (i + 1 <= n)b[i][j][0] = 1;
				if (j + 1 <= n)b[i][j][1] = 1;
			}
		//b[][][]=1可以走 0不能走
		//k=0 右 k=1 上
		int w;
		cin >> w;
		for (int i = 0; i < w; i++){
			int x, y;
			char p;
			cin >> x >> y >> p;
			if (p == 'S')
				b[x][y - 1][1] = 0;
			else if (p == 'W')
				b[x - 1][y][0] = 0;
			else if (p == 'E')
				b[x][y][0] = 0;
			else
				if (p=='N')
				b[x][y][1] = 0;
		}
		//x1~x2 y1~y2
		long long s[31] = {};
		s[x1] = 1;
		for (int i = x1+1; i <= x2;i++)
			if (b[i-1][y1][0])
				s[i] += s[i - 1];

		for (int j = y1+1; j <= y2; j++){
			if (!b[x1][j - 1][1])
				s[x1] = 0;
			for (int i = x1+1; i <= x2; i++){
				if (!b[i][j-1][1])
					s[i]=0;
				if (b[i - 1][j][0])
					s[i] += s[i - 1];
			}
		}
		cout << s[x2] << endl;
	}
}

//dp
