/*
* 20171128
*/

#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 100010

int n;
long long x,k;
long long num[maxn];

int main()
{
    scanf("%d%I64d%I64d",&n,&x,&k);
    for(int i=0;i<n;i++) scanf("%I64d",&num[i]);
    sort(num,num+n);
    long long ans = 0;
    for(int i=0;i<n;i++)
    {
        long long t = num[i]%x;
        long long left,right;
        if(t==0)
        {
            left = max(num[i],num[i]+k*x-x);
            right = num[i]+k*x;
        }else
        {
            left = max(num[i],num[i]+k*x-t);
            right = num[i]+k*x+x-t;
        }
        ans+=(lower_bound(num,num+n,right)-lower_bound(num,num+n,left));
    }
    printf("%I64d\n",ans);
    return 0;
}  