#include<bits/stdc++.h>
using namespace std;
struct tree{
	int lc,rc,sum;
};
struct que{
	int l,r,k;
};
tree tr[2000000];
que q[10000];
int a[200000],sa[200000],root[200000],ans[10000],n,m,size=0;
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&q[i].l,&q[i].r,&q[i].k);
}
void writeit(){
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}
void disc(){
	for (int i=1;i<=n;i++)
		sa[i]=a[i];
    sort(sa+1,sa+n+1);
    map<int,int> ma;
    for (int i=1;i<=n;i++)
        ma[sa[i]]=i;
    for (int i=1;i<=n;i++)
        a[i]=ma[a[i]];
}
void build(int s,int t,int last,int &now,int v){
	now=++size;
	tr[now].sum=tr[last].sum+1;
	if (s==t) return;
	tr[now].lc=tr[last].lc;
	tr[now].rc=tr[last].rc;
	int mid=(s+t)>>1;
	if (v<=mid) build(s,mid,tr[last].lc,tr[now].lc,v);
	else build(mid+1,t,tr[last].rc,tr[now].rc,v);
}
int query(int k,int s,int t,int x){
	if (t==x) return tr[k].sum;
	int mid=(s+t)>>1;
	if (x<=mid) return query(tr[k].lc,s,mid,x);
	else return tr[tr[k].lc].sum+query(tr[k].rc,mid+1,t,x);
}
int ask(int s,int t,int k){
	int tr1=root[s-1],tr2=root[t],l=1,r=n;
	while (l<=r){
		int mid=(l+r)>>1;
		int rank=query(tr2,1,n,mid)-query(tr1,1,n,mid);
		if (rank<k) l=mid+1;
		else r=mid-1;
	}
	return l;
}
void work(){
	disc();
	for (int i=1;i<=n;i++)
		build(1,n,root[i-1],root[i],a[i]);
	for (int i=1;i<=m;i++)
		ans[i]=sa[ask(q[i].l,q[i].r,q[i].k)];
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
