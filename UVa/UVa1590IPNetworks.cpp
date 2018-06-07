/*
* 20171214
*/

/*
注意：
1，数字没有前导零，数字长度不一；
2，数字会出现0的情况；
3，注意初始化数组，因为要用0来结束字符串；
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define maxn 1005

char str[maxn][40];
int m;

int translateB(char* s,int l)
{
    int t = 0;
    for(int i=0;i<l;i++)
    {
        t*=10;
        t+=(*(s+i)-'0');
    }
    return t;
} 

void translateA(char* s,int t)
{
    for(int i=7;i>=0;i--)
    {
        s[i] = t%2 + '0';
        t>>=1;
    }
}

void translate(char* s,int l,char* t)
{
    int f[5];
    int tl[5];
    memset(f,0,sizeof(f));
    memset(tl,0,sizeof(tl));
    int cnt = 0;
    for(int i=0;i<l;i++) 
    {
        if(t[i] == '.')
        {
            cnt++;
            f[cnt] = i+1;
        }else{
            tl[cnt]++;
        }
    }
    for(int i=0;i<4;i++) translateA(s+i*8,translateB(t+f[i],tl[i]));
}

int solve(char* a,char* b)
{
    for(int i=0;i<32;i++)
    {
        if(a[i] != b[i]) return i;
    }
    return 32;
}

int itranslateB(char* s)
{
    int t = 0;
    for(int i=0;i<8;i++)
    {
        t<<=1;
        t+=(*(s+i)&1);
    }
    return t;
}

void itranslateA(char* a,int& l,int b)
{
    if(b>=100)
    {
        *(a+l++) = b/100 + '0';
        *(a+l++) = (b/10)%10 + '0';
        *(a+l++) = b%10 + '0';
    }else if(b>=10)
    {
        *(a+l++) = b/10 + '0';
        *(a+l++) = b%10 + '0';
    }else
    {
        *(a+l++) = b%10 + '0';
    }
}

void itranslate(char* a,char* b)
{
    int l = 0;
    for(int i=0;i<4;i++)
    {
        if(i!=0){
            *(a+l) = '.';
            l++;
        } 
        itranslateA(a,l,itranslateB(b+i*8));
    }
}

int main()
{

    //freopen("input.txt","r",stdin);
    //freopen("ans.txt","w",stdout);

    while(scanf("%d",&m)!=EOF)
    {
        memset(str,0,sizeof(str));
        for(int i=0;i<m;i++)
        {
            char t[40];
            scanf("%s",t);
            int l = strlen(t);
            translate(str[i],l,t);
        }

        int ans = 32;
        for(int i=0;i<m;i++) for(int j=0;j<m;j++)
        {
            int l = solve(str[i],str[j]);
            ans = min(ans,l);
        }

        for(int i=ans;i<32;i++) str[0][i] = '0';

        char res[40];
        memset(res,0,sizeof(res));
        for(int i=0;i<ans;i++) res[i] = '1';
        for(int i=ans;i<32;i++) res[i] = '0';

        char resA[40];
        char resB[40];
        memset(resA,0,sizeof(resA));
        memset(resB,0,sizeof(resB));
        itranslate(resA,str[0]);
        itranslate(resB,res);
        printf("%s\n%s\n",resA,resB);
    }
    return 0;
}