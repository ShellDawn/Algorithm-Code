/*
* 201708012
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int ans = 0;
	int last = 0;
	for(int i=0;i<n;i++)
	{
		int t;
		scanf("%d",&t);
		if(last+t>8){
			last = t+last - 8;
			ans+=8;
		}else
		{
			ans+=(last+t);
			last = 0;
		}
		if(ans>=k)
		{
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}