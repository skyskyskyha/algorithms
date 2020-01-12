#include<bits/stdc++.h>
using namespace std;
vector<int> e[20000];
stack<int> sta;
int dfn[20000],low[20000],sccnum[20000],num[20000],next[20000],ans[20000],n,m,tim=0,cnt=0,t=0,tot=0,anstot=0;
inline void ins(int u,int v){
	e[u].push_back(v);
}
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		ins(u,v);
	}
}
void writeit(){
	printf("%d\n",t);
	if (tot==1){
		for (int i=1;i<anstot;i++)
			printf("%d ",ans[i]);
		printf("%d\n",ans[anstot]);
	}
	else printf("-1\n");
}
void dfs(int u){
	sta.push(u);
	dfn[u]=low[u]=++tim;
	for (int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if (!dfn[v]){
			dfs(v);
			low[u]=min(low[u],low[v]);
		}
		else
			if (!sccnum[v])
				low[u]=min(low[u],dfn[v]);
	}
	if (dfn[u]==low[u]){
		cnt++;
		int top=-1;
		while (top!=u){
			top=sta.top();
			sta.pop();
			sccnum[top]=cnt;
			num[cnt]++;
		}
	}
}
void tarjan(){
	for (int i=1;i<=n;i++)
		if (!dfn[i]) dfs(i);
}
void rebuild(){
	for (int i=1;i<=n;i++)
		for (int j=0;j<e[i].size();j++)
			if (sccnum[i]!=sccnum[e[i][j]])
				next[sccnum[i]]++;
}
void work(){
	tarjan();
	for (int i=1;i<=n;i++)
		if (num[i]>1) t++;
	rebuild();
	int sccn;
	for (int i=1;i<=cnt;i++)
		if (!next[i]&&num[i]>1){
			tot++;
			sccn=i;
		}
	if (tot==1)
		for (int i=1;i<=n;i++)
			if (sccnum[i]==sccn) ans[++anstot]=i;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
