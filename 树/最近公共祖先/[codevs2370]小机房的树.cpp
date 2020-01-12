#include<bits/stdc++.h>
using namespace std;
struct node1{
	int val,pos;
};
struct node2{
	int to,cost;
};
struct node3{
	int u,v;
};
vector<node2> e[100000];
node1 mi[100000][30];
node3 q[100000];
int lg[100000],vis[100000],ver[100000],first[100000],r[100000],d[100000],ans[100000],n,m,tot=0;
inline void ins(int u,int v,int c){
	e[u].push_back((node2){v,c});
	e[v].push_back((node2){u,c});
}
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++){
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		ins(u+1,v+1,c);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d",&q[i].u,&q[i].v);
		q[i].u++;
		q[i].v++;
	}
}
void writeit(){
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}
void lgn(){
	lg[1]=0;
	for (long long i=2;i<=2*n-1;i++)
		lg[i]=lg[i>>1]+1;
}
void dfs(int u,int dep,int dis){
	vis[u]=1;ver[++tot]=u;first[u]=tot;r[tot]=dep;d[u]=dis;
	for (int i=0;i<e[u].size();i++){
		node2 &eui=e[u][i];
		if (!vis[eui.to]){
			dfs(eui.to,dep+1,dis+eui.cost);
			ver[++tot]=u;
			r[tot]=dep;
		}
	}
}
inline node1 min(node1 a,node1 b){
	if (a.val<b.val) return a;
	else return b;
}
void rmq(){
	int temp=lg[2*n-1];
	for (int i=1;i<=2*n-1;i++){
		mi[i][0].val=r[i];
		mi[i][0].pos=i;
	}
	for(int j=1;j<=temp;j++)
		for (int i=1;i<=2*n-1;i++)
	    	if (i+(1<<j)-1<=2*n-1)
	    		mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
}
inline int query(int l,int r){
	int k=lg[r-l+1];
	return min(mi[l][k],mi[r-(1<<k)+1][k]).pos;
}
inline int lca(int u,int v){
	int x=first[u],y=first[v];
	if (x>y) swap(x,y);
	return ver[query(x,y)];
}
inline int dis(int x,int y){
	int l=lca(x,y);
	return d[x]+d[y]-2*d[l];
}
void work(){
	lgn();
	dfs(1,1,0);
	rmq();
	for (int i=1;i<=m;i++)
		ans[i]=dis(q[i].u,q[i].v);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
