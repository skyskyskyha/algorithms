#include<bits/stdc++.h>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
struct ope{
	int t,x,y,k;
};
ope o[30000];
rope<int> *fa[30000];
int a[30000],ans[30000],n,m,tot=0;
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int t;
		scanf("%d",&t);
		o[i].t=t;
		if (t==2) scanf("%d",&o[i].k);
		else scanf("%d%d",&o[i].x,&o[i].y);
	}
}
void writeit(){
	for (int i=1;i<=tot;i++)
		printf("%d\n",ans[i]);
}
inline int root(int num,int x){
	if ((*fa[num])[x]==x) return x;
	int rt=root(num,(*fa[num])[x]);
	(*fa[num]).replace(x,rt);
	return rt;
}
inline void uni(int num,int x,int y){
	int u=root(num,x),v=root(num,y);
	(*fa[num]).replace(v,u);
}
void work(){
	for (int i=1;i<=n;i++)
		a[i]=i;
	fa[0]=new rope<int>(a,a+n+1);
	for (int i=1;i<=m;i++){
		int t=o[i].t;
		fa[i]=new rope<int>(*fa[i-1]);
		if (t==1){
			int x=o[i].x,y=o[i].y;
			uni(i,x,y);
		}
		else
			if (t==2){
				int k=o[i].k;
				fa[i]=fa[k];
			}
			else{
				int x=o[i].x,y=o[i].y;
				ans[++tot]=root(i,x)==root(i,y);
			}
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
