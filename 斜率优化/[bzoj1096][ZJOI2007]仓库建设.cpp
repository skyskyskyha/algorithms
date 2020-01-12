#include<bits/stdc++.h>
using namespace std;
long long d[2000000],num[2000000],cost[2000000],sum1[2000000],sum2[2000000],f[2000000],ans;
int q[2000000],n;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld%lld%lld",d+i,num+i,cost+i);
}
void writeit(){
	printf("%lld\n",ans);
}
inline double slope(int k,int j){
	return (double)(f[j]-f[k]+sum2[j]-sum2[k])/(double)(sum1[j]-sum1[k]);
}
void work(){
	for (int i=1;i<=n;i++){
		sum1[i]=sum1[i-1]+num[i];
		sum2[i]=sum2[i-1]+d[i]*num[i];
	}
	int head=0,tail=0;
	for (int i=1;i<=n;i++){
		while (head<tail&&slope(q[head],q[head+1])<d[i]) head++;
		int j=q[head];
		f[i]=f[j]+(sum1[i]-sum1[j])*d[i]-sum2[i]+sum2[j]+cost[i];
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
