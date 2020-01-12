#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
point p[200];
int n,ans=0;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
}
void writeit(){
	printf("%d\n",ans);
}
int cross(point a,point b){
	return a.x*b.y-a.y*b.x;
}
void work(){
	ans+=cross(p[n],p[1]);
	for (int i=1;i<n;i++)
		ans+=cross(p[i],p[i+1]);
	ans/=2;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
