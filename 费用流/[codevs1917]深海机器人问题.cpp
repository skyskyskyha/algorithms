#include<bits/stdc++.h>
#define inf 100000000
using namespace std;
struct node{
	int to,cap,rev,cost;
};
struct p{
	int u,i;
};
vector<node> e[30000];
p pre[30000];
int a,b,m,n,s=20001,t=20002,d,cost=0;
inline void ins(int u,int v,int cap,int cost){
	e[u].push_back((node){v,cap,e[v].size(),cost});
	e[v].push_back((node){u,0,e[u].size()-1,-cost});
}
void readit(){
	scanf("%d%d",&a,&b);
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m+1;i++)
		for (int j=1;j<=n;j++){
			int x,u=(i-1)*(n+1)+j;
			int v=u+1;
			scanf("%d",&x);
			ins(u,v,1,x);
			ins(u,v,inf,0);
		}
	for (int i=1;i<=n+1;i++)
		for (int j=1;j<=m;j++){
			int x,u=(j-1)*(n+1)+i;
			int v=u+n+1;
			scanf("%d",&x);
			ins(u,v,1,x);
			ins(u,v,inf,0);
		}
	for (int i=1;i<=a;i++){
		int k,x,y;
		scanf("%d%d%d",&k,&x,&y);
		ins(s,x*(n+1)+y+1,k,0);
	}
	for (int i=1;i<=b;i++){
		int r,x,y;
		scanf("%d%d%d",&r,&x,&y);
		ins(x*(n+1)+y+1,t,r,0);
	}	
}
void writeit(){
	printf("%d\n",cost);
}
int spfa(int s,int t){
	queue<int> q;
	int dis[30000];
	bool inq[30000];
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
	while ((d=spfa(s,t))!=-inf)
		flow();
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
