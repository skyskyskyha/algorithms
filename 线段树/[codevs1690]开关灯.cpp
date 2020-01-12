#include<bits/stdc++.h>
using namespace std;
struct tree{
	int l,r,tag,sum;
};
struct ope{
	int p,x,y;
};
tree tr[1000000];
ope o[200000];
int ans[200000];
int n,m,k=0;
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&o[i].p,&o[i].x,&o[i].y);
}
void writeit(){
	for (int i=1;i<=k;i++)
		printf("%d\n",ans[i]);
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
	tr[k<<1].tag%=2;
	tr[k<<1|1].tag+=tr[k].tag;
	tr[k<<1|1].tag%=2;
	tr[k<<1].sum=tr[k<<1].r-tr[k<<1].l+1-tr[k<<1].sum;
	tr[k<<1|1].sum=tr[k<<1|1].r-tr[k<<1|1].l+1-tr[k<<1|1].sum;
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
void updata(int k,int s,int t){
	int l=tr[k].l,r=tr[k].r;
	if (s==l&&t==r){
		tr[k].tag++;
		tr[k].tag%=2;
		tr[k].sum=t-s+1-tr[k].sum;
		return;
	}
	if (tr[k].tag) pushdown(k);
	int mid=(l+r)>>1;
	if (t<=mid) updata(k<<1,s,t);
	else if (s>mid) updata(k<<1|1,s,t);
	else{
		updata(k<<1,s,mid);
		updata(k<<1|1,mid+1,t);
	}
	tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
}
void work(){
	build(1,1,n);
	for (int i=1;i<=m;i++)
		if (!o[i].p) updata(1,o[i].x,o[i].y);
		else ans[++k]=query(1,o[i].x,o[i].y);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
