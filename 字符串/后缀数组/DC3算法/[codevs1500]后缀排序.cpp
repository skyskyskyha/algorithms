#include<bits/stdc++.h>
using namespace std;
char s[20000];
int r[50000],sa[50000],ra[20000],num[20000],p1[20000],p2[20000],ans[20000],n;
void readit(){
	scanf("%d",&n);
	scanf("%s",s);
}
void writeit(){
	for (int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}
inline int pos1(int x,int t){
	if (x%3==1) return x/3;
	else return x/3+t;
}
inline int pos2(int x,int t){
	if (x<t) return x*3+1;
	else return (x-t)*3+2;
}
inline bool check1(int *r,int x,int y){
	return r[x]==r[y]&&r[x+1]==r[y+1]&&r[x+2]==r[y+2];
}
inline bool check2(int k,int *r,int x,int y){
	if (k==2) return r[x]<r[y]||r[x]==r[y]&&check2(1,r,x+1,y+1);
	else return r[x]<r[y]||r[x]==r[y]&&ra[x+1]<ra[y+1];
}
void sort(int *r,int *a,int *b,int n,int m){
	for (int i=0;i<n;i++)
		ra[i]=r[a[i]];
	for (int i=0;i<m;i++)
		num[i]=0;
	for (int i=0;i<n;i++)
		num[ra[i]]++;
	for (int i=1;i<m;i++)
		num[i]+=num[i-1];
	for (int i=n-1;i>=0;i--)
		b[--num[ra[i]]]=a[i];
}
void dc3(int *r,int *sa,int n,int m){
	int *rn=r+n,*san=sa+n,tp=0,t=(n+1)/3,tot=0,p=1;
	r[n]=r[n+1]=0;
	for (int i=0;i<n;i++)
		if (i%3) p1[tot++]=i;
	sort(r+2,p1,p2,tot,m);
	sort(r+1,p2,p1,tot,m);
	sort(r,p1,p2,tot,m);
	rn[pos1(p2[0],t)]=0;
	for (int i=1;i<tot;i++){
		if (!check1(r,p2[i-1],p2[i])) p++;
		rn[pos1(p2[i],t)]=p-1;
	}
	if (p<tot)
		dc3(rn,san,tot,p);
	else
		for (int i=0;i<tot;i++)
			san[rn[i]]=i;
	for (int i=0;i<tot;i++)
		if (san[i]<t) p2[tp++]=san[i]*3;
	if (n%3==1) p2[tp++]=n-1;
	sort(r,p2,p1,tp,m);
	for (int i=0;i<tot;i++)
		ra[p2[i]=pos2(san[i],t)]=i;
	int i=0,j=0,k=0;
	for (;j<tp&&k<tot;i++)
		if (check2(p2[k]%3,r,p1[j],p2[k])) sa[i]=p1[j++];
		else sa[i]=p2[k++];
	for (;j<tp;i++)
		sa[i]=p1[j++];
	for (;k<tot;i++)
		sa[i]=p2[k++];
}
void work(){
	for (int i=0;i<n;i++)
		r[i]=s[i]-96;
	r[n]=0;
	dc3(r,sa,n+1,27);
	for (int i=1;i<=n;i++)
		ans[i]=sa[i]+1;
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
