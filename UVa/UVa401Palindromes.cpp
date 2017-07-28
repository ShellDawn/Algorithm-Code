/*
* 20170727
*/

//#define LOCAL

#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>

using namespace std;

#define maxn 1005

const char* str = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* res[] = {" -- is not a palindrome.",
					 " -- is a regular palindrome.",
					 " -- is a mirrored string.",
					 " -- is a mirrored palindrome."};
char s[maxn];

int main()
{
	while(scanf("%s",s)==1)
	{
		int l = strlen(s);
		int n = 1,m = 1;
		for(int i=0,j=l-1;i<=j;i++,j--)
		{
			if(s[i] != s[j]) n = 0;
			if((isalpha(s[i]) && str[s[i]-'A']!=s[j])||
				(isdigit(s[i]) && str[s[i]-'1'+26]!=s[j])) m = 0;
		}
		printf("%s%s\n\n",s,res[m*2+n]);
	}
	return 0;
}