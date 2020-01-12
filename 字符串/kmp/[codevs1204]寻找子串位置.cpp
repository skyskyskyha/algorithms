#include<bits/stdc++.h>
using namespace std;
char str1[200],str2[200];
int next[200],n,m,ans;
void readit(){
	scanf("%s%s",str1+1,str2+1);
	n=strlen(str1+1);
	m=strlen(str2+1);
}
void writeit(){
	printf("%d\n",ans);
}
void kmp(){
	int j=0;
	for (int i=2;i<=m;i++){
		while (j>0&&str2[j+1]!=str2[i]) j=next[j];
		if (str2[j+1]==str2[i]) j++;
		next[i]=j;
	}
}
void find(){
	int j=0;
	for (int i=1;i<=n;i++){
		while (j>0&&str2[j+1]!=str1[i]) j=next[j];
		if (str2[j+1]==str1[i]) j++;
		if (j==m){
			ans=i-m+1;
			break;
		}
	}
}
void work(){
	kmp();
	find();
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
