/*
* 20170728
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 105

char str[maxn];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",str);
		int l = strlen(str);
		int ans = 0;
		for(int i=1;i<l;i++)
		{
			for(int j=0;j<l;j++)
			{
				if(str[(i+j)%l] < str[(ans+j)%l])
				{
					//printf("J:%d\n",j);
					ans = i;break;
				}else if(str[(i+j)%l] > str[(ans+j)%l])
				{
					break;
				}
			}
			//printf("i:%d ans:%d\n",i,ans);
		}
		for(int i = ans;i<l;i++) printf("%c",str[i]);
		for(int i = 0;i<ans;i++) printf("%c",str[i]);
		printf("\n");
	}
	return 0;
}