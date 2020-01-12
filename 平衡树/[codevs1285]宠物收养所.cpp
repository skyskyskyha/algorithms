#include<bits/stdc++.h>
#define inf 2147483647
using namespace std;
const int p=1000000;
struct ope{
	bool t;
	int v;
};
ope o[100000];
int n,ans=0;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&o[i].t,&o[i].v);
}
void writeit(){
	printf("%d\n",ans);
}
void work(){
	set<int> s;
	bool ty;
	s.insert(-inf);
	s.insert(inf);
	for (int i=1;i<=n;i++){
		int t=o[i].t,v=o[i].v;
		if (s.size()==2){
			ty=t;
			s.insert(v);
		}
		else
			if (ty!=t){
				int l=*--s.lower_bound(v),r=*s.lower_bound(v);
				if (l!=-inf&&v-l<=r-v){
					ans=(ans+v-l)%p;
					s.erase(l);
				}
				else{
					ans=(ans+r-v)%p;
					s.erase(r);
				}
			}
			else s.insert(v);
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
