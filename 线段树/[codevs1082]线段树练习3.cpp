#include<bits/stdc++.h>
using namespace std;
struct tree{
	int l,r,tag;
	long long sum;
};
struct ope{
	int p,l,r,x;
};
tree tr[1000000];
ope o[300000];
long long ans[300000];
int a[300000],n,m,k=0;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	scanf("%d",&m);
	for (int i=1;i<=m;i++){
		scanf("%d",&o[i].p);
		if (o[i].p==1) scanf("%d%d%d",&o[i].l,&o[i].r,&o[i].x);
		else scanf("%d%d",&o[i].l,&o[i].r);
	}
}
void writeit(){
	for (int i=1;i<=k;i++)
		printf("%lld\n",ans[i]);
}
void build(int k,int s,int t){
	tr[k].l=s;
	tr[k].r=t;
	if (s==t){
		tr[k].sum=a[s];
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
void work(){
	build(1,1,n);
	for (int i=1;i<=m;i++)
		if (o[i].p==1) updata(1,o[i].l,o[i].r,o[i].x);
		else ans[++k]=query(1,o[i].l,o[i].r);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
