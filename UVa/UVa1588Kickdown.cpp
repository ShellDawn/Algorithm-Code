/*
* 20170816
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

char a[105];
char b[105];

int main()
{
	while(scanf("%s%s",a,b)==2)
	{
		int la = strlen(a);
		int lb = strlen(b);
		int ans = la + lb;
		if(la<lb){swap(a,b);swap(la,lb);}
		for(int i=0;i<la;i++)
		{
			bool flag = true;
			for(int j=0;j<lb&&(i+j<la);j++)
			{
				if((a[i+j]-'0')+(b[j]-'0')>3)
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				ans = min(ans,max(la,lb+i));
				break;
			}
		}
		for(int i=0;i<lb;i++)
		{
			bool flag = true;
			for(int j=0;j<la&&(i+j<lb);j++)
			{
				if((b[i+j]-'0')+(a[j]-'0')>3)
				{
					flag = false;
					break;
				}
			}
			if(flag)
			{
				ans = min(ans,max(la+i,lb));
				break;
			}
		}
		printf("%d\n",ans);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
	}
	return 0;
}