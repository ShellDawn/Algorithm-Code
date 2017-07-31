/*
* 20170731
*/

#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 10

int ans[maxn];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int N;
		memset(ans,0,sizeof(ans));
		scanf("%d",&N);
		for(int i=1;i<=N;i++)
		{
			int t = i;
			while(t>0)
			{
				ans[t%10]++;
				t/=10;
			}
		}
		for(int i=0;i<10;i++) printf("%d%s",ans[i],i==9?"\n":" ");
	}
	return 0;
}
