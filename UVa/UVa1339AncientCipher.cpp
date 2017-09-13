/*
* 20170913
*/

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	char a[105];
	char b[105];
	while(scanf("%s%s",a,b)==2)
	{
		int na[30];
		int nb[30];
		memset(na,0,sizeof(na));
		memset(nb,0,sizeof(nb));
		int l = strlen(a);
		for(int i=0;i<l;i++)
		{
			na[a[i]-'A']++;
			nb[b[i]-'A']++;
		}
		sort(na,na+30);
		sort(nb,nb+30);
		bool flag = true;
		for(int i=0;i<30;i++)
		{
			if(na[i]!=nb[i])
			{
				flag = false;
				break;
			}
		}
		printf("%s\n",flag?"YES":"NO");
	}
	return 0;
}