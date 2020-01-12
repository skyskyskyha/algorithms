#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
int c[500000],n,ans=0;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",c+i);
}
void writeit(){
	printf("%d\n",ans);
}
void work(){
	rope<int> num,rev;
	for (int i=1;i<=n;i++)
		num+=c[i];
	for (int i=n;i>=1;i--)
		rev+=c[i];
	int k;
	while ((k=num[0])!=1){
		rope<int> tmp=num.substr(0,k);
		num=rev.substr(n-k,k)+num.substr(k,n-k);
		rev=rev.substr(0,n-k)+tmp;
		ans++;
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
