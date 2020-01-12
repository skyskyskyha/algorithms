#include<bits/stdc++.h>
using namespace std;
int a,b,ans;
void readit(){
	scanf("%d%d",&a,&b);
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
	printf("%d\n",ans);
}
void work(){
	ans=pow(a,b,1012);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
