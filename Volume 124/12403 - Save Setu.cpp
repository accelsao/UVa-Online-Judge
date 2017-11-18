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
	int t;
	cin >> t;
	int sum = 0;
	while (t--){
		cin >> s;
		int n;
		
		if (s == "donate"){
			cin >> n;
			sum += n;
		}
		else cout << sum << endl;
	}

}
