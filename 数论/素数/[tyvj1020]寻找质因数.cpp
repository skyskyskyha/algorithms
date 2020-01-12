#include<bits/stdc++.h>
using namespace std;
int x[10000],f[100000],prime[100000],n,ma,ans;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",x+i);
}
void getprime(int n){
	int tot=0;
	f[1]=1;
	for (int i=1;i<=n;i++){
		if (!f[i]) prime[++tot]=i;
		for (int j=1;j<=tot&&i*prime[j]<=n;j++){
			f[i*prime[j]]=1;
			if (!(i%prime[j])) break;
		}
	}
}
void writeit(){
	printf("%d\n",ans);
}
void work(){
	getprime(20000);
	for (int i=1;i<=n;i++){
		int sq=(int)sqrt(x[i]);
		for (int j=1;j<=sq;j++){
			int y=x[i]/j;
			if ((!(x[i]%j)&&!f[y]||y==1)&&y>ma){
				ma=y;
				ans=x[i];
			}
		}
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
