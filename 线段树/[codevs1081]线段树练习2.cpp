#include<bits/stdc++.h>
using namespace std;
struct tree{
	int l,r,x;
};
struct ope{
	int p,l,r,x;
};
tree tr[500000];
ope o[200000];
int a[200000],ans[200000],n,m,k=0;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&o[i].p);
		if (o[i].p==1) scanf("%d%d%d",&o[i].l,&o[i].r,&o[i].x);
		else scanf("%d",&o[i].x);
	}
}
void writeit(){
	for (int i=1;i<=k;i++)
		printf("%d\n",ans[i]);
}
void build(int k,int s,int t){
	tr[k].l=s;
	tr[k].r=t;
	if (s==t){
		tr[k].x=a[s];
		return;
	}
	int mid=(s+t)>>1;
	build(k<<1,s,mid);
	build(k<<1|1,mid+1,t);
}
int query(int k,int x){
	int l=tr[k].l,r=tr[k].r;
	if (l==r) return tr[k].x;
	int mid=(l+r)>>1;
	if (x<=mid) return tr[k].x+query(k<<1,x);
	else return tr[k].x+query(k<<1|1,x);
}
void updata(int k,int s,int t,int x){
	int l=tr[k].l,r=tr[k].r;
	if (s==l&&t==r) {
		tr[k].x+=x;
		return;
	}
	int mid=(l+r)>>1;
	if (t<=mid) updata(k<<1,s,t,x);
	else if (s>mid) updata(k<<1|1,s,t,x);
	else{
		updata(k<<1,s,mid,x);
		updata(k<<1|1,mid+1,t,x);
	}
}
void work(){
	build(1,1,n);
	for (int i=1;i<=m;i++)
		if (o[i].p==1) updata(1,o[i].l,o[i].r,o[i].x);
		else ans[++k]=query(1,o[i].x);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
