#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
int m;
void readit(){
	scanf("%lld",&n);
}
void writeit(){
	printf("%lld",ans);
}
long long phi(int x){
	long long t=x;
	for (int i=2;i<=m;i++)
		if (!(x%i)){
			t=t/i*(i-1);
			while (!(x%i))
				x/=i;
		}
	if (x>1) t=t/x*(x-1);
	return t;
}
void work(){
	m=(int)sqrt(n);
	for (int i=1;i<=m;i++)
		if (!(n%i)){
			ans+=phi(n/i)*i;
			if (i*i<n) ans+=phi(i)*(n/i);
		}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
