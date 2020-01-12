#include<bits/stdc++.h>
using namespace std;
char str[1000000];
int rad[1000000],pos[1000000],n,ans=0;
void readit(){
	scanf("%d",&n);
	scanf("%s",str+1);
	str[0]='#';
}
void writeit(){
	printf("%d\n",ans);
}
void manacher(){
	int r=0,id;
	for (int i=1;i<=n;i++){
		if (i<=r) rad[i]=min(r-i,rad[2*id-i]);
		else rad[i]=0;
		while (str[i-rad[i]]==str[i+rad[i]+1])
			rad[i]++;
		if (i+rad[i]>r){
			r=i+rad[i];
			id=i;
		}
	}
}
bool cmp(int a,int b){
	return a-rad[a]<b-rad[b];
}
void work(){
	manacher();
	for (int i=1;i<=n;i++)
		pos[i]=i;
	sort(pos+1,pos+n+1,cmp);
	set<int> s;
	int now=1;
	s.insert(0);
	for (int i=1;i<=n;i++){
		while (now<=n&&pos[now]-rad[pos[now]]<=i){
			s.insert(pos[now]);
			now++;
		}
		int l=*--s.upper_bound(i+rad[i]/2);
		if (l) ans=max(ans,(l-i)*4);
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
