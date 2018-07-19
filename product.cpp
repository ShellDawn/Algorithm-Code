#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(){
    srand(time(0));
    freopen("input.txt","w",stdout);
    int n = rand()%100+1;
    for(int j=0;j<n;j++){
        int num = rand()%50000+1;
        printf("%d",num);
        for(int i=0;i<num;i++){
            printf(" %d",rand()%1000+1);
        }
        printf("\n");
    }
    printf("0\n");
    return 0;
}