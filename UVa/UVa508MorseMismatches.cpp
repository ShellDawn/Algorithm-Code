/*
* 20171215
*/

/*
multi match !
need make up ?
than same
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char sC[30][10];
char sN[20][10];
char ans[1000][1000];
char mtc[1000][5000];
int cnt = 0;

int main()
{
    memset(sC,0,sizeof(sC));
    memset(sN,0,sizeof(sN));
    memset(ans,0,sizeof(ans));
    memset(mtc,0,sizeof(mtc));
    //read dictionary
    for(int i=0;i<26;i++) scanf("%*s%s",sC[i]);
    for(int i=0;i<10;i++) scanf("%*s%s",sN[i]);

    scanf("%*s");
    //read word
    while(scanf("%s",ans[cnt])==1&&ans[cnt][0]!='*')
    {
        int l = strlen(ans[cnt]);
        int loc = 0;
        for(int i=0;i<l;i++)
        {
            if(ans[cnt][i]>='A'&&ans[cnt][i]<='Z')
            {
                int key = ans[cnt][i] - 'A';
                strcat(mtc[cnt],sC[key]);
            }else
            {
                int key = ans[cnt][i] - '0';
                strcat(mtc[cnt],sN[key]);
            }
        }
        cnt++;
    }
    
    //for(int i=0;i<cnt;i++) printf("%s %s\n",ans[i],mtc[i]);

    char res[5000];
    while(scanf("%s",res)==1&&res[0]!='*')
    {
        int k = 0;
        int t = 0;
        for(int i=0;i<cnt;i++)
        {
            if(strcmp(res,mtc[i])==0)
            {
                t = i;
                k++;
            }
        }
        if(k==1) printf("%s\n",ans[t]);
        else if(k>1) printf("%s!\n",ans[t]);
        else
        {
            int m = -1;
            int n = 5000;
            int resl = strlen(res);
            for(int i=0;i<cnt;i++)
            {
                int mtcl = strlen(mtc[i]);
                bool flag = true;
                for(int j=0;flag&&j<min(mtcl,resl);j++)
                {
                    if(res[j]!=mtc[i][j]) flag = false;
                }
                if(flag&&abs(mtcl-resl)<n)
                {
                    n = abs(mtcl - resl);
                    m = i;
                } 
            }
            if(m!=-1) printf("%s?\n",ans[m]);
            else printf("None\n");
        }
    }
    return 0;
}
