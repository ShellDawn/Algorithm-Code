/*
* 201708012
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define maxn 100050

int color[maxn];
vector<int> m[maxn];
int n;
stack<int> tp;
stack<double> pp;
double ans = 0;

void solve(int loc,double p){
	color[loc] = 1;
	int cnt = m[loc].size();
	//printf("%d ans:%f cnt:%d\n",loc,ans,cnt);
	int res  = 0;
	for(int i=0;i<cnt;i++)
	{
		int c = m[loc][i];
		if(color[c]==0)
		{
			res++;
		}
	}
	p = p/res;
	for(int i=0;i<cnt;i++)
	{
		int c = m[loc][i];
		if(color[c]==0)
		{
			ans+=p;
			solve(c,p);
		}
	}
	color[loc] = 0;
}

int main()
{
	memset(color,0,sizeof(color));
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		m[a].push_back(b);
		m[b].push_back(a);
	}
	solve(1,1.0);
	printf("%.15f\n",ans);
	return 0;
}