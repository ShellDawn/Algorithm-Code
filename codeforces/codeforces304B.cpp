/*
* 20171202
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char date1[20];
char date2[20];

bool isLeapYear(int a)
{
    if((a%4==0&&a%100!=0)||a%400==0) return true;
    return false;
}

int month(int m,int y)
{
    int mon[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeapYear(y)) mon[1] = 29;
    return mon[m-1];
}

int num(char* str,int a,int b)
{
    int ans = 0;
    for(int i=a;i<b;i++)
    {
        ans*=10;
        ans+=(str[i]-'0');
    }
    return ans;
}

int year()
{
   int y1 = num(date1,0,4);
   int y2 = num(date2,0,4);
   int m1 = num(date1,5,7);
   int m2 = num(date2,5,7);
   int d1 = num(date1,8,10);
   int d2 = num(date2,8,10);
   int ans = 0;
   if(y1==y2)
   {
        for(int m=m1+1;m<m2;m++) ans+=month(m,y1);
        if(m1==m2) return ans+d2-d1;
        else return ans+d2+month(m1,y1)-d1;
   }else
   {
        for(int y=y1+1;y<y2;y++)
            if(isLeapYear(y)) ans+=366;
            else ans+=365;
        for(int m=1;m<m2;m++) ans+=month(m,y2);
        for(int m=m1+1;m<13;m++) ans+=month(m,y1);
        return ans+d2+month(m1,y1)-d1;
   }
}

int main()
{
    scanf("%s%s",date1,date2);
    if(num(date1,0,4)*10000+num(date1,5,7)*100+num(date1,8,10)
        >num(date2,0,4)*10000+num(date2,5,7)*100+num(date2,8,10))
    {
        swap(date1,date2);
    }
    printf("%d\n",year());
    return 0;
}