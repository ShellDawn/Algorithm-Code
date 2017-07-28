/*
* 20170728
*/

//#define LOCAL

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxn 100

char str[maxn];

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
		scanf("%s",str);
		int l = strlen(str);
		int cnt = 1;
		int ans = 0;
		for(int i=0;i<l;i++)
		{
			if(str[i] == 'O')
			{
				ans += cnt;
				cnt++;
			}else
			{
				cnt = 1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}