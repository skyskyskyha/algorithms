#include<bits/stdc++.h>
using namespace std;
struct tree{
	int l,r,tag,sum;
};
struct ope{
	int l,r;
};
tree tr[600000];
ope o[300000];
int ans[300000],n,m;
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d",&o[i].l,&o[i].r);
}
void writeit(){
	for (int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
}
void build(int k,int s,int t){
	tr[k].l=s;
	tr[k].r=t;
	if (s==t){
		tr[k].sum=1;
		return;
	}
	int mid=(s+t)>>1;
	build(k<<1,s,mid);
	build(k<<1|1,mid+1,t);
	tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
}
void pushdown(int k){
	int x=tr[k].r-tr[k].l+1;
	tr[k<<1].tag=1;
	tr[k<<1|1].tag=1;
	tr[k<<1].sum=0;
	tr[k<<1|1].sum=0;
	tr[k].tag=0;
}
void updata(int k,int s,int t){
	int l=tr[k].l,r=tr[k].r;
	if (s==l&&t==r){
		tr[k].tag=1;
		tr[k].sum=0;
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
	for (int i=1;i<=m;i++){
		updata(1,o[i].l,o[i].r);
		ans[i]=tr[1].sum;
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
