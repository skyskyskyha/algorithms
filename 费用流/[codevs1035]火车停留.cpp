#include<bits/stdc++.h>
#define inf 100000000
using namespace std;
struct node{
	int to,cap,rev,cost;
};
struct p{
	int u,i;
};
vector<node> e[300];
p pre[300];
int n,m,ss=201,s=202,t=203,d,f=0,cost=0;
inline void ins(int u,int v,int cap,int cost){
	e[u].push_back((node){v,cap,e[v].size(),cost});
	e[v].push_back((node){u,0,e[u].size()-1,-cost});
}
void readit(){
	int reach[200],cost[200],stay[200];
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",reach+i,cost+i,stay+i);
		ins(s,i,inf,0);
		ins(i,i+100,1,cost[i]);
		ins(i+100,t,inf,0);
	}
	ins(ss,s,n,0);
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			if (i!=j&&reach[i]+stay[i]<reach[j])
				ins(i+100,j,1,0);
}
void writeit(){
	printf("%.2lf\n",cost*0.01);
}
int spfa(int s,int t){
	queue<int> q;
	int dis[300];
	bool inq[300];
	for (int i=0;i<=t;i++)
		dis[i]=-inf;
	for (int i=0;i<=t;i++)
		inq[i]=0;
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
	f+=tmp;
	cost+=d*tmp;
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
