#include<bits/stdc++.h>
#define inf 100000000
using namespace std;
struct node{
	int to,cap,rev,cost;
};
struct p{
	int u,i;
};
vector<node> e[10000];
p pre[10000];
int n,k,s=0,t=6000,d,ans=0;
inline void ins(int u,int v,int cap,int cost){
	e[u].push_back((node){v,cap,e[v].size(),cost});
	e[v].push_back((node){u,0,e[u].size()-1,-cost});
}
void readit(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			ins((i-1)*n+j,(i-1)*n+j+n*n,1,x);
			ins((i-1)*n+j,(i-1)*n+j+n*n,k-1,0);
			if (i<n) ins((i-1)*n+n*n+j,i*n+j,k,0);
			if (j<n) ins((i-1)*n+n*n+j,(i-1)*n+j+1,k,0);
		}
	ins(s,1,k,0);
	ins(n*n*2,t,k,0);
}
void writeit(){
	printf("%d\n",ans);
}
int spfa(int s,int t){
	queue<int> q;
	int dis[10000];
	bool inq[10000];
	for (int i=0;i<=t;i++)
		dis[i]=-inf;
	dis[s]=0;
	inq[s]=1;
	q.push(s);
	while (!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for (int i=0;i<e[u].size();i++){
			node &eui=e[u][i];
			int v=eui.to;
			if (eui.cap&&dis[u]+eui.cost>dis[v]){
				dis[v]=dis[u]+eui.cost;
				pre[v].u=u;
				pre[v].i=i;
				if (!inq[v]){
					q.push(v);
					inq[v]=1;
				}
			}
		}
	}
	return dis[t];
}
void flow(){
	int u,tmp=inf,i;
	for (int v=t;v!=s;){
		u=pre[v].u;
		i=pre[v].i;
		tmp=min(tmp,e[u][i].cap);
		v=u;
	}
	ans+=d*tmp;
	for (int v=t;v!=s;){
		u=pre[v].u;
		i=pre[v].i;
		e[u][i].cap-=tmp;
		e[v][e[u][i].rev].cap+=tmp;
		v=u;
	}
}
void work(){
	while ((d=spfa(s,t))!=-inf)
		flow();
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
