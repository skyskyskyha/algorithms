#include<bits/stdc++.h>
using namespace std;
struct node1{
	long long val,pos;
};
struct node2{
	long long l,r,id;
};
long long a[200000],sl[200000],sr[200000],ans[200000],nowans,l[200000],r[200000],lg[200000],n,m;
node1 b[200000],mi[200000][30];
node2 q[200000];
inline long long read(){
    long long x=0,f=1;
	char c=getchar();
    for (;!isdigit(c);c=getchar())
		if(c=='-') f=-1;
    for (;isdigit(c);c=getchar())
		x=x*10+c-'0';
    return x*f;
}
void readit(){
    n=read();
	m=read();
	for (long long i=1;i<=n;i++){
		a[i]=read();
		b[i]=(node1){a[i],i};
	}
	for (long long i=1;i<=m;i++){
		q[q[i].id=i].l=read();
		q[i].r=read();
	}
}
void writeit(){
	for (long long i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
}
node1 min(node1 a,node1 b){
	if (a.val<b.val) return a;
	else return b;
}
void lgn(){
	lg[1]=0;
	for (long long i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
}
void rmq(){
	long long temp=lg[n];
	for (long long i=1;i<=n;i++)
		mi[i][0]=b[i];
	for(long long j=1;j<=temp;j++)
		for (long long i=1;i<=n;i++)
	    	if (i+(1<<j)-1<=n)
	    		mi[i][j]=min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
}
void stl(){
	stack<node1> sk;
	sk.push((node1){-1000000001,0});
	for (long long i=1;i<=n;i++){
		while (b[i].val<sk.top().val) sk.pop();
		l[i]=sk.top().pos;
		sk.push(b[i]);
	}
}
void str(){
	stack<node1> sk;
	sk.push((node1){-1000000001,n+1});
	for (long long i=n;i>=1;i--){
		while (b[i].val<sk.top().val) sk.pop();
		r[i]=sk.top().pos;
		sk.push(b[i]);
	}
}
void suml(){
	for (long long i=1;i<=n;i++)
		sl[i]=sl[l[i]]+(i-l[i])*a[i];
}
void sumr(){
	for (long long i=n;i>=1;i--)
		sr[i]=sr[r[i]]+(r[i]-i)*a[i];
}
node1 query(long long l,long long r){
	long long k=lg[r-l+1];
	return min(mi[l][k],mi[r-(1<<k)+1][k]);
}
void updatel(long long l,long long r,long long t){
	long long p=query(l,r).pos;
	nowans+=t*(sr[l]-sr[p]+(r-p+1)*a[p]);
}
void updater(long long l,long long r,long long t){
	long long p=query(l,r).pos;
	nowans+=t*(sl[r]-sl[p]+(p-l+1)*a[p]);
}
bool complarel(node2 a,node2 b){
	return a.l<b.l;
}
bool complarer(node2 a,node2 b){
	return a.r<b.r;
}
void solve(){
	sort(q+1,q+m+1,complarel);
	long long size=(long long)sqrt(n),l=1,r=size,ql=1,qr=1;
	while ((l<=n)&&(qr<=m)){
		for (;(qr<=m)&&(q[qr].l<=r);qr++);
		long long l1=q[ql].l,r1=l1;
		sort(q+ql,q+qr,complarer);
		nowans=a[l1];
		for (long long i=ql;i<=qr-1;i++){
			while (l1>q[i].l) updatel(--l1,r1,1);
			while (r1<q[i].r) updater(l1,++r1,1);
			while (l1<q[i].l) updatel(l1++,r1,-1);
			while (r1>q[i].r) updater(l1,r1--,-1);
			ans[q[i].id]=nowans;
		}
		ql=qr;
		l+=size;
		r+=size;
		if (r>n) r=n;
	}
}
void work(){
	lgn();
	rmq();
	stl();
	str();
	suml();
	sumr();
	solve(); 
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
