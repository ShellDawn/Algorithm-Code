/*
* 20170731
*/

#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 85

char str[maxn];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		getchar();
		scanf("%s",str);
		int l = strlen(str);
		int ans = l;
		for(int i=1;i<l;i++)
		{
			if(l%i==0)
			{
				bool flag = true;
				for(int j=0;j<i;j++)
				{
					for(int k=1;j+i*k<l;k++)
					{
						if(str[j]!=str[j+i*k])
						{
							flag = false;
							break;
						}
					}
					if(!flag) break;
				}
				if(flag)
				{
					ans = i;
					break;
				}
			}
		}
		printf("%d%s",ans,T?"\n\n":"\n");
	}
	return 0;
}
