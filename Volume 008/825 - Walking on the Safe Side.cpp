#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
#include<queue>
#include<cmath>
#include<sstream>
using namespace std;


int s[101] = {};
bool b[101][101] = {};//障礙物
int main(){
	int t;
	cin >> t;
	while(t--){
		for (int i = 0; i < 101; i++)
			for (int j = 0; j < 101; j++)
				b[i][j] = 0;
		for (int i = 0; i < 101; i++)
			s[i] = 0;

		int n, m;
		cin >> n >> m;
		string a;
		cin.ignore();
		for (int i = 1; i <= n; i++){
			getline(cin, a);
			stringstream ss;
			int num = 0;
			ss << a;
			ss >> num;
			while (ss >> num)b[i][num]=1;
		}
		if (b[1][1]){
			s[1] = s[2] = 1;
			for (int j = 3; j <= m; j++){
				if (b[1][j])s[j] = 0;
				else
					s[j] += s[j - 1];
			}
		}
		else{
			s[1] = 1;
			for (int j = 2; j <= m; j++){
				if (b[1][j])s[j] = 0;
				else
					s[j] += s[j - 1];
			}
		}

		for (int i = 2; i <= n; i++){
			for (int j = 1; j <= m; j++){
				if (b[i][j])s[j] = 0;
				else
					s[j] += s[j - 1];
			}
		}
		cout << s[m] << endl;
		if (t)cout << endl;
	}
}

dp 走格子路徑方法數 有障礙物
