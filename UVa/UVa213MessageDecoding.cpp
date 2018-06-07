/*
* 20171028
*/

#define LOCAL

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 1000

char code[8][1<<8];
char head[maxn];

int readchar()
{
	char t = getchar();
	if(t=='0'||t=='1') return t-'0';
	else return readchar();
}

bool readlen(int& len)
{
	int a = readchar();
	int b = readchar();
	int c = readchar();
	len = a*4+b*2+c;
	if(len==0)
	{
		//printf("the all code is over!\n");
		return false;
	}
	return true;
}

bool readcode(int len)
{
	int v = 0;
	for(int i=0;i<len;i++)
	{
		v*=2;
		v+=readchar();
	}
	if(v>=((1<<len)-1))
	{
		//printf("the segment is over!\n");
		return false;
	}
	//printf("len:%d v:%d\n code:%c\n",len,v,code[len][v]);
	printf("%c",code[len][v]);
	return true;
}

void solvecode()
{
	int len = 0;
	while(readlen(len))
	{
		while(readcode(len));
	}
}

int main()
{
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	while(fgets(head,maxn,stdin)!=NULL)
	{
		printf("%s\n",head);
		return 0;
		memset(code,0,sizeof(code));
		int len = strlen(head)-1;
		int loc = 0;
		int i = 0;
		while(i<len)
		{
			int j = 0;
			loc++;
			while(j<((1<<loc)-1))
			{
				code[loc][j] = head[i];
				//printf("loc:%d j:%d code:%c head:%c\n",loc,j,code[loc][j],head[i]);
				i++;
				j++;
				if(i>=len) break;
			}
		}
		solvecode();
		printf("\n");
		getchar();
	}
	return 0;
}