#include<bits/stdc++.h>
using namespace std;
struct data{
	long long x,y;
};
data a[100000];
long long x[100000],y[100000],f[100000],ans;
int q[100000],n;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%lld%lld",&a[i].x,&a[i].y);
}
void writeit(){
	printf("%lld\n",ans);
}
bool cmp(data a,data b){
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
inline double slope(int k,int j){
	return (double)(f[j]-f[k])/(double)(y[k+1]-y[j+1]);
}
void work(){
	sort(a+1,a+n+1,cmp);
	int tot=0;
	for (int i=1;i<=n;i++){
		while (tot&&a[i].y>=y[tot]) tot--;
		x[++tot]=a[i].x;
		y[tot]=a[i].y;
	}
	int head=0,tail=0;
	for (int i=1;i<=tot;i++){
		while (head<tail&&slope(q[head],q[head+1])<x[i]) head++;
		int j=q[head];
		f[i]=f[j]+y[j+1]*x[i];
		while (head<tail&&slope(q[tail-1],q[tail])>slope(q[tail],i)) tail--;
		q[++tail]=i;
	}
	ans=f[tot];
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
