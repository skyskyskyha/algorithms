#include<bits/stdc++.h>
using namespace std;
struct tree{
	int l,r,mi;
};
struct ope{
	int p,x,y;
};
tree tr[500000];
ope o[200000];
int a[200000],ans[200000],m,n,k=0;
void readit(){
	scanf("%d%d",&m,&n);
	for (int i=1;i<=m;i++)
		scanf("%d",a+i);
	for (int i=1;i<=n;i++)
		scanf("%d%d%d",&o[i].p,&o[i].x,&o[i].y);
}
void writeit(){
	for (int i=1;i<k;i++)
		printf("%d ",ans[i]);
	if (k) printf("%d\n",ans[k]);
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
void updata(int k,int x,int y){
	int l=tr[k].l,r=tr[k].r;
	if (l==r) {
		tr[k].mi=y;
		return;
	}
	int mid=(l+r)>>1;
	if (x<=mid) updata(k<<1,x,y);
	else updata(k<<1|1,x,y);
	tr[k].mi=min(tr[k<<1].mi,tr[k<<1|1].mi);
}
void work(){
	build(1,1,m);
	for (int i=1;i<=n;i++)
		if (o[i].p==1) ans[++k]=query(1,o[i].x,o[i].y);
		else updata(1,o[i].x,o[i].y);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
