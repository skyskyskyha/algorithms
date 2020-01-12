#include<bits/stdc++.h>
using namespace std;
struct circle{
	double x,y,r;
};
circle c1,c2;
double ans;
void readit(){
	scanf("%lf%lf%lf%lf%lf%lf",&c1.x,&c1.y,&c1.r,&c2.x,&c2.y,&c2.r);
}
void writeit(){
	printf("%.3lf\n",ans);
}
void work(){
	if (c1.r<c2.r) swap(c1,c2);
	double h=hypot(c1.x-c2.x,c1.y-c2.y);
	if (c1.r+c2.r<=h) ans=0;
	else if (c1.r-c2.r>=h) ans=c2.r*c2.r*M_PI;
	else{
		double m=(c1.r*c1.r-c2.r*c2.r+h*h)/(h*2),n=sqrt(c1.r*c1.r-m*m),area1=c1.r*c1.r*asin(n/c1.r)-n*m,area2=c2.r*c2.r*asin(n/c2.r)-n*abs(h-m);
		if (m>h) area2=c2.r*c2.r*M_PI-area2;
		ans=area1+area2;
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
