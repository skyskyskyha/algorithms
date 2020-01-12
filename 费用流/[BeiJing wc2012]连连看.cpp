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
int a,b,s=20001,t=20002,d,f=0,cost=0;
inline void ins(int u,int v,int cap,int cost){
	e[u].push_back((node){v,cap,e[v].size(),cost});
	e[v].push_back((node){u,0,e[u].size()-1,-cost});
}
inline bool check(int x,int y){
	int tmp=x*x-y*y,z=(int)sqrt(tmp);
	if (z*z!=tmp) return 0;
	while (z){
		tmp=y%z;
		y=z;
		z=tmp;
	}
	return y==1;
}
void readit(){
	scanf("%d%d",&a,&b);
	for (int i=a;i<=b-1;i++)
		for (int j=i+1;j<=b;j++)
			if (check(j,i)){
				ins(i,j+10000,1,i+j);
				ins(j,i+10000,1,i+j);
			}	
	for (int i=a;i<=b;i++){
		ins(s,i,1,0);
		ins(i+10000,t,1,0);
	}
}
void writeit(){
	printf("%d %d\n",f/2,cost/2);
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
	while ((d=spfa(s,t))!=-inf)
		flow();
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
