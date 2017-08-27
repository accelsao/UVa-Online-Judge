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
	int t;
	cin >> t;
	int s1[1501] = {};
	int s2[1501] = {};
	for (int i = 1; i <= t; i++){
		int n,l1,l2;
		int lcis[1501] = {};//leng
		cin >> n;
		l1 = n;
		for (int i = 0; i < n; i++)
			cin >> s1[i];
		cin >> n;
		l2 = n;
		for (int i = 0; i < n; i++)
			cin >> s2[i];

		for (int i = 0; i < l1; i++){
			int tmp = 0;
			for (int j = 0; j < l2; j++){
				if (s1[i]>s2[j] && lcis[j] > tmp){//更新目前長度
					tmp = lcis[j];
				}
				if (s2[j] == s1[i] && lcis[j] < tmp+1)//相等有希望加長  若 (目前長度tmp)+1>(j位置的長度) 則(j位置的長度)更新為tmp+1 
					lcis[j]=tmp+1;
			}
		}
		int ans = 0;
		for (int i = 0; i < l2; i++)
			if (lcis[i]>ans)
				ans = lcis[i];
		cout << ans<< endl;
	}
}
