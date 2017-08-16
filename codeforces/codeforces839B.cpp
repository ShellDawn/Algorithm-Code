/*
* 201708016
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int numf = n;
	int numt = n*2;
	int numo = 0;
	for(int i=0;i<k;i++)
	{
		int t;
		scanf("%d",&t);
		int a = t/4;
		int b = t%4;
		if(a>numf)
		{
			a-=numf;
			numf=0;
			//leave = b
			b += a*4;
			int c = b/2;
			int d = b%2;
			if(c>numt)
			{
				c-=numt;
				numt=0;
				//leave = d
				d+=c*2;
				if(d>numo)
				{
					printf("NO\n");
					return 0;
				}else
				{
					numo-=d;
				}
			}else
			{
				numt-=c;
				if(d==1)
				{
					if(numo>0) numo--;
					else if(numt>0){
						numt--;
					}else{
						printf("NO\n");
						return 0;
					}
				}
			}
		}else
		{
			numf-=a;
			if(b==3)
			{
				if(numo>2) numo-=3;
				else if(numt>0&&numo>0){
					numt--;
					numo--;
				}else if(numf>0) numf--;
				else if(numt>1) numt-=2;
				else{
					printf("NO\n");
					return 0;
				}
			}else if(b==2)
			{
				if(numt>0) numt--;
				else if(numf>0)
				{
					numf--;
					numo++;
				}else if(numo>1) numo-=2;
				else if(numo>0&&numf>0)
				{
					numo--;
					numf--;
					numt++;
				}else{
					printf("NO\n");
					return 0;
				}
			}else if(b==1){
				if(numo>0) numo--;
				else if(numf>0){
					numf--;
					numt++;
				}else if(numt>0) numt--;
				else
				{
					printf("NO\n");
					return 0;					
				}
			}
		}
	}
	printf("YES\n");
	return 0;
}
