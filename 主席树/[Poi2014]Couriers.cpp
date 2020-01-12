#include<bits/stdc++.h>
using namespace std;
struct tree{
	int lc,rc,sum;
};
struct que{
	int l,r;
};
tree tr[10000010];
que q[600000];
int a[600000],root[600000],ans[600000],n,m,size=0;
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&q[i].l,&q[i].r);
}
void writeit(){
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
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
int solve(int s,int t){
	int tr1=root[s-1],tr2=root[t],l=1,r=n,tmp=(t-s+1)>>1;
	while (l!=r){
		if (tr[tr2].sum-tr[tr1].sum<=tmp) return 0;
		int mid=(l+r)>>1;
		if (tr[tr[tr2].lc].sum-tr[tr[tr1].lc].sum>tmp){
			r=mid;
			tr1=tr[tr1].lc;
			tr2=tr[tr2].lc;
		}
		else
			if (tr[tr[tr2].rc].sum-tr[tr[tr1].rc].sum>tmp){
				l=mid+1;
				tr1=tr[tr1].rc;
				tr2=tr[tr2].rc;
			}
			else return 0;
	}
	return l;
}
void work(){
	for (int i=1;i<=n;i++)
		build(1,n,root[i-1],root[i],a[i]);
	for (int i=1;i<=m;i++)
		ans[i]=solve(q[i].l,q[i].r);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
