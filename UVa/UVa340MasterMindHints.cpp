/*
* 20170728
*/

//#define LOCAL

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxn 1005


int num[maxn];
int test[maxn];
int power[10];
int p[10];

int main()
{ 
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int N;
	int cnt = 1;
	while(scanf("%d",&N)==1)
	{
		if(N == 0) break;
		printf("Game %d:\n",cnt++);
		memset(num,0,sizeof(num));
		memset(power,0,sizeof(power));
		for(int i=0;i<N;i++)
		{
			scanf("%d",&num[i]);
			power[num[i]]++;
		}
		while(true)
		{
			memset(test,0,sizeof(test));
			memset(p,0,sizeof(p));
			for(int i=0;i<N;i++)
			{
				scanf("%d",&test[i]);
			}
			if(test[0] == 0)
			{
				break;
			}
			for(int i=0;i<10;i++)
			{
				p[i] = power[i];
			}
			int A = 0,B = 0;
			for(int i=0;i<N;i++)
			{
				if(test[i] == num[i])
				{
					p[test[i]]--;
					test[i] = 0;
					A++;
				}
			}
			for(int i=0;i<N;i++)
			{
				if(test[i]!=0&&p[test[i]]>0&&test[i]!=num[i])
				{
					B++;
					p[test[i]]--;
				}
			}
			printf("    (%d,%d)\n",A,B);
		}
	}
	return 0;
}