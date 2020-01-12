#include<bits/stdc++.h>
#define inf 100000000
using namespace std;
struct node{
	int to,cap,rev,cost;
};
struct p{
	int u,i;
};
vector<node> e[3000];
p pre[3000];
int a[2000],n,s=2001,t=2002,ave=0,d,cost=0;
inline void ins(int u,int v,int cap,int cost){
	e[u].push_back((node){v,cap,e[v].size(),cost});
	e[v].push_back((node){u,0,e[u].size()-1,-cost});
}
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",a+i);
		ave+=a[i];
	}
	ave/=n;
	for (int i=1,j;i<=n;i++){
		a[i]-=ave;
		if (a[i]>0) ins(s,i,a[i],0);
		else ins(i+n,t,-a[i],0);
		j=i-1;
		if (j==0) j=n;
		ins(i,j,inf,1);
		ins(i,j+n,inf,1);
		j=i+1;
		if (j>n) j=1;
		ins(i,j,inf,1);
		ins(i,j+n,inf,1);
	}
}
void writeit(){
	printf("%d\n",cost);
}
int spfa(int s,int t){
	queue<int> q;
	int dis[3000];
	bool inq[3000];
	for (int i=0;i<=t;i++)
		dis[i]=inf;
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
	while ((d=spfa(s,t))!=inf)
		flow();
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
