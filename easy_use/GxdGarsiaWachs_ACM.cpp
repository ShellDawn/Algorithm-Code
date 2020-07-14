#include <cstdio>
#include <cstring>

using namespace std;

#define maxn 50050          // 叶子节点数
#define maxV 1000000001  // 权费最大和

int S = 1; // 链表起始节点
int L = 0;  // 链表长度
long long V[maxn]; // 叶子值
int LAST[maxn];  // 前向链
int NEXT[maxn]; // 后向链

int main(){
    int n;
    while(scanf("%d",&n)!=EOF && n){
        memset(V,0,sizeof(V));
        memset(LAST,0,sizeof(LAST));
        memset(NEXT,0,sizeof(NEXT));
        L = n;
        S = 1;
        for(int i=1;i<=L;i++){
            scanf("%lld",&V[i]);
            LAST[i] = i-1;
            NEXT[i] = i+1;
        }
        NEXT[L] = 0;
        V[0] = maxV;
        V[L+1] = maxV;
        long long ans = 0;
        int st = S;
        while(L>2){
            int i = st;
            while(i!=0){
                int a = LAST[i];
                int b = NEXT[i];
                if(V[a] <= V[b]){
                    V[a] += V[i];
                    ans += V[a];
                    NEXT[a] = b;
                    LAST[b] = a;
                    i = a;
                    break;
                }
                i = NEXT[i];
            }
            L--;
            int j = i;
            while(j!=0){
                int j_last = LAST[j];
                if(V[j_last] >= V[i]){
                    if(i==j) break;
                    int a = LAST[i];
                    int b = NEXT[i];
                    NEXT[a] = b;
                    LAST[b] = a;
                    NEXT[i] = j;
                    LAST[i] = j_last;
                    LAST[j] = i;
                    NEXT[j_last] = i;
                    if(j_last == 0) S = i;
                    break;
                }
                j = LAST[j];
            }
            for(int k=0;k<2;k++){
                if(i==S) break;
                i = LAST[i];
            }
            st = i;
        }
        if(L==2) printf("%lld\n",ans+V[S]+V[NEXT[S]]);
        if(L==1) printf("0\n");
    }
    return 0;
}