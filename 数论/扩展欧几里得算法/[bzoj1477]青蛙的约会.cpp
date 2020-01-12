#include<bits/stdc++.h>
using namespace std;
long long x,y,m,n,l,f,ans;
void readit(){
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
}
void writeit(){
	if (f) printf("Impossible\n");
	else printf("%d\n",ans);
}
long long gcd(long long a,long long b){
	if (!b) return a;
	else return gcd(b,a%b);
}
void exgcd(long long a,long long b,long long &x,long long &y){
	if (!b){
		x=1;
		y=0;
	}
	else{
		exgcd(b,a%b,x,y);
		long long temp=x;
		x=y;
		y=temp-a/b*y;
	}
}
void work(){
	long long a=n-m,b=l,c=x-y;
	long long t=gcd(a,b);
	if (c%t) f=1;
	else{
		a/=t;
		b/=t;
		c/=t;
		exgcd(a,b,x,y);
		ans=(x*c%b+b)%b;
		if (!ans) ans+=b;
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
