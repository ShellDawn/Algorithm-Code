/*
* 20170913
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>

using namespace std;

int main()
{
	int num = 0;
	while(scanf("%d",&num)&&num!=-1)
	{
		map<char,int> hsh;
		printf("Round %d\n",num);
		char str1[100];
		char str2[100];
		scanf("%s%s",str1,str2);
		int ans = 0;
		int l = strlen(str1);
		for(int i=0;i<l;i++)
		{
			if(hsh[str1[i]]==0)
			{
				hsh[str1[i]]=1;
				ans++;
			} 
		}
		l = strlen(str2);
		int cnt = 0;
		for(int i=0;i<l;i++)
		{
			if(hsh[str2[i]]==0){
				cnt++;
				if(cnt>6) break;
			}
			else
			{
				ans--;
				hsh[str2[i]] = 0;
				if(ans==0) break;
			}
		}
		if(cnt>6) printf("You lose.\n");
		else if(ans==0) printf("You win.\n");
		else printf("You chickened out.\n");
	}
	return 0;
}