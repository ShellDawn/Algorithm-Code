// 最大相同数的数量

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int num[105];

int main(){
    memset(num,0,sizeof(num));
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        num[k] ++;
    }
    int ans = 0;
    for(int i=1;i<=100;i++){
        ans = max(ans,num[i]);
    }
    printf("%d\n",ans);
    return 0;
} 