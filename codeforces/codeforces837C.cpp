/*
* 20170803
*/

#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Node{
	public:
		int x;
		int y;
	public:
		void init(int a,int b){x=a;y=b;}
};

Node N[105];

int n;
int X;
int Y;
int ans = 0;

int main()
{
	int a,b;
	scanf("%d%d%d",&n,&X,&Y);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a,&b);
		N[i].init(a,b);
	}
	for(int j=0;j<n;j++)
	{
		int a = N[j].x;
		int b = N[j].y;
		for(int i=0;i<n;i++)
		{
			if(i==j) continue;
			int ta = N[i].x;
			int tb = N[i].y;
			int ts = a*b+ta*tb;
			if((a<=X&&b<=Y)&&((X-a>=ta&&tb<=Y)||(Y-b>=tb&&ta<=X))) ans=max(ans,ts);
			else if((a<=X&&b<=Y)&&((X-a>=tb&&ta<=Y)||(Y-b>=ta&&tb<=X))) ans=max(ans,ts);
			else if((a<=Y&&b<=X)&&((X-b>=ta&&tb<=Y)||(Y-a>=tb&&ta<=X))) ans=max(ans,ts);
			else if((a<=Y&&b<=X)&&((X-b>=tb&&ta<=Y)||(Y-a>=ta&&tb<=X))) ans=max(ans,ts);
		}	
	}
	printf("%d\n",ans);
	return 0;
}