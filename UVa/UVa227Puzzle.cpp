/*
* 20170731
*/

//#define LOCAL
//#define TEST

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

char m[10][10];

map<char,int> x;
map<char,int> y;

int main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	x['A'] = -1;
	y['A'] = 0;
	x['B'] = 1;
	y['B'] = 0;
	x['L'] = 0;
	y['L'] = -1;
	x['R'] = 0;
	y['R'] = 1;
	int cnt = 0;
	while(true)
	{
		int locx = 0,locy = 0;
		cnt++;
		memset(m,0,sizeof(m));
		for(int i=1;i<=5;i++)
		{
			for(int j=1;j<=5;j++)
			{
				scanf("%c",&m[i][j]);
				if(m[i][j]=='Z') return 0;
				if(m[i][j]==' '){locx=i;locy=j;}
				#ifdef TEST
					printf("m[i][j]:%c locx:%d locy:%d\n",m[i][j],locx,locy);
				#endif
			}
			getchar();
		}
		bool flag = true;
		while(true)
		{
			char c;
			scanf("%c",&c);
			#ifdef TEST
				printf("input:%c\n",c);
			#endif
			if(c=='\n'||c==' ') continue;
			if(c=='0')
			{
				getchar();
				if(flag)
				{
					printf("%sPuzzle #%d:\n",cnt==1?"":"\n",cnt);
					for(int i=1;i<=5;i++)
					{
						for(int j=1;j<=5;j++)
						{
							printf("%c%s",m[i][j],j==5?"\n":" ");
						}
					}
				}else
				{
					printf("%sPuzzle #%d:\n",cnt==1?"":"\n",cnt);
					printf("This puzzle has no final configuration.\n");
				}
				break;
			}else
			{
				if(!flag) continue;
				if(m[locx+x[c]][locy+y[c]]==0)
				{
					flag = false;
				}else
				{
					#ifdef TEST
						printf("locx:%d locy:%d x[c]:%d y[c]:%d\n",locx,locy,x[c],y[c]);
					#endif
					swap(m[locx][locy],m[locx+x[c]][locy+y[c]]);
					locx+=x[c];
					locy+=y[c];
				}
			}
		}
	}
	return 0;
}
