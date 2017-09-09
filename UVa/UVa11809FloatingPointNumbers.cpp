/*
 * 20170909
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

//鉴别精度由打表分析看出的
#define eps 0.0001

double ans[31][10];

int main()
{
	memset(ans,0,sizeof(ans));
	
	//枚举E和M的所有情况
	//通过每次迭代生成E，i为E位数
	long long E = 0;
	for(int i=1;i<=30;i++)
	{
		E++;
		E = E*2 - 1;
		//通过每次迭代生成M，j为M位数
		double t = 1.0;
		for(int j=0;j<=9;j++)
		{
			t/=2;
			double M = 1 - t;
			//double s = log10(M) + E * log10(2);
			//printf("%d %d %.15f\n",j,i,s);
			ans[i][j] = log10(M) + E * log10(2);
		}
	}

	char str[50];
	while(scanf("%s",str)==1)
	{
		if(str[0]=='0'&&str[1]=='e'&&str[2]=='0') break;
		double A = 0;
		for(int i = 16;i>=2;i--)
		{
			A+=(str[i]-'0');
			A/=10;
		}
		A+=(str[0]-'0');
		int l = strlen(str);
		double B = 0;
		for(int i = 18;i<l;i++)
		{
			B*=10;
			B+=(str[i]-'0');
		}
		bool flag = false;
		for(int i = 1;i<=30;i++)
		{
			for(int j=0;j<=9;j++)
			{
				if(B+log10(A)-ans[i][j]<eps)
				{
					printf("%d %d\n",j,i);
					//printf("%d %d %f %f %.15f\n",j,i,A,B,B+log10(A));
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
	}
	return 0;
}