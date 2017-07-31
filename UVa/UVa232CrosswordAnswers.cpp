/*
* 20170731
*/

//#define LOCAL
//#define TEST

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxn 12

char m[maxn][maxn];
int n[maxn][maxn];

int main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int a,b;
	int T = 1;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(T!=1) printf("\n");
		getchar();
		memset(m,0,sizeof(m));
		memset(n,0,sizeof(n));
		int cnt = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				scanf("%c",&m[i][j]);
			}
			getchar();
		}
		#ifdef TEST
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				printf("%c",m[i][j]);
			}
			printf("\n");
		}
		#endif
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(m[i][j]!='*'&&(m[i-1][j]=='*'||m[i-1][j]==0||
					m[i][j-1]=='*'||m[i][j-1]==0))
				{
					n[i][j] = ++cnt;
				}
			}
		}
		#ifdef TEST
			for(int i=1;i<=a;i++)
			{
				for(int j=1;j<=b;j++)
				{
					printf("%2d ",n[i][j]);
				}
				printf("\n");
			}
		#endif
		printf("puzzle #%d:\nAcross\n",T++);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(m[i][j]!='*'&&(m[i][j-1]=='*'||m[i][j-1]==0))
				{
					printf("%3d.",n[i][j]);
					for(int k=j;k<=b;k++)
					{
						if(m[i][k]=='*') break;
						printf("%c",m[i][k]);
					}
					printf("\n");
				}
			}
		}
		printf("Down\n");
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(m[i][j]!='*'&&(m[i-1][j]=='*'||m[i-1][j]==0))
				{
					printf("%3d.",n[i][j]);
					for(int k=i;k<=a;k++)
					{
						if(m[k][j]=='*') break;
						printf("%c",m[k][j]);
					}
					printf("\n");
				}
			}
		}
	}
	return 0;
}

