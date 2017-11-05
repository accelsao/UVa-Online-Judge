#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<functional>
#include<fstream>
#include<stack>
#include<ctime>
#include<vector>
using namespace std;

void bst(int l, int r, int h){
	if (h == 0 || l > r)return;
	//root 靠左 填滿右子樹
	int rs = (1 << (h - 1)) - 1;//right subtree space
	int rt = r - rs;
	if (rt < l)rt = l;//rs>r
	printf(" %d", rt);
	bst(l, rt - 1, h - 1);
	bst(rt + 1, r, h - 1);
}
int main(){
	int t=1;
	int n, h;
	while (cin >> n >> h,n+h){
		printf("Case %d:", t++);
		if ((1 << h) - 1 < n){
			puts(" Impossible.");
			continue;
		}
		if (h > n)  h = n;
		bst(1, n, h);
		puts("");
	}

}
