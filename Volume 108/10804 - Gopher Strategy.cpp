#include <bits/stdc++.h>
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
const int N=1e3;
using namespace std;
pair<double,double>g[N],h[N];

double dis[N][N];
vector<int>f[N];
int n,m,k;
int a[N],b[N];
int vis[N];
bool dfs(int u){
	for(auto v:f[u]){
		if(vis[v])continue;
		vis[v]=1;
		if(b[v]==-1||dfs(b[v])){
			b[v]=u;
			a[u]=v;
			return 1;
		}
	}
	return 0;
}
int match(){
	int cnt=0;
	Re(a,-1);
	Re(b,-1);
	for(int i=0;i<n;i++)
		if(a[i]==-1){
			Re(vis,0);
			if(dfs(i))cnt++;
			
		}
	return cnt;
}
void build(double t){
	for(int i=0;i<n;i++)f[i].clear();
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(dis[i][j]<t){
				f[i].push_back(j);
			}
}
int main(){Accel
	int t;
	cin>>t;
	int t_c=1;
	while(t--){
		cin>>n>>m>>k;
		double l=0.0,r=0.0;
		for(int i=0;i<n;i++){
			cin>>g[i].F>>g[i].S;
		}
		for(int i=0;i<m;i++){
			cin>>h[i].F>>h[i].S;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				dis[i][j]=sqrt((g[i].F-h[j].F)*(g[i].F-h[j].F)+(g[i].S-h[j].S)*(g[i].S-h[j].S));
				r=max(r,dis[i][j]);
				
			}
		
	//cout<<l<<" "<<r<<endl;
		int ans;
		double res=0;
		for(int i=0;i<200;i++){
			double m=(l+r)/2;
			build(m);
			ans=match();
		//	cout<<m<<" "<<ans<<endl;
			if(ans>=n-k){
				r=m;
				res=m;
			}
			else l=m;
		}
		printf("Case #%d:\n", t_c++);
		
		build(res);
		ans=match();
		
		if(ans>=n-k)printf("%.3lf\n\n", res);
		else
			printf("Too bad.\n\n");
		
		
		
	}
}
