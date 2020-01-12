#include<bits/stdc++.h>
using namespace std;
struct tree{
	int l,r,mid,sum;
};
struct ope{
	int p,x,y;
};
tree tr[500000];
ope o[200000];
int a[200000],ans[200000],n,m,k=0;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	scanf("%d",&m);
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
		tr[k].sum=a[s];
		return;
	}
	int mid=(s+t)>>1;
	build(k<<1,s,mid);
	build(k<<1|1,mid+1,t);
	tr[k].sum=tr[k<<1].sum+tr[k<<1|1].sum;
}
int query(int k,int s,int t){
	int l=tr[k].l,r=tr[k].r;
	if (s==l&&t==r) return tr[k].sum;
	int mid=(l+r)>>1;
	if (t<=mid) return query(k<<1,s,t);
	if (s>mid) return query(k<<1|1,s,t);
	return query(k<<1,s,mid)+query(k<<1|1,mid+1,t);
}
void updata(int k,int x,int y){
	tr[k].sum+=y;
	int l=tr[k].l,r=tr[k].r;
	if (l==r) return;
	int mid=(l+r)>>1;
	if (x<=mid) updata(k<<1,x,y);
	else updata(k<<1|1,x,y);
}
void work(){
	build(1,1,n);
	for (int i=1;i<=m;i++){
		if (o[i].p==1) updata(1,o[i].x,o[i].y);
		else ans[++k]=query(1,o[i].x,o[i].y);
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
