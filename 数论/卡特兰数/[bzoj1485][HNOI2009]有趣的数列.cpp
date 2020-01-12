#include<bits/stdc++.h>
using namespace std;
long long ans=1;
int f[3000000],prime[3000000],minfac[3000000],num[3000000],n,p;
void readit(){
	scanf("%d%d",&n,&p);
}
void writeit(){
	printf("%lld\n",ans);
}
void getprime(int n){
	int tot=0;
	f[1]=1;
	for (int i=1;i<=n;i++){
		if (!f[i]){
			prime[++tot]=i;
			minfac[i]=i;
		}
		for (int j=1;j<=tot&&i*prime[j]<=n;j++){
			f[i*prime[j]]=1;
			minfac[i*prime[j]]=prime[j];
			if (!(i%prime[j])) break;
		}
	}
}
void add(int x,int tot){
	while (x!=1){
		num[minfac[x]]+=tot;
		x/=minfac[x];
	}
}
void work(){
	getprime(2*n);
	for (int i=n+2;i<=2*n;i++)
		add(i,1);
	for (int i=2;i<=n;i++)
		add(i,-1);
	for (int i=1;i<=2*n;i++)
		for (int j=1;j<=num[i];j++)
			ans=ans*i%p;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
