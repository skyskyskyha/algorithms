#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,cap,rev;
};
vector<node> e[1000];
bool used[1000];
int n,m,ans;
inline void ins(int u,int v,int c){
	e[u].push_back((node){v,c,e[v].size()});
	e[v].push_back((node){u,0,e[u].size()-1});
}
void readit(){
	scanf("%d%d",&n,&m);
	int u,v,c;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&u,&v,&c);
		ins(u,v,c);
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
	ans=max_flow(1,m);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
