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

struct pos{
	int d, c;
	//depth,coin
}p[31];
int t, w, n;
void dp(){
	int m[1001] = {};
	bool s[31][1001] = {};
	for (int i = 0; i < n; i++)
		for (int j = t; j >= p[i].d; j--)
			if (m[j - p[i].d] + p[i].c > m[j]){
				m[j] = m[j - p[i].d] + p[i].c;
				s[i][j] = 1;
			}
	cout << m[t] << endl;
	vector<pos>v;
	for (int i = n - 1, j = t; i >= 0; i--)
		if (s[i][j]){
			v.push_back(p[i]);
			j -= p[i].d;
		}
	cout << v.size()<<endl;
	for (int i = v.size() - 1; i >= 0;i--)
		cout << v[i].d / 3 / w << ' ' << v[i].c << endl;
}
int main(){
	int cc = 0;
	while (cin >> t){
		if (cc)cout << endl;
		else cc = 1;
		cin >> w >> n;
		for (int i = 0; i < n; i++){
			cin >> p[i].d >> p[i].c;
			p[i].d = 3 * w*p[i].d;
		}
		dp();
	}
}
