#include<bits/stdc++.h>
using namespace std;
struct point{
	int x,y;
};
point p[200000];
double ans=0;
int n;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&p[i].x,&p[i].y);
}
void writeit(){
	printf("%.1lf\n",ans);
}
bool cmp(point a,point b){
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
inline bool left(int x1,int y1,int x2,int y2){
	return x1*y2<=x2*y1;
}
inline bool check(point a,point b,point c){
	return left(b.x-a.x,b.y-a.y,c.x-b.x,c.y-b.y);
}
inline double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void work(){
	point sta[200000];
	int top=0;
	sort(p+1,p+n+1,cmp);
	sta[++top]=p[1];
	sta[++top]=p[2];
	for (int i=3;i<=n;i++){
		while (top>=2&&check(sta[top-1],sta[top],p[i])) top--;
		sta[++top]=p[i];
	}
	int len=top;
	sta[++top]=p[n-1];
	for (int i=n-2;i>=1;i--){
		while (top>len&&check(sta[top-1],sta[top],p[i])) top--;
		sta[++top]=p[i];
	}
	ans+=dis(sta[top],sta[1]);
	for (int i=1;i<top;i++)
		ans+=dis(sta[i],sta[i+1]);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
