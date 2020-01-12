#include<bits/stdc++.h>
using namespace std;
struct node{
	int to,w;
};
vector<node> e[300000];
long long dis[300000],ans=0;
int n;
bool f=0;
inline void ins(int u,int v,int w){
	e[u].push_back((node){v,w});
}
void readit(){
	int k;
	scanf("%d%d",&n,&k);
	for (int i=1;i<=k;i++){
		int x,a,b;
		scanf("%d%d%d",&x,&a,&b);
		switch (x){
			case 1:ins(a,b,0);ins(b,a,0);break;
			case 2:if (a==b) f=1;ins(a,b,1);break;
			case 3:ins(b,a,0);break;
			case 4:if (a==b) f=1;ins(b,a,1);break;
			case 5:ins(a,b,0);break;
		}
	}
}
void writeit(){
	if (f) printf("-1\n");
	else printf("%lld\n",ans);
}
bool spfa(){
	queue<int> q;
	int time[300000];
	bool inq[300000];
	dis[0]=0;
	inq[0]=1;
	time[0]=1;
	q.push(0);
	while (!q.empty()){
		int u=q.front();
		q.pop();
		inq[u]=0;
		for (int i=0;i<e[u].size();i++){
			node &eui=e[u][i];
			int v=eui.to;
			if (dis[u]+eui.w>dis[v]){
				dis[v]=dis[u]+eui.w;
				if (!inq[v]){
					q.push(v);
					inq[v]=1;
					if (++time[v]>=n) return 1;
				}
			}
		}
	}
	return 0;
}
void count(){
	for (int i=1;i<=n;i++)
		ans+=dis[i];
}
void work(){
	for (int i=1;i<=n;i++)
		ins(0,i,1);
	f=spfa();
	if (!f) count();
}
int main(){
	readit();
	if (!f) work();
	writeit();
	return 0;
}
