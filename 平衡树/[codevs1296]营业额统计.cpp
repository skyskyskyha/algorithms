#include<bits/stdc++.h>
#define inf 1073741823
using namespace std;
int a[50000],n,ans;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
}
void writeit(){
	printf("%d\n",ans);
}
void work(){
	set<int> s;
	s.insert(-inf);
	s.insert(inf);
	s.insert(a[1]);
	ans=a[1];
	for (int i=2;i<=n;i++){
		int l=*--s.lower_bound(a[i]),r=*s.lower_bound(a[i]);
		ans+=min(a[i]-l,r-a[i]);	
		s.insert(a[i]);
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
