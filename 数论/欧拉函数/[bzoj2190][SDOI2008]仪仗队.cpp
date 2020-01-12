#include<bits/stdc++.h>
using namespace std;
int f[100000],prime[100000],phi[100000],n,ans=0;
void readit(){
	scanf("%d",&n);
}
void getphi(){
	int tot=0;
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
void writeit(){
	printf("%d\n",ans);
}
void work(){
	getphi();
	for (int i=1;i<n;i++)
		ans+=phi[i];
	if (n>1) ans=ans*2+1;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
