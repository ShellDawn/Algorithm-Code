/*
* 20170801
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

map<int,int> m;
queue<int> q;

const char* str = " = number of digits in repeating cycle";

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		printf("%d/%d = ",a,b);
		m.clear();
		while(!q.empty()) q.pop();
		if(a>=b) printf("%d.",a/b);
		else printf("0.");
		int cnt = -1;
		a%=b;
		m[a] = cnt;
		cnt+=2;
		int ansa = 0;
		int ansb = 0;
		while(true)
		{
			a*=10;
			int c = a/b;
			a%=b;
			if(a==0)
			{
				if(c!=0)
				{
					q.push(c);
					cnt++;
				}
				q.push(0);
				ansa = cnt;
				ansb = cnt;
				break;
			}
			if(m[a]!=0)
			{
				q.push(c);
				if(m[a]==-1) ansa = 1;
				else ansa = m[a]+1;
				ansb = cnt;
				break;
			}
			if(c==0) q.push(0);
			else q.push(c);
			m[a] = cnt;
			cnt++;
		}
		int l = min(cnt,50);
		for(int i=1;i<=l;i++)
		{
			if(ansa == i) printf("(");
			printf("%d",q.front());
			q.pop();
			if(ansb == i) printf(")");
		}
		if(cnt>50) printf("...)");
		printf("\n   %d%s\n\n",ansb-ansa+1,str);
	}
	return 0;
}