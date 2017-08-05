/*
* 20170803
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	scanf("%d",&N);
	getchar();
	int ans = 0;
	int sum = 0;
	for(int i=0;i<N;i++)
	{
		char c;
		scanf("%c",&c);
		if(c==' ')
		{
			ans = max(ans,sum);
			sum = 0;
		}else
		{
			if(c>='A'&&c<='Z') sum++;
		}
	}
	printf("%d\n",max(sum,ans));
	return 0;
}