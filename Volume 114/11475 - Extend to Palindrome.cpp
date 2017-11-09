#include<iostream>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
using namespace std;

string s, r;
int f[100010];
int main() {
	while (getline(cin, s)) {
		r = "";
		for (int i = 0; i < s.size(); i++)
			r = s[i] + r;
		for (int i = 1, j = f[0] = -1; i < r.size(); i++) {
			while (j >= 0 && r[i] != r[j + 1])
				j = f[j];
			if (r[j + 1] == r[i])j++;
			f[i] = j;
		}
		int i, j;
		for (i = 0, j = -1; i<s.size(); i++) {
			while (j >= 0 && s[i] != r[j + 1])
				j = f[j];
			if (s[i] == r[j + 1])j++;
		}
		cout << s ;
		for (int i = j + 1; i < r.size(); i++)
			cout << r[i];
		cout << endl;
	}
}
