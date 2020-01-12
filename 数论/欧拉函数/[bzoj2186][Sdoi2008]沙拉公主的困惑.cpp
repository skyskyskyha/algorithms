#include<bits/stdc++.h>
using namespace std;
int f[12000000],prime[2000000],fac[12000000],ine[12000000],res[12000000],t,r,n,m,tot=0,ans;
void readit(){
	scanf("%d%d",&n,&m);
}
void writeit(){
	printf("%d\n",ans);
}
void solve(int n){
	fac[1]=1;
	for (int i=2;i<=n;i++)
		fac[i]=(long long)fac[i-1]*i%r;
	for (int i=2;i<=n;i++){
		if (!f[i]) prime[++tot]=i;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++){
			f[i*prime[j]]=1;
			if (!(i%prime[j])) break;
		}
	}
	ine[1]=1;
	for (int i=2;i<=n&&i<r;i++)
		ine[i]=(r-(long long)r/i)*ine[r%i]%r;
	res[1]=1;
	for (int i=2;i<=n;i++){
		res[i]=res[i-1];
		if (!f[i]) res[i]=(long long)res[i]*(i-1)%r*ine[i]%r;
	}
}
void work(){
	ans=(long long)fac[n]*res[m]%r;
}
int main(){
	scanf("%d%d",&t,&r);
	solve(10000000);
	for (int i=1;i<=t;i++){
		readit();
		work();
		writeit();
	}
	return 0;
}
