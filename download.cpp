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

struct p{
	int heigh; int pos;
};
bool land[101][101] = {};
int lei[101][101] = {};//Largest Empty Interval
int main(){
	int m, n;
	while (cin >> m >> n, m){
		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				cin >> land[i][j];
		/*
		-      n       -
		| 0000000000000000
		0000011111000001
		0011111111100001
		m 0111111111110001
		1111111111110011
		1111111111111111
		| 0000000000000000
		*/
		for (int j = 1; j <= n; j++)
			for (int i = 1; i <= m; i++)
				if (!land[i][j])
					lei[i][j] = lei[i - 1][j] + 1;
				else
					lei[i][j] = 0;
		stack<p>s;
		int t = 0;//暫時的面積
		int k = 1;//上個彈出位置
		for (int i = m; i >= 0; i--){
			k = 1;
			for (int j = 1; j <= n; j++){
				if (!lei[i][j]){
					if (s.empty())continue;
					while (!s.empty()){
						t = max(t, s.top().heigh*(k - s.top().pos));
						s.pop();
					}
					k = 0;
				}
				else if (s.empty())
					s.push({ lei[i][j], k });
				else if (lei[i][j] > s.top().heigh)
					s.push({ lei[i][j], k });
				else if (lei[i][j] < s.top().heigh){
					int x = 0;
					while (!s.empty() && lei[i][j] < s.top().heigh){
						t = max(t, s.top().heigh*(k - s.top().pos));
						x = s.top().pos;
						s.pop();
					}
					s.push({ lei[i][j], x });
				}
				k++;
			}
			while (!s.empty()){
				t = max(t, s.top().heigh*(k - s.top().pos));
				s.pop();
			}
		}
		cout << t << endl;
	}
}