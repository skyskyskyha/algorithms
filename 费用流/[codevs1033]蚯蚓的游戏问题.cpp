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
int n,m,k,ss=0,s=9998,t=9999,d,ans=0;
inline void ins(int u,int v,int cap,int cost){
	e[u].push_back((node){v,cap,e[v].size(),cost});
	e[v].push_back((node){u,0,e[u].size()-1,-cost});
}
void readit(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=0;i<n;i++)
		for (int j=0;j<m+i;j++){
			int x,u=i*(m+n)+j+1,v=i*(m+n)+j+(n+m)*n+1;
			scanf("%d",&x);
			ins(u,v,1,x);
			if (i<n-1){
				ins(v,u+m+n,1,0);
				ins(v,u+m+n+1,1,0);
			}
			if (i==0) ins(s,u,1,0);
			if (i==n-1) ins(v,t,1,0);
		}
	ins(ss,s,k,0);	
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
void flow(int s,int t){
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
	while ((d=spfa(ss,t))!=-inf)
		flow(ss,t);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
