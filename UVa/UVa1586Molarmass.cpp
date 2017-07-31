/*
* 20170731
*/

//#define LOCAL

#include <cstdio>
#include <cctype>
#include <cstring>
#include <map>

using namespace std;

#define maxn 85

char str[maxn];
map<char,float> ms;

int main()
{
	ms['C'] = 12.01;
	ms['H'] = 1.008;
	ms['O'] = 16.00;
	ms['N'] = 14.01;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		float ans = 0;
		scanf("%s",str);
		int l = strlen(str);
		int p = 0;
		char c = str[0];
		for(int i=1;i<l;i++)
		{
			if(isalpha(str[i]))
			{
				#ifdef LOCAL
					printf("c:%c str[i]:%c p:%d\n",c,str[i],p);
				#endif
				if(p==0) ans+=ms[c];
				else ans+=(p*ms[c]);
				c = str[i];
				p = 0;
			}else
			{
				p*=10;
				p+=(str[i] - '0');
			}
		}
		if(p==0) ans+=ms[c];
		else ans+=(p*ms[c]);
		printf("%.3f\n",ans);
	}
	return 0;
}



