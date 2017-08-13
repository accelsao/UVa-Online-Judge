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
	while (cin >> n,n){
		map<string, int>r;
		int b[51][51] = {},x,y;
		
		int move,play=-1;
		char c;
		for (int i = 0; i < n * 2; i++){
			cin >> x >> y >> c;
			if (play != -1)continue;
			x--, y--;
			b[x][y] = c == '+' ? 1 : 0;
			string s;
			for (int j = 0; j < n; j++)
				for (int k = 0; k < n; k++)
					s += b[j][k] + '0';
			if (r[s]){
				play = i % 2?1:2;
				move = i + 1;
				continue;
			}
			for (int i = 0; i < 4; i++){
				string s;
				for (int j = 0; j < n; j++)
					for (int k = 0; k < n; k++)
						s += b[j][k] + '0';
				r[s] = 1;
				
				int bb[51][51] = {};
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						bb[j][n - i - 1] = b[i][j];
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						b[i][j] = bb[i][j];
			
			}
		}
		if (play == -1)
			puts("Draw");
		else
			printf("Player %d wins on move %d\n", play, move);
	}

}
