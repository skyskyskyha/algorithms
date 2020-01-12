#include<bits/stdc++.h>
using namespace std;
const int c[]={2,3,5,7,11,13};
long long l,r;
int ans=0;
void readit(){
	scanf("%d%d",&l,&r);
}
void writeit(){
	printf("%d\n",ans);
}
long long power(long long a,long long b,long long p){
	if (!b) return 1%p;
	long long t=power(a,b/2,p);
	t=t*t%p;
	if (b&1) t=t*a%p;
	return t;
}
bool check(long long n){
	bool f=1;
	for (int i=0;i<=5;i++)
		if (c[i]!=n&&power(c[i],n-1,n)!=1){
			f=0;
			break;
		}
	return f;
}
void work(){
	if (l<=2) ans=1;
	if (!(l%2)) l++;
	for (long long i=l;i<=r;i+=2)
		if (check(i)) ans++;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
