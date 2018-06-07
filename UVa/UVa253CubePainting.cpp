/*
* 20171119
*/

#include <cstdio>
#include <cstring>

int e[10][10];

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("ans.txt","w",stdout);
	memset(e,0,sizeof(e));
    e[1][2] = e[2][1] = 1;
    e[1][3] = e[3][1] = 1;
    e[1][4] = e[4][1] = 1;
    e[1][5] = e[5][1] = 1;
    e[2][3] = e[3][2] = 1;
    e[2][4] = e[4][2] = 1;
    e[2][6] = e[6][2] = 1;
   	e[3][5] = e[5][3] = 1;
   	e[3][6] = e[6][3] = 1;
   	e[4][6] = e[6][4] = 1;
   	e[4][5] = e[5][4] = 1;
   	e[5][6] = e[6][5] = 1;
   	char num[100];
   	while(scanf("%s",num)==1)
   	{
   		char A[10],B[10];
   		for(int i=1;i<=6;i++)
   		{
   			A[i] = num[i-1];
   			B[i] = num[i+5];
   		}
   		bool flag = false;
   		for(int i=1;(!flag)&&i<=6;i++) if(B[i] == A[1])
   		{
			for(int j=1;(!flag)&&j<=6;j++) if(e[i][j]==1&&B[j]==A[2])
			{
				for(int k=1;(!flag)&&k<=6;k++) if(e[k][i]==1&&e[k][j]==1&&B[k]==A[3])
				{
					for(int x=1;(!flag)&&x<=6;x++) if(x!=j&&e[x][i]==1&&e[x][k]==1&&B[x]==A[5])
					{
						for(int y=1;(!flag)&&y<=6;y++) if(y!=k&&e[y][i]==1&&e[y][x]==1&&B[y]==A[4])
						{
							for(int z=1;(!flag)&&z<=6;z++) if(z!=i&&e[z][j]==1&&e[z][k]==1&&B[z]==A[6])
							{
								flag = true;
							}
						}
					}
				}
			}
   		}
   		printf("%s\n",flag?"TRUE":"FALSE");
   	}
    return 0;
}
