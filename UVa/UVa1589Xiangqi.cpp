/*
* 20171108
*/

//#define LOCAL 
//#define TEST

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int dx[] = {1,-1,-2,-2,-1,1,2,2};
const int dy[] = {-2,-2,-1,1,2,2,1,-1};
const int fx[] = {0,-1,0,1};
const int fy[] = {-1,0,1,0};
char mp[20][20];
int ans[20][20];
int a,b;

int main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("ans.txt","w",stdout);
	#endif
	int n;
	while(scanf("%d%d%d",&n,&a,&b)==3&&n)
	{
		memset(mp,0,sizeof(mp));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=10;i++) for(int j=1;j<=9;j++) ans[i][j] = 1;

		while(n--)
		{
			char tc[5];
			int x,y;
			scanf("%s%d%d",tc,&x,&y);
			mp[x][y] = tc[0];
		}
		
		//solve
		for(int i=1;i<=10;i++)
		{
			for(int j=1;j<=9;j++)
			{
				if(mp[i][j]=='R'||mp[i][j]=='G')
				{
					for(int k=j+1;k<=9;k++)
					{
						ans[i][k] = 0;
						if(mp[i][k]!=0) break;
					}
					for(int k=j-1;k>=1;k--)
					{
						ans[i][k] = 0;
						if(mp[i][k]!=0) break;
					}
					for(int k=i+1;k<=10;k++)
					{
						ans[k][j] = 0;
						if(mp[k][j]!=0) break;
					}
					for(int k=i-1;k>=1;k--)
					{
						ans[k][j] = 0;
						if(mp[k][j]!=0) break;
					}
					#ifdef TEST
						printf("%c\n",mp[i][j]);
						for(int i=0;i<11;i++)
						{
							for(int j=0;j<10;j++)
							{
								printf("%d ",ans[i][j]);
							}
							printf("\n");
						}
					#endif
				}else if(mp[i][j]=='H')
				{
					for(int k=0;k<4;k++)
					{
						if(mp[i+fx[k]][j+fy[k]]==0)
						{
							if(i+dx[k*2]>=0&&j+dy[k*2]>=0) ans[i+dx[k*2]][j+dy[k*2]] = 0;
							if(i+dx[k*2+1]>=0&&j+dy[k*2+1]>=0) ans[i+dx[k*2+1]][j+dy[k*2+1]] = 0;
						}
					}
					#ifdef TEST
						printf("%c\n",mp[i][j]);
						for(int i=0;i<11;i++)
						{
							for(int j=0;j<10;j++)
							{
								printf("%d ",ans[i][j]);
							}
							printf("\n");
						}
					#endif
				}else if(mp[i][j]=='C')
				{
					bool flag = true;
					for(int k=j+1;k<=9&&flag;k++)
					{
						if(mp[i][k]!=0)
						{
							for(int u=k+1;u<=9;u++)
							{
								ans[i][u] = 0;
								if(mp[i][u]!=0){flag = false; break;}
							}
						}
					}
					flag = true;
					for(int k=j-1;k>=1&&flag;k--)
					{
						if(mp[i][k]!=0)
						{
							for(int u=k-1;u>=1;u--)
							{
								ans[i][u] = 0;
								if(mp[i][u]!=0){flag = false;break;}
							}
						}
					}
					flag = true;
					for(int k=i+1;k<=10&&flag;k++)
					{
						if(mp[k][j]!=0)
						{
							for(int u=k+1;u<=10;u++)
							{
								ans[u][j] = 0;
								if(mp[u][j]!=0){flag = false;break;}
							}
						}
					}
					flag = true;
					for(int k=i-1;k>=1&&flag;k--)
					{
						if(mp[k][j]!=0)
						{
							for(int u=k-1;u>=1;u--)
							{
								ans[u][j] = 0;
								if(mp[u][j]!=0){flag = false;break;}
							}
						}
					}
					#ifdef TEST
						printf("%c\n",mp[i][j]);
						for(int i=0;i<11;i++)
						{
							for(int j=0;j<10;j++)
							{
								printf("%d ",ans[i][j]);
							}
							printf("\n");
						}
					#endif
				}
			}
		}
		bool res = true;
		for(int i=0;i<4;i++) 
		{
			int ta = a+fx[i];
			int tb = b+fy[i];
			if(ta>=1&&ta<=3&&tb>=4&&tb<=6&&ans[a+fx[i]][b+fy[i]]==1){res = false;break;}
		}
		printf("%s\n",res?"YES":"NO");
	}
	return 0;
}
