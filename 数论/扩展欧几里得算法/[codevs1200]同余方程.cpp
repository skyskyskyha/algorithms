#include<bits/stdc++.h>
using namespace std;
int a,b,ans;
void readit(){
	scanf("%d%d",&a,&b);
}
void writeit(){
	printf("%d\n",ans);
}
void exgcd(int a,int b,int &x,int &y){
	if (!b){
		x=1;
		y=0;
	}
	else{
		exgcd(b,a%b,x,y);
		int tmp=x;
		x=y;
		y=tmp-(a/b)*y;
	}
}
void work(){
	int x,y;
	exgcd(a,b,x,y);
	ans=((x%b)+b)%b;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
