/*
* 20170803
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

using namespace std;

map<char,int> sum;
int n,m;
char str[105][105];

bool solve()
{
	bool flag;
	//A
	if(n%3==0) 
	{
		flag = true;
		for(int i=0;i<n;i+=(n/3))
		{
			for(int j=0;j<m;j++)
			{
				for(int k=i;k<i+(n/3);k++)
				{
					sum[str[k][j]]++;
					if(str[k][j]!=str[i][0]) flag = false;
				}
			}
		}
		if(flag&&sum['R']==sum['G']&&sum['R']==sum['B'])
			return true;
	}
	//B
	if(m%3==0)
	{	
		flag = true;
		for(int i=0;i<m;i+=(m/3))
		{
			for(int j=0;j<n;j++)
			{
				for(int k=i;k<i+(m/3);k++)
				{
					sum[str[j][k]]++;
					if(str[j][k]!=str[0][i]) flag = false;
				}
			}
		}
		if(flag&&sum['R']==sum['G']&&sum['R']==sum['B'])
			return true;
	}
	return false;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",str[i]);
	printf("%s\n",solve()?"YES":"NO");
	return 0;
}