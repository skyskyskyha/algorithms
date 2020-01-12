#include<bits/stdc++.h>
using namespace std;
struct ope{
	int t,x,y,x2,y2,k;
};
ope o[20000];
int t[1025][1025],ans[20000],m,n,tot=0;
void readit(){
	scanf("%d",&n);
	while (1){
		scanf("%d",&o[++m].t);
		if (o[m].t==1) scanf("%d%d%d",&o[m].x,&o[m].y,&o[m].k);
		else if (o[m].t==2) scanf("%d%d%d%d",&o[m].x,&o[m].y,&o[m].x2,&o[m].y2);
		else break;
	}
}
void writeit(){
	for (int i=1;i<=tot;i++)
		printf("%d\n",ans[i]);
}
inline int lowbit(int x){
	return x&(-x);
}
int query(int x,int y){
	int sum=0;
	for (int i=x;i>0;i-=lowbit(i))
		for (int j=y;j>0;j-=lowbit(j))
			sum+=t[i][j];
	return sum;
}
void updata(int x,int y,int k){
	for (int i=x;i<=n;i+=lowbit(i))
		for (int j=y;j<=n;j+=lowbit(j))
			t[i][j]+=k;
}
void work(){
	for (int i=1;i<m;i++)
		if (o[i].t==1){
			int x=o[i].x,y=o[i].y,k=o[i].k;
			updata(x+1,y+1,k);
		}
		else{
			int x1=o[i].x,y1=o[i].y,x2=o[i].x2,y2=o[i].y2;
			ans[++tot]=query(x2+1,y2+1)-query(x2+1,y1)-query(x1,y2+1)+query(x1,y1);
		}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
