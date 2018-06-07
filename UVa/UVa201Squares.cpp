/*
* 20171109
*/

//#define LOCAL

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int num[10][10][10][10];
int ans[10];
int n;

bool hline(int x,int y,int dx,int dy,int k)
{
	for(int i=0;i<k;i++) 
		if(num[x+i*dx][y+i*dy][x+(i+1)*dx][y+(i+1)*dy]!=1) 
			return false;
	return true;
}	

void judge(int x,int y,int z)
{
	if(hline(x,y,1,0,z)&&
		hline(x,y,0,1,z)&&
		hline(x+z,y,0,1,z)&&
		hline(x,y+z,1,0,z))
	{
		ans[z]++;
	}
}

void print()
{
	bool flag = false;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]!=0)
		{
			flag = true;
			printf("%d square (s) of size %d\n",ans[i],i);
		}
	}
	if(!flag) printf("No completed squares can be found.\n");
}

int main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("ans.txt","w",stdout);
	#endif
	int cnt = 1;
	while(scanf("%d",&n)==1)
	{
		if(cnt!=1) printf("\n**********************************\n\n");
		printf("Problem #%d\n\n",cnt++);
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
		int m;
		scanf("%d",&m);
		while(m--)
		{
			char c[5];
			int x,y;
			scanf("%s%d%d",c,&x,&y);
			if(c[0]=='H') num[x][y][x][y+1] = 1; 
			else num[y][x][y+1][x] = 1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				for(int k=1;k<=n-max(i,j);k++)
				{
					judge(i,j,k);
				}
			}
		}
		print();
	}
	return 0;
}
