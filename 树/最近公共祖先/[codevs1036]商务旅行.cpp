#include<bits/stdc++.h>
using namespace std;
struct node{
	int val,pos;
};
vector<int> e[100000];
node mi[100000][30];
int lg[100000],vis[100000],ver[100000],first[100000],r[100000],d[100000],s[100000],n,m,tot=0,ans=0;
inline void ins(int u,int v){
	e[u].push_back(v);
	e[v].push_back(u);
}
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ins(u,v);
	}
	scanf("%d",&m);
	s[0]=1;
	for (int i=1;i<=m;i++)
		scanf("%d",s+i);
}
void writeit(){
	printf("%d\n",ans);
}
void lgn(){
	lg[1]=0;
	for (long long i=2;i<=2*n-1;i++)
		lg[i]=lg[i>>1]+1;
}
void dfs(int u,int dep){
	vis[u]=1;ver[++tot]=u;first[u]=tot;r[tot]=dep;d[u]=dep;
	for (int i=0;i<e[u].size();i++){
		int &eui=e[u][i];
		if (!vis[eui]){
			dfs(eui,dep+1);
			ver[++tot]=u;
			r[tot]=dep;
		}
	}
}
inline node min(node a,node b){
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
	dfs(1,1);
	rmq();
	for (int i=1;i<=m;i++)
		ans+=dis(s[i-1],s[i]);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
