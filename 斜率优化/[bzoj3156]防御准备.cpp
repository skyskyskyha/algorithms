#include<bits/stdc++.h>
using namespace std;
long long sum[2000000],f[2000000],ans;
int cost[2000000],q[2000000],n;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",cost+i);
}
void writeit(){
	printf("%lld\n",ans);
}
inline double slope(int k,int j){
	return (double)(f[j]-f[k]+sum[j]-sum[k])/(double)(j-k);
}
void work(){
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+i;
	int head=0,tail=0;
	for (int i=1;i<=n;i++){
		while (head<tail&&slope(q[head],q[head+1])<i) head++;
		int j=q[head];
		f[i]=f[j]+(long long)(i-j)*i-sum[i]+sum[j]+cost[i];
		while (head<tail&&slope(q[tail-1],q[tail])>slope(q[tail],i)) tail--;
		q[++tail]=i;
	}
	ans=f[n];
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
