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
	for (int k = 1; k <= t;k++){
		int n;
		cin >> n;
		int ans = 0;
		int sum = 0;
		int a;
		int tempstart = 1;
		int start=0, end=0;
		int lastcycle = 0;
		for (int i = 1; i < n; i++){
			cin >> a;
			sum += a;
			if (sum < 0){ sum = 0; tempstart = i + 1;  }
			else if(sum>ans){
				ans = sum;
				start = tempstart;
				end = i;
				lastcycle = i - tempstart;
			}
			else if (sum == ans){
				if (i - tempstart > lastcycle){
					start = tempstart;
					end = i;
					lastcycle = i - tempstart;
				}
			}
		}
		if (start <= end&&start)
			printf("The nicest part of route %d is between stops %d and %d\n", k, start, end+1);
		else
			printf("Route %d has no nice parts\n", k);
	}
	
}
// 貪心 路線加權總和最大 + 記錄點
