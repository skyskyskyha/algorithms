#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b;
};
node q[100];
int ans[100],n;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&q[i].a,&q[i].b);
}
int pow(int m,int n,int p){
	int ans=1;
	while (n>0){
		if (n&1) ans=ans*m%p;
		n=n>>1;
		m=m*m%p;
	}
	return ans;
}
void writeit(){
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}
void work(){
	for (int i=1;i<=n;i++)
		ans[i]=pow(q[i].a,q[i].b,1012);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
