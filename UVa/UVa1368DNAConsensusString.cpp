/*
* 20170731
*/

//#define LOCAL
//#define TEST

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

#define maxa 55
#define maxb 1005

char str[maxa][maxb];
char ans[maxb];
map<char,int> s;

int main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(ans,0,sizeof(ans));
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++) scanf("%s",str[i]);
		for(int i=0;i<b;i++)
		{
			s.clear();
			for(int j=0;j<a;j++)
			{
				s[str[j][i]]++;
			}
			#ifdef TEST
				printf("A:%d C:%d G:%d T:%d\n",s['A'],s['C'],s['G'],s['T']);
			#endif
			if(s['A']>=s['C']&&s['A']>=s['G']&&s['A']>=s['T']) ans[i]='A';
			else if(s['C']>=s['G']&&s['C']>=s['T']) ans[i]='C';
			else if(s['G']>=s['T']) ans[i] = 'G';
			else ans[i] = 'T';
		}
		int res = 0;
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++)
			{
				if(str[i][j]!=ans[j]) res++;
			}
		}
		printf("%s\n%d\n",ans,res);
	}
	return 0;
}
