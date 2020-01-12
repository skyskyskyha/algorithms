#include<bits/stdc++.h>
using namespace std;
struct ope{
	char t;
	int x,y,l,r;
};
ope o[20000];
int c[20000],pos[20000],pre[20000],pre2[20000],last[2000000],ans[20000],n,m,block,num,tot=0;
void readit(){
	scanf("%d%d",&n,&m);
	block=(int)sqrt(n);
	if (n%block) num=n/block+1;
	else num=n/block;
	for (int i=1;i<=n;i++)
		scanf("%d",c+i);
	for (int i=1;i<=m;i++){
		scanf("%s",&o[i].t);
		if (o[i].t=='R') scanf("%d%d",&o[i].x,&o[i].y);
		else scanf("%d%d",&o[i].l,&o[i].r);
	}
}
void writeit(){
	for (int i=1;i<=tot;i++)
		printf("%d\n",ans[i]);
}
int find(int pos,int x){
	int l=(pos-1)*block+1,r=min(pos*block,n),first=l;
	while (l<=r){
		int mid=(l+r)>>1;
		if (pre2[mid]<x) l=mid+1;
		else r=mid-1;
	}
	return l-first;
}
void reset(int pos){
	int l=(pos-1)*block+1,r=min(pos*block,n);
	for (int i=l;i<=r;i++)
		pre2[i]=pre[i];
	sort(pre2+l,pre2+r+1);
}
int ask(int s,int t){
	int ans=0;
	if (pos[s]==pos[t])
		for (int i=s;i<=t;i++)
			if (pre[i]<s) ans++;
			else;
	else{
		for (int i=s;i<=block*pos[s];i++)
			if (pre[i]<s) ans++;
		for (int i=block*(pos[t]-1)+1;i<=t;i++)
			if (pre[i]<s) ans++;
	}
	for (int i=pos[s]+1;i<pos[t];i++)
		ans+=find(i,s);
	return ans;
}
void change(int x,int y){
	for (int i=1;i<=n;i++)
		last[c[i]]=0;
	c[x]=y;
	bool tag[200];
	for (int i=1;i<=n;i++){
		int tmp=pre[i];
		pre[i]=last[c[i]];
		if (tmp!=pre[i]) tag[pos[i]]=1;
		last[c[i]]=i;
	}
	for (int i=1;i<=num;i++)
		if (tag[i]) reset(i);
}
void work(){
	for (int i=1;i<=n;i++){
		pre[i]=last[c[i]];
		last[c[i]]=i;
		pos[i]=(i-1)/block+1;
	}
	for (int i=1;i<=num;i++)
		reset(i);
	for (int i=1;i<=m;i++)
		if (o[i].t=='R') change(o[i].x,o[i].y);
		else ans[++tot]=ask(o[i].l,o[i].r);
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
