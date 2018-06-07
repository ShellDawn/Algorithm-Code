/*
* 20171205
*/

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

char F[] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char A[] = "What are you doing while sending \"";
char B[] = "\"? Are you busy? Will you send \"";
char C[] = "\"?";

const long long FL = strlen(F);
const long long AL = strlen(A);
const long long BL = strlen(B);
const long long CL = strlen(C);
const long long ALL = FL+AL+BL+CL;

char solve(long long a,long long b)
{
    if(a==0)
    {
        if(b>FL) return '.';
        else return F[(b-1)%FL];
    }
    if(b<=AL) return A[(b-1)%AL];
    if(a>=57) return solve(a-1,b-AL);
    long long lastL = 1;
    lastL<<=(a-1);
    lastL*=ALL;
    lastL-=(AL+BL+CL); 
    if(b<=AL) return A[(b-1)%AL];
    b-=AL;
    if(b<=lastL) return solve(a-1,b);
    b-=lastL; 
    if(b<=BL) return B[(b-1)%BL];
    b-=BL;
    if(b<=lastL) return solve(a-1,b);
    b-=lastL;
    if(b<=CL) return C[(b-1)%CL];
    return '.';
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n,m;
        scanf("%I64d%I64d",&n,&m);
        printf("%c",solve(n,m));
    }
    printf("\n");
    return 0;
}

/*
the length of fn is f0*2^n+(A+B+C)*(2^n-1),is (f0+A+B+C)*2^n-(A+B+C);
the length of fn-1 is (f0+A+B+C)*2^(n-1)-(A+B+C);
and the max of k is 10^18 about 2^60,strictly less than 2^60
and the max number in long long type is 9223372036854775807 (19 digit,2^63)
f0 75 = 75
f1 34 75 32 75 2 = 218
f2 34 218 32 218 2 = 504
*/