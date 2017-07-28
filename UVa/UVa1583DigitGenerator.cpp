/*
* 20170728
*/

#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define maxn 100100

int ans[maxn];

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<=100000;i++)
	{
		int sum = i;
		int key = i;
		while(key>0)
		{
			sum += key%10;
			key/=10;
		}
		if(ans[sum]!=0) ans[sum] = min(ans[sum],i);
		else ans[sum] = i;
	}
	for(int i=0;i<N;i++)
	{
		int t;
		scanf("%d",&t);
		printf("%d\n",ans[t]);
	}
	return 0;
}