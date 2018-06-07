/*
* 20171026
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define maxn 30

int n,k,m;
int v[maxn];
int left[maxn];
int right[maxn];

int main()
{
	while(scanf("%d%d%d",&n,&k,&m)==3&&n)
	{
		memset(v,0,sizeof(v));
		memset(left,0,sizeof(left));
		memset(right,0,sizeof(right));
		k%=(n+1);
		m%=(n+1);
		for(int i=1;i<=n;i++)
		{
			v[i] = i;
			left[i] = i+1;
			right[i] = i-1;
		}
		left[n] = 1;
		right[1] = n;

		int know = 1;
		int mnow = n;

		//for(int i=0;i<=n;i++) printf("%d %d %d\n",v[i],left[i],right[i]);

		while(true)
		{
			//move
			int cnt = 1;
			while(cnt<k)
			{
				//printf("%d ",know);
				know = left[know];
				cnt++;
			}
			//printf("%d\n",know);
			cnt = 1;
			while(cnt<m)
			{
				//printf("%d ",mnow);
				mnow = right[mnow];
				cnt++;
			}
			//printf("%d\n",mnow);

			printf("%3d",v[know]);
			n--;
			if(know!=mnow)
			{
				printf("%3d",v[mnow]);
				n--;
			}

			//printf("!! %d %d\n",know,mnow); 

			//delete
			left[right[know]] = left[know];
			right[left[know]] = right[know];
			know = left[know];
			left[right[mnow]] = left[mnow];
			right[left[mnow]] = right[mnow];
			if(know==mnow) know = left[mnow];
			mnow = right[mnow];

			if(n>0) printf(",");
			else break;
		}
		printf("\n");
	}
	return 0;
}
