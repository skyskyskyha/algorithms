#include<bits/stdc++.h>
using namespace std;
int p[2000],f[12000000],prime[2000000],phi[12000000],ans[2000],n,tot=0;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",p+i);
}
void writeit(){
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}
void getphi(int n){
	phi[1]=1;
	for (int i=2;i<=n;i++){
		if (!f[i]){
			prime[++tot]=i;
			phi[i]=i-1;
		}
		for (int j=1;j<=tot&&i*prime[j]<=n;j++){
			f[i*prime[j]]=1;
			if (!(i%prime[j])){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else phi[i*prime[j]]=phi[i]*(prime[j]-1);
		}
	}
}
int pow(long long m,long long n,int p){
	int ans=1%p;
	while (n>0){
		if (n&1) ans=ans*m%p;
		n=n>>1;
		m=m*m%p;
	}
	if (ans>=p) cout<<p;
	return ans;
}
int solve(int p){
	if (p==1) return 0;
	int k=0;
	while (!(p&1)){
		p>>=1;
		k++;
	}
	int ph=phi[p],res=solve(ph);
	res=(res+ph-k%ph)%ph;
	res=pow(2,res,p)<<k;
	return res;
}
void work(){
	getphi(10000000);
	for (int i=1;i<=n;i++)
		ans[i]=solve(p[i]);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
