#include<bits/stdc++.h>
using namespace std;
const long long c[]={2,3,7,11,13};
bool f;
long long p;
void readit(){
	scanf("%lld",&p);
}
void writeit(){
	if (f) printf("Yes\n");
	else printf("No\n");
}
long long mul(long long a,long long b,long long p){
	long long ans=0;
	while (b){
		if (b&1){
			b--;
			ans+=a;
			ans%=p;
		}
		a<<=1;
		a%=p;
		b>>=1;
	}
	return ans;
}
long long power(long long a,long long b,long long p){
	if (!b) return 1%p;
	long long t=power(a,b/2,p);
	t=mul(t,t,p);
	if (b&1) t=mul(t,a,p);
	return t;
}
bool check(long long n){
	bool f=1;
	for (int i=0;i<=4;i++)
		if (c[i]!=n&&power(c[i],n-1,n)!=1){
			f=0;
			break;
		}
	return f;
}
void work(){
	f=check(p);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
