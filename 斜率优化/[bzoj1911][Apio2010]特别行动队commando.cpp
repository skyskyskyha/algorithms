#include<bits/stdc++.h>
using namespace std;
long long sum[2000000],f[2000000],ans;
int x[2000000],q[2000000],n,a,b,c;
void readit(){
	scanf("%d",&n);
	scanf("%d%d%d",&a,&b,&c);
	for (int i=1;i<=n;i++)
		scanf("%d",x+i);
}
void writeit(){
	printf("%lld\n",ans);
}
inline long long sqr(long long x){
	return x*x;
}
inline double slope(int k,int j){
	return (double)(f[j]-f[k]+a*(sqr(sum[j])-sqr(sum[k]))+b*(sum[k]-sum[j]))/(double)(2*a*(sum[j]-sum[k]));
}
void work(){
	for (int i=1;i<=n;i++)
		sum[i]=sum[i-1]+x[i];
	int head=0,tail=0;
	for (int i=1;i<=n;i++){
		while (head<tail&&slope(q[head],q[head+1])<sum[i]) head++;
		int j=q[head];
		f[i]=f[j]+a*sqr(sum[i]-sum[j])+b*(sum[i]-sum[j])+c;
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
