#include<bits/stdc++.h>
#define inf 100000000
using namespace std;
struct node{
	int to,cap,rev,cost;
};
struct p{
	int u,i;
};
vector<node> e1[20000],e2[20000];
p pre[20000];
int n,s=10001,t=10002,d,f=0,cost,min_cost,max_cost;
inline void ins(int u,int v,int cap,int cost){
	e1[u].push_back((node){v,cap,e1[v].size(),cost});
	e1[v].push_back((node){u,0,e1[u].size()-1,-cost});
	e2[u].push_back((node){v,cap,e2[v].size(),cost});
	e2[v].push_back((node){u,0,e2[u].size()-1,-cost});
}
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int x;
			scanf("%d",&x);
			ins(i,j+n,1,x);
		}
	for (int i=1;i<=n;i++){
		ins(s,i,1,0);
		ins(i+n,t,1,0);
	}
}
void writeit(){
	printf("%d\n%d\n",min_cost,max_cost);
}
int min_spfa(int s,int t){
	queue<int> q;
	int dis[20000];
	bool inq[20000];
	for (int i=0;i<=t;i++)
		dis[i]=inf;
	dis[s]=0;
	inq[s]=1;
	q.push(s);
	while (!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for (int i=0;i<e1[u].size();i++){
			node &eui=e1[u][i];
			int v=eui.to;
			if (eui.cap&&dis[u]+eui.cost<dis[v]){
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
int max_spfa(int s,int t){
	queue<int> q;
	int dis[20000];
	bool inq[20000];
	for (int i=0;i<=t;i++)
		dis[i]=-inf;
	dis[s]=0;
	inq[s]=1;
	q.push(s);
	while (!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for (int i=0;i<e2[u].size();i++){
			node &eui=e2[u][i];
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
void flow(vector<node> *e){
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
	cost=0;
	while ((d=min_spfa(s,t))!=inf)
		flow(e1);
	min_cost=cost;
	cost=0;
	while ((d=max_spfa(s,t))!=-inf)
		flow(e2);
	max_cost=cost;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
