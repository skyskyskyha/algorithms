#include<bits/stdc++.h>
using namespace std;
struct tree{
	int l,r,tag,sum;
};
struct ope{
	int p,x,y;
};
vector<int> e[200000];
tree tr[500000];
ope q[200000];
int dep[200000],siz[200000],son[200000],fa[200000],top[200000],id[200000],ans[200000],n,m,num=0,k=0;
inline void ins(int u,int v){
	e[u].push_back(v);
	e[v].push_back(u);
}
void readit(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ins(u,v);
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&q[i].p,&q[i].x,&q[i].y);
}
void writeit(){
	for (int i=1;i<=k;i++)
		printf("%d\n",ans[i]);
}
void dfs1(int u,int f,int d){
	dep[u]=d;
	siz[u]=1;
	son[u]=0;
	fa[u]=f;
	for (int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if (v==f) continue;
		dfs1(v,u,d+1);
		siz[u]+=siz[v];
		if (siz[son[u]]<siz[v])
			son[u]=v;
	}
}
void dfs2(int u,int t){
	top[u]=t;
	id[u]=++num;
	if (son[u]) dfs2(son[u],t);
	for (int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if (v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
void build(int k,int s,int t){
	tr[k].l=s;
	tr[k].r=t;
	if (s==t){
		tr[k].sum=0;
		return;
	}
	int mid=(s+t)>>1;
	build(k<<1,s,mid);
	build(k<<1|1,mid+1,t);
	tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
}
void pushdown(int k){
	int x=tr[k].r-tr[k].l+1;
	tr[k<<1].tag+=tr[k].tag;
	tr[k<<1|1].tag+=tr[k].tag;
	tr[k<<1].sum+=(x-(x>>1))*tr[k].tag;
	tr[k<<1|1].sum+=(x>>1)*tr[k].tag;
	tr[k].tag=0;
}
int query(int k,int s,int t){
	int l=tr[k].l,r=tr[k].r;
	if (s==l&&t==r) return tr[k].sum;
	if (tr[k].tag) pushdown(k);
	int mid=(l+r)>>1;
	if (t<=mid) return query(k<<1,s,t);
	else if (s>mid) return query(k<<1|1,s,t);
	else return query(k<<1,s,mid)+query(k<<1|1,mid+1,t);
}
void updata(int k,int s,int t,int x){
	int l=tr[k].l,r=tr[k].r;
	if (s==l&&t==r){
		tr[k].tag+=x;
		tr[k].sum+=(t-s+1)*x;
		return;
	}
	if (tr[k].tag) pushdown(k);
	int mid=(l+r)>>1;
	if (t<=mid) updata(k<<1,s,t,x);
	else if (s>mid) updata(k<<1|1,s,t,x);
	else{
		updata(k<<1,s,mid,x);
		updata(k<<1|1,mid+1,t,x);
	}
	tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
}
void change(int u,int v){
	int tx=top[u],ty=top[v];
	while (tx!=ty){
		if (dep[tx]<dep[ty]){
			swap(tx,ty);
			swap(u,v);
		}
		updata(1,id[tx],id[u],1);
		u=fa[tx];
		tx=top[u];
	}
	if (dep[u]>dep[v]) swap(u,v);
	updata(1,id[u],id[v],1);
}
int ask(int u,int v){
	int tx=top[u],ty=top[v],ans=0;
	while (tx!=ty){
		if (dep[tx]<dep[ty]){
			swap(tx,ty);
			swap(u,v);
		}
		ans+=query(1,id[tx],id[u]);
		u=fa[tx];
		tx=top[u];
	}
	if (dep[u]>dep[v]) swap(u,v);
	ans+=query(1,id[u],id[v]);
	return ans;
}
void work(){
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,num);
	for (int i=1;i<=m;i++)
		if (q[i].p==1) change(q[i].x,q[i].y);
		else ans[++k]=ask(q[i].x,q[i].y);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
