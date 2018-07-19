#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n,k,d;
vector<pair<int,int> > v;
bool flagA = false;
bool flagB = false;
int cnt = 0;

// 父节点编号，当前深度，最大深度
void dfs(int fa,int nd,int mxd){
    if(nd > mxd) return ;
    // 在合理深度内
    int now = cnt++; // 获取当前节点
    if(now > n) return ;
    // 在合理数量内
    v.push_back(make_pair(fa,now)); // 生成路径
    if(cnt > n){
        flagB = true;
        return ;
    }
    if(nd == mxd){
        flagA = true;
        return ;
    }
    if(flagA){
        for(int i=0;i<k-1;i++){
            if(flagB) return ;
            dfs(now,nd+1,min(mxd,nd*2));
        }
    }else{
        dfs(now,nd+1,d);
        for(int i=1;i<k-1;i++){
            if(flagB) return ;
            dfs(now,nd+1,min(mxd,nd*2));
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&d,&k);
    if(n <= d) return 0*printf("NO\n");
    if(k==1){
        if(n==2) return 0*printf("YES\n1 2\n");
        return 0*printf("NO\n");
    }
    cnt = 2;
    dfs(1,1,d);
    if(flagB){
        printf("YES\n");
        for(vector<pair<int,int> >::iterator p=v.begin();p!=v.end();p++){
            printf("%d %d\n",p->first,p->second);
        }
    }else return 0*printf("NO\n");
    return 0;
}