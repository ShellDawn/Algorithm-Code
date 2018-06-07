/*
* 20171030
*/

//#define LOCAL

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define maxn 10000UVaRandom

struct Command
{
	char s[5];
	int r1,c1,r2,c2;
	int A;
	int a[15];
}cmd[maxn];

int loc = 0;

void solve(int x,int y)
{
	int tx = x;
	int ty = y;
	int tmp = 0;
	for(int i=0;i<loc;i++)
	{
		//exchange
		if(cmd[i].s[0]=='E')
		{
			//printf("!!! EX %d %d %d %d tx:%d ty:%d\n",cmd[i].r1,cmd[i].c1,cmd[i].r2,cmd[i].c2,tx,ty);
			//the first condition
			if(tx==cmd[i].r1&&ty==cmd[i].c1){tx=cmd[i].r2;ty=cmd[i].c2;}
			//the second condition
			else if(tx==cmd[i].r2&&ty==cmd[i].c2){tx=cmd[i].r1;ty=cmd[i].c1;}
		}

		//delete
		if(cmd[i].s[0]=='D')
		{
			//delete r
			if(cmd[i].s[1]=='R')
			{
				tmp = 0;
				for(int j=0;j<cmd[i].A;j++)
				{
					if(tx>cmd[i].a[j]) tmp++;
					if(tx==cmd[i].a[j]){printf("Cell data in (%d,%d) GONE\n",x,y);return ;}
				}
				tx-=tmp;
			}

			//delete c
			if(cmd[i].s[1]=='C')
			{
				tmp = 0; 
				for(int j=0;j<cmd[i].A;j++)
				{
					if(ty>cmd[i].a[j]) tmp++;
					if(ty==cmd[i].a[j]){ printf("Cell data in (%d,%d) GONE\n",x,y);return ;}
				}
				ty-=tmp;
			}
		}

		//insert
		if(cmd[i].s[0]=='I')
		{
			if(cmd[i].s[1]=='R')
			{
				tmp = 0;
				for(int j=0;j<cmd[i].A;j++) if(tx>=cmd[i].a[j]) tmp++;
				tx+=tmp;
			}

			if(cmd[i].s[1]=='C')
			{
				tmp = 0;
				for(int j=0;j<cmd[i].A;j++) if(ty>=cmd[i].a[j]) tmp++;
				ty+=tmp;
			}
		}
		//printf("!!! %d %d\n",tx,ty);
	}
	printf("Cell data in (%d,%d) moved to (%d,%d)\n",x,y,tx,ty);
}

int main()
{
	#ifdef LOCAL
		freopen("test.txt","r",stdin);
		freopen("b.txt","w",stdout);
	#endif
	int r,c;
	int cnt = 0;
	while(scanf("%d%d",&r,&c)==2&&r)
	{
		loc = 0;
		memset(cmd,0,sizeof(cmd));
		int n;
		if(cnt>0) printf("\n");
		printf("Spreadsheet #%d\n",++cnt);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%s",cmd[loc].s);
			if(cmd[loc].s[0]=='E')
			{
				scanf("%d%d%d%d",&cmd[loc].r1,&cmd[loc].c1,&cmd[loc].r2,&cmd[loc].c2);
			}
			else
			{
				scanf("%d",&cmd[loc].A);
				for(int j=0;j<cmd[loc].A;j++)
				{
					scanf("%d",&cmd[loc].a[j]);
				}
			}
			loc++;
		}
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			solve(x,y);
		}
	}
	return 0;
}