#include<bits/stdc++.h>
using namespace std;
struct tree{
	int l,r,mi;
};
struct que{
	int l,r;
};
tree tr[500000];
que q[200000];
int a[200000],ans[200000],m,n;
void readit(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		scanf("%d",a+i);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&q[i].l,&q[i].r);
}
void writeit(){
	for (int i=1;i<n;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n]);
}
void build(int k,int s,int t){
	tr[k].l=s;
	tr[k].r=t;
	if (s==t){
		tr[k].mi=a[s];
		return;
	}
	int mid=(s+t)>>1;
	build(k<<1,s,mid);
	build(k<<1|1,mid+1,t);
	tr[k].mi=min(tr[k<<1].mi,tr[k<<1|1].mi);
}
int query(int k,int s,int t){
	int l=tr[k].l,r=tr[k].r;
	if (s==l&&t==r) return tr[k].mi;
	int mid=(l+r)>>1;
	if (t<=mid) return query(k<<1,s,t);
	if (s>mid) return query(k<<1|1,s,t);
	return min(query(k<<1,s,mid),query(k<<1|1,mid+1,t));
}
void work(){
	build(1,1,m);
	for (int i=1;i<=n;i++)
		ans[i]=query(1,q[i].l,q[i].r);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
