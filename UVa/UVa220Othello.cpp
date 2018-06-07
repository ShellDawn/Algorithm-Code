/*
* 20171109
*/

//#define LOCAL

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

int dx[] = {-1,-1,-1,0,1,1,1,0};
int dy[] = {-1,0,1,1,1,0,-1,-1};
char m[10][10];
char now[5];
char nxt[5];

int main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("ans.txt","w",stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int nn=0;nn<n;nn++)
	{
		if(nn!=0) printf("\n");
		memset(m,0,sizeof(m));
		for(int i=1;i<=8;i++)
		{
			char mt[10];
			scanf("%s",mt);
			for(int j=1;j<=8;j++) m[i][j] = mt[j-1];
		}
		scanf("%s",now);
		if(now[0]=='W') sprintf(nxt,"B");
		else nxt[0] = 'W';
		char c[5];
		while(scanf("%s",c)==1)
		{
			if(c[0]=='L')
			{
				bool flag = false;
				for(int i=1;i<=8;i++) for(int j=1;j<=8;j++) if(m[i][j]=='-')
				{
					bool getout = true;
					for(int k=0;k<8&&getout;k++) if(m[i+dx[k]][j+dy[k]]==nxt[0])
					{
						for(int p=1;;p++)
						{
							if(m[i+p*dx[k]][j+p*dy[k]]==0||m[i+p*dx[k]][j+p*dy[k]]=='-') break;
							if(m[i+p*dx[k]][j+p*dy[k]]==nxt[0]) continue;
							if(m[i+p*dx[k]][j+p*dy[k]]==now[0])  
							{
								if(flag) printf(" ");
								flag = true;
								printf("(%d,%d)",i,j);
								getout = false;
								break;
							}
						}
					}
				}
				if(!flag) printf("No legal move.");
				printf("\n");
			}
			else if(c[0] == 'M')
			{
				bool flag = false;
				int i = c[1] - '0';
				int j = c[2] - '0';
				for(int k=0;k<8;k++) if(m[i+dx[k]][j+dy[k]]==nxt[0])
				{
					for(int p=1;;p++)
					{
						if(m[i+p*dx[k]][j+p*dy[k]]==0||m[i+p*dx[k]][j+p*dy[k]]=='-') break;
						if(m[i+p*dx[k]][j+p*dy[k]]==nxt[0]) continue;
						if(m[i+p*dx[k]][j+p*dy[k]]==now[0]){ flag = true; break;}
					}
				}
				if(!flag) swap(now[0],nxt[0]);
				m[i][j] = now[0];
				i = c[1] - '0';
				j = c[2] - '0';
				for(int k=0;k<8;k++) if(m[i+dx[k]][j+dy[k]]==nxt[0])
				{
					for(int p=1;;p++)
					{
						if(m[i+p*dx[k]][j+p*dy[k]]==0||m[i+p*dx[k]][j+p*dy[k]]=='-') break;
						if(m[i+p*dx[k]][j+p*dy[k]]==nxt[0]) continue;
						if(m[i+p*dx[k]][j+p*dy[k]]==now[0])
						{
							for(int t=p-1;t>=1;t--) m[i+t*dx[k]][j+t*dy[k]] = now[0];
							break;
						}
					}
				}
				map<char,int> cnt;
				for(i=1;i<=8;i++) for(j=1;j<=8;j++)
				{
					if(m[i][j]=='W') cnt['W']++;
					else if(m[i][j]=='B') cnt['B']++;
				}
				printf("Black -%3d White -%3d\n",cnt['B'],cnt['W']);
				swap(now[0],nxt[0]);
			}
			else if(c[0] == 'Q')
			{
				for(int i=1;i<=8;i++)
				{
					for(int j=1;j<=8;j++)
					{
						printf("%c",m[i][j]);
					}
					printf("\n");
				}
				break;
			}
		}
	}
	return 0;
}

