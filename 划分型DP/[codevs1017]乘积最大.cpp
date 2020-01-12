#include<bits/stdc++.h>
using namespace std;
char s[100];
long long f[10][100],num[100][100],ans;
int n,k;
void readit(){
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
}
void writeit(){
	printf("%lld\n",ans);
}
void work(){
	for (int i=1;i<=n;i++)
		for (int j=i;j<=n;j++)
			num[i][j]=num[i][j-1]*10+s[j]-48;
	for (int i=1;i<=n;i++)
		f[0][i]=num[1][i];
	for (int i=1;i<=k;i++)
		for (int j=i+1;j<=n;j++)
			for (int l=i;l<=j-1;l++)
				f[i][j]=max(f[i][j],f[i-1][l]*num[l+1][j]);
	ans=f[k][n];
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
