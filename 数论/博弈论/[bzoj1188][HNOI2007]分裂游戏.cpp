#include<bits/stdc++.h>
using namespace std;
int a[30],sg[30],t,n,ansi,ansj,ansk,tot;
void readit(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",a+i);
}
void writeit(){
	printf("%d %d %d\n",ansi,ansj,ansk);
	printf("%d\n",tot);
}
void getsg(){
	sg[n-1]=0;
	for (int i=n-2;i>=0;i--){
		bool f[1000];
		memset(f,0,sizeof(f));
		for (int j=i+1;j<n;j++)
			for (int k=j;k<n;k++)
				f[sg[j]^sg[k]]=1;
			//	printf("%d %d %d %d\n",j,k,sg[j],sg[k]);
		for (int j=0;;j++)
			if (!f[j]){
				sg[i]=j;
				break;
			}
	}
}
void work(){
	getsg();
	int res=0;
	for (int i=0;i<n;i++)
		if (a[i]&1) res^=sg[i];
	tot=0;
	cout<<res<<endl;
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++)
			for (int k=j;k<n;k++)
				if (!(res^sg[i]^sg[j]^sg[k]))
					if (++tot==1){
						ansi=i;
						ansj=j;
						ansk=k;
					}
	if (!tot) ansi=ansj=ansk=-1;
	for (int i=0;i<n;i++)printf("%d ",sg[i]);
	printf("\n");
}
int main(){
	freopen("1188.in","r",stdin);
	freopen("zyc.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		readit();
		work();
		writeit();
	}
	return 0;
}
