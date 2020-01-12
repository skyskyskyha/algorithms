#include<bits/stdc++.h>
using namespace std;
const int p[]={1,2,3,5,7,11,13,17,19,23,29,31};
int n,ans=1,num=1;
void readit(){
	scanf("%d",&n);
}
void writeit(){
	printf("%d\n",ans);
}
void dfs(int k,long long now,int cnt,int last){
	if (k>=12){
		if (now>ans&&cnt>num||now<=ans&&cnt>=num){
			ans=now;
			num=cnt;	
		}
		return;
	}
	int t=1;
	for (int i=0;i<=last;i++){
		dfs(k+1,now*t,cnt*(i+1),i);
		t*=p[k];
		if (now*t>n) break;
	}
}
void work(){
	dfs(1,1,1,20);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
