// 前缀和，区间查询

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,k;
int num[5050];
int sum[5050];

int main(){
    memset(num,0,sizeof(num));
    memset(sum,0,sizeof(sum));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&num[i]);
    }

    for(int i=1;i<=n;i++){
        sum[i] += sum[i-1]+num[i];
    }
    //for(int i=1;i<=n+1;i++) printf("num:%d\n",sum[i]);

    double ans = 0;
    for(int i=0;i+k<=n;i++){
        for(int j=i+k;j<=n;j++){
            ans = max(ans,(double)(sum[j]-sum[i])/(j-i));
        }
    }
    printf("%f\n",ans);
    return 0;
}