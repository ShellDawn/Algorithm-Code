/*
* 20170801
*/

//#define LOCAL

#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 1000005

char s[maxn];
char t[maxn];

int main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	while(scanf("%s%s",s,t)==2)
	{
		int ls = strlen(s);
		int lt = strlen(t);
		if(ls>lt)
		{
			printf("No\n");
			continue;
		}
		int i,j;
		for(i=0,j=0;i<ls&&j<lt;j++)
		{
			if(s[i]==t[j]) i++;
		}
		if(i==ls) printf("Yes\n");
		else printf("No\n");
	}
}
