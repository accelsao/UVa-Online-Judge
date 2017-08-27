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


int main(){
	string s;
	while (cin >> s){
		int l = s.size();
		int c1 = 0, c2 = 0;
		char b3[3] = {}, b4[4] = {};
		for (int i = 0; i < l - 2 && c1+c2<2; i++){
			if (s[i] == s[i + 2] && (b3[0] != s[i] || b3[1] != s[i + 1] || b3[2] != s[i + 2])){
				c1++;
				b3[0] = s[i];
				b3[1] = s[i + 1];
				b3[2] = s[i + 2];
			}
			if ((i + 3 < l&&s[i] == s[i + 3] && s[i + 1] == s[i + 2]) && (b4[0] != s[i] || b4[1] != s[i + 1] || b4[2] != s[i + 2] || b4[3] != s[i + 3])){
				if (s[i] != b3[0] || s[i+1] != b3[1] || s[i+2] != b3[2]){
					c2++;
					b4[0] = s[i];
					b4[1] = s[i + 1];
					b4[2] = s[i + 2];
					b4[3] = s[i + 3];
				}
			}
		}
		if (c1 == 2||c2==2||c1+c2==2)
			cout << s << endl;
	}	
}
