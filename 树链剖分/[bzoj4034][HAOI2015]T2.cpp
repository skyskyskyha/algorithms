#include<bits/stdc++.h>
using namespace std;
struct tree{
	int l,r;
	long long tag,sum;
};
struct ope{
	int p;
	long long x,y;
};
vector<int> e[200000];
tree tr[500000];
ope q[200000];
long long a[200000],ans[200000];
int dep[200000],siz[200000],son[200000],fa[200000],top[200000],id[200000],mx[200000],n,m,num=0,k=0;
inline void ins(int u,int v){
	e[u].push_back(v);
	e[v].push_back(u);
}
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%lld",a+i);
	for (int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ins(u,v);
	}
	for (int i=1;i<=m;i++){
		scanf("%d",&q[i].p);
		if (q[i].p==3) scanf("%lld",&q[i].x);
		else scanf("%lld%lld",&q[i].x,&q[i].y);
	}
}
void writeit(){
	for (int i=1;i<=k;i++)
		printf("%lld\n",ans[i]);
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
	mx[u]=num;
	if (son[u]){
		dfs2(son[u],t);
		mx[u]=max(mx[u],mx[son[u]]);
	}
	for (int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if (v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
		mx[u]=max(mx[u],mx[v]);
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
long long query(int k,int s,int t){
	int l=tr[k].l,r=tr[k].r;
	if (s==l&&t==r) return tr[k].sum;
	if (tr[k].tag) pushdown(k);
	int mid=(l+r)>>1;
	if (t<=mid) return query(k<<1,s,t);
	else if (s>mid) return query(k<<1|1,s,t);
	else return query(k<<1,s,mid)+query(k<<1|1,mid+1,t);
}
void updata(int k,int s,int t,long long x){
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
long long ask(int u,int v){
	long long ans=0;
	int tx=top[u],ty=top[v];
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
	for (int i=1;i<=n;i++)
		updata(1,id[i],id[i],a[i]);
	for (int i=1;i<=m;i++)
		if (q[i].p==1) updata(1,id[q[i].x],id[q[i].x],q[i].y);
		else if (q[i].p==2) updata(1,id[q[i].x],mx[q[i].x],q[i].y);
		else ans[++k]=ask(1,q[i].x);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
