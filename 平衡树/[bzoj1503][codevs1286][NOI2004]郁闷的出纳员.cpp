#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf 1073741823
using namespace std;
using namespace __gnu_pbds;
struct ope{
	char t;
	int k;
};
ope o[500000];
int ans[200000],n,m,num=0,tot=0;
void readit(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s%d",&o[i].t,&o[i].k);
}
void writeit(){
	for (int i=1;i<=num;i++)
		printf("%d\n",ans[i]);
	printf("%d\n",tot);
}
void work(){
	tree<double,null_mapped_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> tr;
	int delta=0;
	tr.insert(-inf);
	tr.insert(inf);
	for (int i=1;i<=n;i++){
		char t=o[i].t;
		int k=o[i].k;
		if (t=='I')
			if 	(k>=m){
				int v=k-m+delta;
				double l=*--tr.lower_bound(v+1);
				if (l>=v) tr.insert(l+0.000001);
				else tr.insert(v);
   			}
			else;
		else
			if (t=='A') delta-=k;
			else
				if (t=='S'){
					delta+=k;
					double l=*--tr.lower_bound(delta);
					while (l!=-inf){
						tot++;
						tr.erase(l);
						l=*--tr.lower_bound(delta);
					}
				}
				else{
					num++;
					if (tr.size()-2<k) ans[num]=-1;
					else ans[num]=*tr.find_by_order(tr.size()-k-1)-delta+m;
				}
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
