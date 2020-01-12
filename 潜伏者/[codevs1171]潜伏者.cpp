#include<bits/stdc++.h>
using namespace std;
char s1[100],s2[100],s[100],ans[100];
bool f[100];
int h[100],flag=0,tot=0;
void readit(){
	scanf("%s%s%s",s1,s2,s);
}
void writeit(){
	if (flag) printf("Failed");
	else printf("%s\n",ans);
}
void work(){
	if (strlen(s1)!=strlen(s2)){
		flag=1;
		return;
	}
	int len=strlen(s1);
	for (int i=0;i<len;i++)
		if (h[s1[i]-65]&&h[s1[i]-65]!=s2[i]){
			flag=1;
			return;
		}
		else{
			h[s1[i]-65]=s2[i];
			f[s2[i]-65]=1;
		}
	for (int i=0;i<26;i++)
		if (!f[i]){
			flag=1;
			return;
		}
	len=strlen(s);
	for (int i=0;i<len;i++)
		ans[i]=h[s[i]-65];
}
int main(){
	readit();
	work();
	writeit();
	return 0;
}
