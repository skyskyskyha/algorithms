#include<bits/stdc++.h>
using namespace std;
int a[2000000],q[2000000],last[2000],ans[2000000],n,m,block;
void readit(){
	scanf("%d",&n);
	block=(int)sqrt(n);
	for (int i=1;i<=n;i++)
		scanf("%d",a+i);
	m=1;
	while (scanf("%d",q+m)!=EOF)
		m++;
}
void writeit(){
	for (int i=1;i<m;i++)
		printf("%d\n",ans[i]);
}
int query(int x){
	if (x<a[1]) return 1;
	if (x>a[n]) return n+1;
	for (int i=0;i<=block+1;i++)
		if (x>last[i-1]&&x<=last[i]){
			int p=(i-1)*block;
			for (int j=1;j<=block;j++)
				if (a[p+j]>=x) return p+j;
		}
}
void work(){
	sort(a+1,a+n+1);
	for (int i=1;i<=block;i++)
		last[i]=a[block*i];
	last[block+1]=a[n];
	for (int i=1;i<=m;i++)
		ans[i]=query(q[i]);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
