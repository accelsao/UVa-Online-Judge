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
//#pragma GCC optimize(2)
using namespace std;
const int N=1e5+1;
const int M=998244353;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int t=0;while(x){t+=BIT[x];x-=x&-x;}return t;}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)


int t,s,n;
int w[25];
bool f=0;
int b[25];
void dfs(int id,int res,int j,int cnt){
	
//	if(cnt){
//		cout<<id<<": ";
//		for(int k=0;k<n;k++)
//			if(b[k])cout<<k<<" ";
//		cout<<endl;
//	}
//	
	if(f)return ;
	if(id==4&&cnt==n){
		f=1;
		return ;
	}
	for(int i=j;i<n;i++){
		if(b[i])continue;
		if(res>=w[i]){
			b[i]=1;
			if(res==w[i])
				dfs(id+1,s, 0,cnt+1);
			else
				dfs(id, res-w[i], i+1,cnt+1);
			b[i]=0;
		}
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){

	
//	freopen("01.txt","w",stdout);
	cin>>t;
	while(t--){

		cin>>n;
		s=0;
		int z=0;
		for(int i=0;i<n;i++)
			cin>>w[i],s+=w[i],z=max(z,w[i]);
		if(s%4){
			puts("no");continue;
		}
		s/=4;
		if(z>s){
			puts("no");continue;
		}
		sort(w,w+n,cmp);
		
		
		f=0;
		dfs(0,s,0,0);
		if(f)puts("yes");
		else puts("no");
	}

	
}

/*
3
1
8 10 27 30 7 2 35 1 36
5 10 20 30 40 50
8 1 7 2 6 4 4 3 5
*/
