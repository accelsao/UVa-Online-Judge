# Problem statement
Given N width of the cave  
input N  
ith-cave ceil and floor  
Furthermore, there is some electrical wiring on the ceiling of the cave. You can never be sure if the  
insulation is intact, so you want to keep the fuel level just below the ceiling at every point. You can  
pump the fuel to whatever spots in the cave you choose, possibly creating several ponds. Bear in mind  
though that the fuel is a liquid, so it minimises its gravitational energy, e.g., it will run evenly in every  
direction on a flat horizontal surface, pour down whenever possible, obey the rule of communicating  
vessels, etc. As the cave is degenerate and you can make the space between the fuel level and the  
ceiling arbitrarily small, you actually want to calculate the maximum possible area of ponds that  
satisfy aforementioned rules.  
# Input
* <a href="https://www.codecogs.com/eqnedit.php?latex=1\leq&space;10^{6}\leq&space;n" target="_blank"><img src="https://latex.codecogs.com/gif.latex?1\leq&space;10^{6}\leq&space;n" title="1\leq 10^{6}\leq n" /></a>  
* <a href="https://www.codecogs.com/eqnedit.php?latex=0\leq&space;floor_i<&space;ceil_i\leq1000" target="_blank"><img src="https://latex.codecogs.com/gif.latex?0\leq&space;floor_i<&space;ceil_i\leq1000" title="0\leq floor_i< ceil_i\leq1000" /></a>  
# Solution
Because we cant let fuel cover other ceil, so maintain the possible Height for each interval that come from left and right  
```cpp
#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define SZ(a) ((int)a.size())
#define endl "\n" 
using namespace std;
//typedef complex<double>C;
//const double PI(acos(-1.0));
//const double eps(1e-8);
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
const int N=55;
const LL INF=1e18;
const int M=1e9+7;
int main(){Accel
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>L(n+1),R(n+1),l(n+1),r(n+1);
		FOR(i,1,n)cin>>L[i];
		FOR(i,1,n)cin>>R[i];
		int ls=1001;
		//from left
		for(int i=1;i<=n;i++){
			l[i]=max(min(ls,R[i]),L[i]);
			ls=l[i];
		}
		ls=1001;
		for(int i=n;i>=1;i--){
			r[i]=max(min(ls,R[i]),L[i]);
			ls=r[i];
		}
		int ans=0;
		FOR(i,1,n)
			ans+=min(r[i],l[i])-L[i];
		cout<<ans<<endl;
	}
}
```
