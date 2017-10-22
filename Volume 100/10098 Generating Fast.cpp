#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

char s[11] = {};
char ans[11] = {};//暫存
char c;
int n;
bool p[27] = {};
int x = 0;
int t;
void backtracking(int n){
	if (n ==x){
		for (int i = 0; i < x; i++)
			cout << ans[i];
		cout << '\n';
		return;
	}
	char lc=' ';
	for (int i = 0; i < x; i++){
		if (!p[i]&&s[i]!=lc){//避免 重複 last char  
			ans[n] =lc= s[i];
			p[i] = 1;
			backtracking(n + 1);
			p[i] = 0;
		}
	}
}

int main(){
	cin >> t;
	while (t--){
		for (int i = 0; i < 26; i++)
			p[i] = 0;
		string ss;
		cin >> ss;
		x = ss.size();
		sort(ss.begin(), ss.end());
		for (int i = 0; i < x; i++)
			s[i] = ss[i];
		backtracking(0);
		cout << '\n';
	}
}
