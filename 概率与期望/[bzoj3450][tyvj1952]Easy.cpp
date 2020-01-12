#include<bits/stdc++.h>
using namespace std;
char s[500000];
long double f[500000],d[500000],ans;
int n;
void readit(){
	scanf("%d",&n);
	scanf("%s",s+1);
}
void writeit(){
	printf("%.4lf\n",ans);
}
void work(){
	for (int i=1;i<=n;i++){
		if (s[i]=='x'){
			f[i]=f[i-1];
			d[i]=0;
		}
		else if (s[i]=='o'){
			f[i]=f[i-1]+d[i-1]*2+1;
			d[i]=d[i-1]+1;
		}
		else{
			f[i]=f[i-1]+d[i-1]+0.5;
			d[i]=(d[i-1]+1)/2;
		}
	}
	ans=f[n];
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
