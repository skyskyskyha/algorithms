#include<bits/stdc++.h>
using namespace std;
vector<int> e[100];
string s[100],val[100];
int siz[100],f[100],t,n,minf,ans;
inline void ins(int u,int v){
	e[u].push_back(v);
	e[v].push_back(u);
}
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		e[i].clear();
	for (int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if (x) ins(i,x);
	}
}
void writeit(){
	printf("%d\n",ans);
}
void findroot(int u,int fa){
	siz[u]=1;
	f[u]=0;
	for (int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if (v!=fa){
			findroot(v,u);
			siz[u]+=siz[v];
			f[u]=max(f[u],siz[v]);
		}
	}
	f[u]=max(f[u],n-siz[u]);
	minf=min(minf,f[u]);
}
void dfs(int u,int fa){
	string son[100];
	int tot=0;
	s[u]="(";
	for (int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if (v!=fa){
			dfs(v,u);
			son[tot++]=s[v];
		}
	}
	sort(son,son+tot);
	for (int i=0;i<tot;i++)
		s[u]+=son[i];
	s[u]+=")";
}
void work(int t){
	minf=n;
	findroot(1,0);
	for (int i=1;i<=n;i++)
		if (f[i]==minf){
			dfs(i,0);
			val[t]=max(val[t],s[i]);
		}
	for (int i=1;i<=t;i++)
		if (val[t]==val[i]){
			ans=i;
			break;
		}
}
int main(){
	scanf("%d",&t);
	for (int i=1;i<=t;i++){
		readit();
		work(i);
		writeit();
	}
	return 0;
}
