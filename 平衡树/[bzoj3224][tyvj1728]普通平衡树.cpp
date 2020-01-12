#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf 1073741823
using namespace std;
using namespace __gnu_pbds;
struct ope{
	int t,x;
};
ope o[200000];
int ans[200000],n,tot=0;
void readit(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d%d",&o[i].t,&o[i].x);
}
void writeit(){
	for (int i=1;i<=tot;i++)
		printf("%d\n",ans[i]);
}
void work(){
	tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> tr;
	tr.insert(-inf);
	tr.insert(inf);
	for (int i=1;i<=n;i++){
		int t=o[i].t,x=o[i].x;
		if (t==1){
			double l=*--tr.lower_bound(x+1);
			if (l>=x) tr.insert(l+0.000001);
			else tr.insert(x);
		}
		else
			if (t==2){
				double l=*--tr.lower_bound(x+1);
				if (l!=-inf) tr.erase(l);
			}
			else
				if (t==3)
					ans[++tot]=tr.order_of_key(x);
				else
					if (t==4)
						ans[++tot]=*tr.find_by_order(x);
					else
						if (t==5)
							ans[++tot]=*--tr.lower_bound(x);
						else
							ans[++tot]=*tr.lower_bound(x+1);				
	}
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
