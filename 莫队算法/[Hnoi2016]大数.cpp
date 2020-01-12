#include<bits/stdc++.h>
using namespace std;
struct node{
    long long l,r,id;
};
char s[150000];
node q[150000];
long long ans[150000],last[150000],last2[150000],p,m,n,nowans=0,sqn;
void readit(){
    scanf("%lld%s%lld",&p,s+1,&m);
    for (long long i=1;i<=m;i++)
    	scanf("%lld%lld",&q[q[i].id=i].l,&q[i].r);
}
void writeit(){
    for (long long i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
}
void solve1(){
    long long sum[150000],num[150000];
    for (long long i=1;i<=n;i++)
        if (!((s[i]-48)%p)){
            sum[i]=sum[i-1]+i;
            num[i]=num[i-1]+1;
        }
        else {
            sum[i]=sum[i-1];
            num[i]=num[i-1];
        }
    for (long long i=1;i<=m;i++)
        ans[i]=sum[q[i].r]-sum[q[i].l-1]-(num[q[i].r]-num[q[i].l-1])*(q[i].l-1);
}
bool comp(node a,node b){
    return a.l/sqn<b.l/sqn||a.l/sqn==b.l/sqn&&a.r<b.r;
}
void getlast(){
    long long b=1;
    for (long long i=n;i>=1;i--){
        b=b*10%p;
        last[i]=(last[i+1]+(s[i]-48)*b)%p;
        last2[i]=last[i];
    }
}
void disc(){
    sort(last2+1,last2+n+2);
    map<long long,long long> ma;
    for (long long i=1;i<=n+1;i++)
        ma[last2[i]]=i;
    for (long long i=1;i<=n+1;i++)
        last[i]=ma[last[i]];
}
void solve2(){
    long long num[150000];
    getlast();
    disc();
    sqn=(long long)sqrt(n);
    sort(q+1,q+m+1,comp);
    long long l=1,r=0;
    for (long long i=1;i<=m;i++){
        while (l>q[i].l) nowans+=num[last[--l]]++;
        while (r<q[i].r+1) nowans+=num[last[++r]]++;
        while (l<q[i].l) nowans-=--num[last[l++]];
        while (r>q[i].r+1) nowans-=--num[last[r--]];
        ans[q[i].id]=nowans;
    }
}
void work(){
    n=strlen(s+1);
    if (p==2||p==5) solve1();
    else solve2();
}
int main(){
    readit();
    work();
    writeit();
    return 0;
}
