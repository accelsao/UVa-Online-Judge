# Problem statement
Given N receptacles,M numbers of device, K adapters  
The store sells adapters that allow one type of plug to be used in a different type of outlet.
Moreover,adapters are allowed to be plugged into other adapters.  
The store does not have adapters for all possible combinations of plugs and receptacles, but there is essentially an unlimited supply of the ones they do have.  
You want the device be plugged as many as possible  
print the minimum unplugged device  
# Input  
<a href="https://www.codecogs.com/eqnedit.php?latex=1\leq&space;n,m,k\leq&space;100" target="_blank"><img src="https://latex.codecogs.com/gif.latex?1\leq&space;n,m,k\leq&space;100" title="1\leq n,m,k\leq 100" /></a>  
# Solution
There might be at most 400 types  
adapters can combine A-B B->C C->D ,now A is type D  
and there are infinte number of adapters ,and K types  
Max Bipartite Match can be solve by max-flow  
check whether A can adapte to B by floyd warshall  
max-flow  s-source,t-sink
build graph s->device with cap 1  ,and receptacles->t with 1 ,and k adapter u->v cap=inf  
ans=m-maxflow(s,t)  

# Code
``` cpp
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
//const double eps=1e-6;
//typedef complex<double>C;
//const double PI(acos(-1.0));
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
//isalnum() decimal digit or an uppercase or lowercase letter
const int N=420;
const int inf=1e9;
map<string,int>mp;
int ID(string s){
	if(!mp[s])mp[s]=SZ(mp);
	return mp[s];
}
int a[N],b[N];
int f[N][N];
struct edge{
	int from,to,cap,flow;
	edge(int u=0,int v=0,int c=0,int f=0):from(u),to(v),cap(c),flow(f){}
};
struct MF{
	int m;
	vector<edge>E;
	vector<int>g[N];
	int a[N],p[N];
	void init(int n){
		FOR(i,0,n+1)g[i].clear();
		E.clear();
		
	}
	void add(int u,int v,int c){
		E.PB(edge(u,v,c,0));
		E.PB(edge(v,u,0,0));
		m=SZ(E);
		g[u].PB(m-2);
		g[v].PB(m-1); 
	}
	int mf(int s,int t){
		int flow=0;
		while(1){
			FOR(i,s,t)a[i]=0;
			queue<int>q;
			q.push(s);
			a[s]=inf;
			while(SZ(q)){
				int u=q.front();q.pop();
				for(auto v:g[u]){
					edge& e=E[v];
					if(!a[e.to]&&e.cap>e.flow){
						p[e.to]=v;
						a[e.to]=min(e.cap-e.flow,a[u]);
						q.push(e.to);
					}
				}
				if(a[t])break;
			}
			if(!a[t])break;
			for(int u=t;u!=s;u=E[p[u]].from){
				E[p[u]].flow+=a[u];
				E[p[u]^1].flow-=a[u];
			}
			flow+=a[t];
		}
		return flow;
	}
}G;
int main(){Accel
	int T;
	cin>>T;
	while(T--){
		mp.clear();
		int n,m,k;	
		cin>>n;
		Re(f,0);
		string u,v;
		FOR(i,1,n){
			cin>>u;
			a[i]=ID(u);
		}
		cin>>m;
		FOR(i,1,m){
			cin>>u>>v;
			b[i]=ID(v);
		}
		
		cin>>k;
		REP(i,k){
			cin>>u>>v;
			f[ID(u)][ID(v)]=1;
		}
		int z=SZ(mp);
		FOR(k,1,z)
			FOR(i,1,z)
				FOR(j,1,z)
					f[i][j]|=f[i][k]&&f[k][j];
		
		//max-flow
		G.init(z);
		
		FOR(i,1,m)G.add(0,b[i],1);
		FOR(i,1,n)G.add(a[i],z+1,1);
		FOR(i,1,m)
			FOR(j,1,n)
				if(f[b[i]][a[j]])G.add(b[i],a[j],inf);
		//cout<<"123ss"<<endl;
		int ans=G.mf(0,z+1);
		cout<<m-ans<<endl;
		if(T)cout<<endl;
	}
	
}
/*
1
4
A
B
C
D
5
laptop B
phone C
pager B
clock B
comb X
3
B X
X A
X D
*/
```
