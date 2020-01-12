#include<bits/stdc++.h>
using namespace std;
long long a,b,c,p,q,r,s,ans;
void readit(){
	scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&p,&q,&r,&s);
}
void writeit(){
	printf("%lld\n",ans);
}
int gcd(int a,int b){
	if (!b) return a;
	else return gcd(b,a%b);
}
void exgcd(int a,int b,int &x,int &y){
	if (!b){
		x=1;
		y=0;
	}
	else{
		exgcd(b,a%b,x,y);
		int tmp=x;
		x=y;
		y=tmp-(a/b)*y;
	}
}
void work(){
	if (a==0&&b==0&&c==0) ans=max((long long)0,q-p+1)*max((long long)0,s-r+1);
	else if (a==0&&b==0&&c!=0) ans=0;
	else if (a==0)
		if (!(-c%b)&&-c/b>=r&&-c/b<=s) ans=q-p+1;
		else ans=0;
	else if (b==0)
		if (!(-c%a)&&-c/a>=p&&-c/a<=q) ans=s-r+1;
		else ans=0;
	else{
		int g=gcd(a,b);
		if (-c%g) ans=0;
		else{
			int x,y;
			exgcd(a,b,x,y);
			x=x*-c/g;
			y=y*-c/g;
			a/=g;
			b/=g;
			if (b<0){
				a=-a;
				b=-b;
			}
			while (x>=p){
				x-=b;
				y+=a;
			}
			ans=0;
			while (x<=q){
				if (x>=p&&y>=r&&y<=s) ans++;
				x+=b;
				y-=a;
			}
		}	
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		readit();
		work();
		writeit();
	}
	return 0;
}
