#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,cap,rev;
};
vector<node> e[10000];
bool used[10000];
int a[1000][1000],h[10000],s[10000],n,m,k,ans;
inline void ins(int u,int v,int c){
	e[u].push_back((node){v,c,e[v].size()});
	e[v].push_back((node){u,0,e[u].size()-1});
}
inline void add(int t){
	for (int i=0;i<=n+1;i++)
		ins((t-1)*(n+2)+i,t*(n+2)+i,10000000);
	for (int i=1;i<=m;i++)
		ins((t-1)*(n+2)+a[i][(t-1)%s[i]+1],t*(n+2)+a[i][t%s[i]+1],h[i]);
}
void readit(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=m;i++){
		scanf("%d%d",h+i,s+i);
		for (int j=1;j<=s[i];j++){
			scanf("%d",a[i]+j);
			if (a[i][j]==-1) a[i][j]=n+1;
		}
	}
}
void writeit(){
	printf("%d\n",ans);
}
int dfs(int v,int t,int f){
	if (v==t) return f;
	used[v]=1;
	for (int i=0;i<e[v].size();i++){
		node &evi=e[v][i];
		if (!used[evi.to]&&evi.cap>0){
			int c=dfs(evi.to,t,min(f,evi.cap));
			if (c>0){
				evi.cap-=c;
				e[evi.to][evi.rev].cap+=c;
				return c;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	int flow=0;
	for (;;){
		memset(used,0,sizeof(used));
		int f=dfs(s,t,10000000);
		if (f==0) return flow;
		flow+=f;
	}
}
void work(){
	for (int t=1;t<=100;t++){
		add(t);
		k-=max_flow(0,(t+1)*(n+2)-1);
		if (k<=0){
			ans=t;
			return;
		}
	}
	ans=0;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
