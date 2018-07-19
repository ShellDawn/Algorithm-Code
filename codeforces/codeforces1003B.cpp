// 构造01串满足条件

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int a,b,x;
    scanf("%d%d%d",&a,&b,&x);
    
    int flag1 = 0;
    int flag2 = 1;
    if(a > b){
        swap(a,b);
        swap(flag1,flag2);
    }

    if(x%2==1){
        int k = (x-1)/2;
        for(int i=0;i<k;i++){
            printf("%d%d",flag2,flag1);
        }
        for(int i=0;i<b-k;i++){
            printf("%d",flag2);
        }
        for(int i=0;i<a-k;i++){
            printf("%d",flag1);
        }
    }else{
        int k = x/2;
        for(int i=0;i<k;i++){
            printf("%d%d",flag2,flag1);
        }
        for(int i=0;i<a-k;i++){
            printf("%d",flag1);
        }
        for(int i=0;i<b-k;i++){
            printf("%d",flag2);
        }
    }
}