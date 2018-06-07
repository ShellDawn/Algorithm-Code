/*
* 20171127
*/

#include <cstdio>
#include <algorithm>

int n;
int num[400];
int prefixSum[400];

int main()
{   
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&num[i]);
        prefixSum[i] = prefixSum[i-1]+num[i];
    }
    int ans = 360;
    for(int i=0;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            ans = std::min(ans,abs(180 - prefixSum[j] + prefixSum[i]));
        }
    }
    printf("%d\n",ans*2);
    return 0;
}